#include "../src/core/matching.h"
#include "../src/core/smithmath.h"
#include "../src/core/impedance.h"

#include <cmath>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using SmithTool::Complex;
using SmithTool::ComponentType;
using SmithTool::ConnectionType;
using SmithTool::MatchingCalculator;
using SmithTool::MatchingSolution;
using SmithTool::MatchingTopology;
using SmithTool::ReflectionCoeff;
using SmithTool::SmithMath;

namespace {

constexpr double kTol = 1e-6;
constexpr double kFreqHz = 1e9;
constexpr double kZ0 = 50.0;

bool approx(double a, double b, double tol = kTol)
{
    return std::abs(a - b) <= tol * std::max(1.0, std::max(std::abs(a), std::abs(b)));
}

bool approx(const Complex& a, const Complex& b, double tol = kTol)
{
    return std::abs(a - b) <= tol * std::max(1.0, std::max(std::abs(a), std::abs(b)));
}

double seriesReactance(ComponentType type, double value, double omega)
{
    switch (type) {
        case ComponentType::Inductor:
            return omega * value;
        case ComponentType::Capacitor:
            return -1.0 / (omega * value);
        default:
            return 0.0;
    }
}

double shuntSusceptance(ComponentType type, double value, double omega)
{
    switch (type) {
        case ComponentType::Inductor:
            return -1.0 / (omega * value);
        case ComponentType::Capacitor:
            return omega * value;
        default:
            return 0.0;
    }
}

Complex applyLumpedSolution(const MatchingSolution& sol)
{
    const double omega = 2.0 * SmithMath::PI * sol.frequency;
    Complex z = sol.loadZ;

    for (const auto& elem : sol.elements) {
        if (elem.connection == ConnectionType::Series) {
            if (elem.type == ComponentType::Resistor) {
                z += Complex(elem.value, 0.0);
            } else {
                z += Complex(0.0, seriesReactance(elem.type, elem.value, omega));
            }
            continue;
        }

        Complex y = Complex(1.0, 0.0) / z;
        if (elem.type == ComponentType::Resistor) {
            y += Complex(1.0 / elem.value, 0.0);
        } else {
            y += Complex(0.0, shuntSusceptance(elem.type, elem.value, omega));
        }
        z = Complex(1.0, 0.0) / y;
    }

    return z;
}

Complex lineInputImpedance(const Complex& zLoad, double length, double z0, double frequency)
{
    const double beta = 2.0 * SmithMath::PI / (3e8 / frequency);
    const double t = std::tan(beta * length);
    return z0 * (zLoad + Complex(0.0, z0 * t)) / (Complex(z0, 0.0) + Complex(0.0, t) * zLoad);
}

Complex stubAdmittance(ComponentType type, double length, double z0, double frequency)
{
    const double beta = 2.0 * SmithMath::PI / (3e8 / frequency);
    const double t = std::tan(beta * length);

    if (type == ComponentType::OpenStub) {
        return Complex(0.0, t / z0);
    }

    if (std::abs(t) < 1e-12) {
        return Complex(0.0, 1e12);
    }

    return Complex(0.0, -1.0 / (z0 * t));
}

Complex applySingleStubSolution(const MatchingSolution& sol, double z0)
{
    const auto& line = sol.elements[0];
    const auto& stub = sol.elements[1];

    Complex zAtStub = lineInputImpedance(sol.loadZ, line.value, z0, sol.frequency);
    Complex yTotal = Complex(1.0, 0.0) / zAtStub + stubAdmittance(stub.type, stub.value, z0, sol.frequency);
    return Complex(1.0, 0.0) / yTotal;
}

void require(bool condition, const std::string& message)
{
    if (!condition) {
        std::cerr << "Test failed: " << message << std::endl;
        std::exit(1);
    }
}

void testSmithMathRoundTrip()
{
    const Complex z(100.0, 50.0);
    const Complex gamma = SmithMath::impedanceToGamma(z, kZ0);
    const Complex restored = SmithMath::gammaToImpedance(gamma, kZ0);
    require(approx(z, restored, 1e-9), "impedance/gamma round-trip");
}

void testReturnLossSign()
{
    const ReflectionCoeff gamma(0.5, 0.0, kZ0);
    require(approx(gamma.returnLossDb(), 6.020599913, 1e-6), "return loss should be positive");
}

void testLumpedTopologies()
{
    const std::vector<std::pair<Complex, Complex>> cases = {
        {Complex(50.0, 0.0), Complex(100.0, 50.0)},
        {Complex(50.0, 0.0), Complex(25.0, -30.0)},
        {Complex(75.0, 10.0), Complex(30.0, -20.0)},
        {Complex(25.0, -5.0), Complex(100.0, 30.0)}
    };

    for (const auto& [sourceZ, loadZ] : cases) {
        MatchingCalculator calc;
        calc.setSourceImpedance(sourceZ);
        calc.setLoadImpedance(loadZ);
        calc.setFrequency(kFreqHz);
        calc.setZ0(kZ0);

        const auto lSolutions = calc.calculateLSection();
        require(!lSolutions.empty(), "expected L-section solution");
        for (const auto& sol : lSolutions) {
            require(sol.topology == MatchingTopology::LSection ||
                        sol.topology == MatchingTopology::LSection_Reversed,
                    "unexpected L topology");
            require(approx(applyLumpedSolution(sol), sourceZ), "L-section does not match source impedance");
        }

        const auto piSolutions = calc.calculatePiNetwork();
        require(!piSolutions.empty(), "expected Pi-network solution");
        for (const auto& sol : piSolutions) {
            require(approx(applyLumpedSolution(sol), sourceZ), "Pi-network does not match source impedance");
        }

        const auto tSolutions = calc.calculateTNetwork();
        require(!tSolutions.empty(), "expected T-network solution");
        for (const auto& sol : tSolutions) {
            require(approx(applyLumpedSolution(sol), sourceZ), "T-network does not match source impedance");
        }
    }
}

void testSingleStub()
{
    MatchingCalculator calc;
    calc.setSourceImpedance(Complex(kZ0, 0.0));
    calc.setLoadImpedance(Complex(100.0, 50.0));
    calc.setFrequency(kFreqHz);
    calc.setZ0(kZ0);

    const auto solutions = calc.calculateSingleStub();
    require(!solutions.empty(), "expected single-stub solution");

    for (const auto& sol : solutions) {
        require(sol.elements.size() == 2, "single-stub solution should have line + stub");
        const Complex zin = applySingleStubSolution(sol, kZ0);
        require(approx(zin, Complex(kZ0, 0.0)), "single-stub solution should match Z0");
    }
}

} // namespace

int main()
{
    testSmithMathRoundTrip();
    testReturnLossSign();
    testLumpedTopologies();
    testSingleStub();

    std::cout << "All matching tests passed." << std::endl;
    return 0;
}
