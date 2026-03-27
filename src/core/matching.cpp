/**
 * @file matching.cpp
 * @brief Impedance matching network design algorithms implementation
 */

#include "matching.h"
#include "smithmath.h"
#include <algorithm>
#include <cmath>

namespace SmithTool {

namespace {

constexpr double kEpsilon = 1e-12;
constexpr double kValidationRelTol = 1e-6;

enum class LOrder {
    SeriesThenShunt, // load -> series -> shunt -> source
    ShuntThenSeries  // load -> shunt -> series -> source
};

struct LSolverResult {
    LOrder order = LOrder::SeriesThenShunt;
    double xSeries = 0.0; // ohm
    double bShunt = 0.0;  // siemens
};

bool nearlyZero(double value, double eps = kEpsilon)
{
    return std::abs(value) <= eps;
}

bool nearlyEqual(double a, double b, double relTol = 1e-9, double absTol = 1e-12)
{
    return std::abs(a - b) <= std::max(absTol, relTol * std::max(std::abs(a), std::abs(b)));
}

QString formatValue(double value, const QString& unit)
{
    const double absVal = std::abs(value);
    QString prefix;
    double scaled = value;

    if (absVal >= 1.0) {
        prefix = "";
    } else if (absVal >= 1e-3) {
        scaled = value * 1e3;
        prefix = "m";
    } else if (absVal >= 1e-6) {
        scaled = value * 1e6;
        prefix = "u";
    } else if (absVal >= 1e-9) {
        scaled = value * 1e9;
        prefix = "n";
    } else if (absVal >= 1e-12) {
        scaled = value * 1e12;
        prefix = "p";
    } else {
        scaled = value * 1e15;
        prefix = "f";
    }

    return QString("%1 %2%3").arg(scaled, 0, 'f', 2).arg(prefix).arg(unit);
}

double elementSeriesReactance(const MatchingElement& elem, double omega)
{
    switch (elem.type) {
        case ComponentType::Inductor:
            return omega * elem.value;
        case ComponentType::Capacitor:
            if (elem.value <= kEpsilon) {
                return 0.0;
            }
            return -1.0 / (omega * elem.value);
        default:
            return 0.0;
    }
}

double elementShuntSusceptance(const MatchingElement& elem, double omega)
{
    switch (elem.type) {
        case ComponentType::Inductor:
            if (elem.value <= kEpsilon) {
                return 0.0;
            }
            return -1.0 / (omega * elem.value);
        case ComponentType::Capacitor:
            return omega * elem.value;
        default:
            return 0.0;
    }
}

bool appendSeriesReactiveElement(std::vector<MatchingElement>& elements, double xSeries, double freqHz)
{
    if (nearlyZero(xSeries)) {
        return false;
    }

    MatchingElement elem;
    elem.connection = ConnectionType::Series;
    if (xSeries > 0.0) {
        elem.type = ComponentType::Inductor;
        elem.value = MatchingCalculator::reactanceToInductance(xSeries, freqHz);
    } else {
        elem.type = ComponentType::Capacitor;
        elem.value = MatchingCalculator::reactanceToCapacitance(xSeries, freqHz);
    }

    if (!std::isfinite(elem.value) || elem.value <= 0.0) {
        return false;
    }

    elements.push_back(elem);
    return true;
}

bool appendShuntReactiveElement(std::vector<MatchingElement>& elements, double bShunt, double freqHz)
{
    if (nearlyZero(bShunt)) {
        return false;
    }

    MatchingElement elem;
    elem.connection = ConnectionType::Shunt;
    if (bShunt > 0.0) {
        elem.type = ComponentType::Capacitor;
        elem.value = MatchingCalculator::susceptanceToCapacitance(bShunt, freqHz);
    } else {
        elem.type = ComponentType::Inductor;
        elem.value = MatchingCalculator::susceptanceToInductance(bShunt, freqHz);
    }

    if (!std::isfinite(elem.value) || elem.value <= 0.0) {
        return false;
    }

    elements.push_back(elem);
    return true;
}

std::vector<LSolverResult> solveReactiveLNetwork(const Complex& zLoad, const Complex& zTarget)
{
    std::vector<LSolverResult> raw;

    const double rs = zTarget.real();
    const double xs = zTarget.imag();
    const double rl = zLoad.real();
    const double xl = zLoad.imag();

    if (rs <= 0.0 || rl <= 0.0) {
        return raw;
    }

    // Topology A: load -> series(X) -> shunt(B) -> source
    // Equation: 1/Zs = 1/(Zl + jX) + jB
    const Complex ys = Complex(1.0, 0.0) / zTarget;
    const double gs = ys.real();
    const double bs = ys.imag();
    if (gs > kEpsilon) {
        double term = rl / gs - rl * rl;
        if (term >= -kEpsilon) {
            term = std::max(0.0, term);
            const double root = std::sqrt(term);
            for (const double sign : {1.0, -1.0}) {
                const double u = sign * root;     // u = Xl + X
                const double xSeries = u - xl;    // X = u - Xl
                const Complex z1(rl, u);          // Zl + jX
                const Complex y1 = Complex(1.0, 0.0) / z1;
                const double bShunt = bs - y1.imag();
                raw.push_back({LOrder::SeriesThenShunt, xSeries, bShunt});
                if (nearlyZero(root)) {
                    break;
                }
            }
        }
    }

    // Topology B: load -> shunt(B) -> series(X) -> source
    // Equation: Zs = 1/(1/Zl + jB) + jX
    const Complex yl = Complex(1.0, 0.0) / zLoad;
    const double g = yl.real();
    const double b0 = yl.imag();
    if (g > kEpsilon && rs > kEpsilon) {
        double term = g / rs - g * g;
        if (term >= -kEpsilon) {
            term = std::max(0.0, term);
            const double root = std::sqrt(term);
            for (const double sign : {1.0, -1.0}) {
                const double t = sign * root;     // t = b0 + B
                const double bShunt = t - b0;     // B = t - b0
                const Complex z1 = Complex(1.0, 0.0) / Complex(g, t);
                const double xSeries = xs - z1.imag();
                raw.push_back({LOrder::ShuntThenSeries, xSeries, bShunt});
                if (nearlyZero(root)) {
                    break;
                }
            }
        }
    }

    // Deduplicate numerically equivalent roots.
    std::vector<LSolverResult> deduped;
    for (const auto& candidate : raw) {
        bool duplicate = false;
        for (const auto& existing : deduped) {
            if (candidate.order == existing.order &&
                nearlyEqual(candidate.xSeries, existing.xSeries) &&
                nearlyEqual(candidate.bShunt, existing.bShunt)) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            deduped.push_back(candidate);
        }
    }

    return deduped;
}

bool areEquivalentElements(const MatchingElement& a, const MatchingElement& b)
{
    if (a.type != b.type || a.connection != b.connection) {
        return false;
    }
    return nearlyEqual(a.value, b.value, 1e-8, 1e-15);
}

bool containsEquivalentSolution(const std::vector<MatchingSolution>& existing,
                                const MatchingSolution& candidate)
{
    for (const auto& sol : existing) {
        if (sol.topology != candidate.topology || sol.elements.size() != candidate.elements.size()) {
            continue;
        }

        bool same = true;
        for (size_t i = 0; i < sol.elements.size(); ++i) {
            if (!areEquivalentElements(sol.elements[i], candidate.elements[i])) {
                same = false;
                break;
            }
        }

        if (same) {
            return true;
        }
    }
    return false;
}

bool validateSolutionImpedance(const MatchingSolution& sol,
                               const Complex& loadZ,
                               const Complex& expectedSourceZ)
{
    if (sol.frequency <= 0.0) {
        return false;
    }

    const double omega = 2.0 * SmithMath::PI * sol.frequency;
    if (!std::isfinite(omega) || omega <= 0.0) {
        return false;
    }

    Complex z = loadZ;

    for (const auto& elem : sol.elements) {
        if (elem.connection == ConnectionType::Series) {
            if (elem.type == ComponentType::Resistor) {
                z += Complex(elem.value, 0.0);
            } else {
                z += Complex(0.0, elementSeriesReactance(elem, omega));
            }
        } else {
            if (std::abs(z) < kEpsilon) {
                return false;
            }
            Complex y = Complex(1.0, 0.0) / z;
            if (elem.type == ComponentType::Resistor) {
                if (elem.value <= 0.0) {
                    return false;
                }
                y += Complex(1.0 / elem.value, 0.0);
            } else {
                y += Complex(0.0, elementShuntSusceptance(elem, omega));
            }

            if (std::abs(y) < kEpsilon) {
                return false;
            }
            z = Complex(1.0, 0.0) / y;
        }
    }

    const double scale = std::max(1.0, std::abs(expectedSourceZ));
    const double err = std::abs(z - expectedSourceZ);
    return err <= kValidationRelTol * scale;
}

} // namespace

// MatchingElement methods
QString MatchingElement::valueString() const
{
    const double absVal = std::abs(value);
    QString prefix;
    double scaled = value;

    switch (type) {
        case ComponentType::Resistor:
            if (absVal >= 1e6) {
                scaled = value / 1e6;
                prefix = "M";
            } else if (absVal >= 1e3) {
                scaled = value / 1e3;
                prefix = "k";
            } else {
                prefix = "";
            }
            return QString("%1 %2Ohm").arg(scaled, 0, 'f', 2).arg(prefix);

        case ComponentType::Inductor:
            if (absVal >= 1e-3) {
                scaled = value * 1e3;
                prefix = "m";
            } else if (absVal >= 1e-6) {
                scaled = value * 1e6;
                prefix = "u";
            } else if (absVal >= 1e-9) {
                scaled = value * 1e9;
                prefix = "n";
            } else {
                scaled = value * 1e12;
                prefix = "p";
            }
            return QString("%1 %2H").arg(scaled, 0, 'f', 2).arg(prefix);

        case ComponentType::Capacitor:
            if (absVal >= 1e-6) {
                scaled = value * 1e6;
                prefix = "u";
            } else if (absVal >= 1e-9) {
                scaled = value * 1e9;
                prefix = "n";
            } else if (absVal >= 1e-12) {
                scaled = value * 1e12;
                prefix = "p";
            } else {
                scaled = value * 1e15;
                prefix = "f";
            }
            return QString("%1 %2F").arg(scaled, 0, 'f', 2).arg(prefix);

        default:
            return QString::number(value);
    }
}

// MatchingSolution methods
double MatchingSolution::networkQ() const
{
    const double rs = sourceZ.real();
    const double rl = loadZ.real();
    if (rs <= 0.0 || rl <= 0.0) {
        return 0.0;
    }

    const double ratio = std::max(rs, rl) / std::min(rs, rl);
    return std::sqrt(std::max(0.0, ratio - 1.0));
}

QString MatchingSolution::toNetlist() const
{
    QString netlist;
    int nodeNum = 1;

    for (const auto& elem : elements) {
        QString compType;
        switch (elem.type) {
            case ComponentType::Resistor:
                compType = "R";
                break;
            case ComponentType::Inductor:
                compType = "L";
                break;
            case ComponentType::Capacitor:
                compType = "C";
                break;
            default:
                continue;
        }

        if (elem.connection == ConnectionType::Series) {
            netlist += QString("%1%2 %3 %4 %5\n")
                           .arg(compType)
                           .arg(nodeNum)
                           .arg(nodeNum)
                           .arg(nodeNum + 1)
                           .arg(elem.value);
            nodeNum++;
        } else {
            netlist += QString("%1%2 %3 0 %4\n")
                           .arg(compType)
                           .arg(nodeNum)
                           .arg(nodeNum)
                           .arg(elem.value);
        }
    }
    return netlist;
}

QString MatchingSolution::toDescription() const
{
    if (!valid) {
        return "Invalid solution";
    }

    QString desc;
    switch (topology) {
        case MatchingTopology::LSection:
            desc = "L-Section: ";
            break;
        case MatchingTopology::LSection_Reversed:
            desc = "L-Section (Reversed): ";
            break;
        case MatchingTopology::PiNetwork:
            desc = "Pi-Network: ";
            break;
        case MatchingTopology::TNetwork:
            desc = "T-Network: ";
            break;
        default:
            desc = "Matching: ";
            break;
    }

    for (size_t i = 0; i < elements.size(); ++i) {
        if (i > 0) {
            desc += " -> ";
        }
        const QString connStr = (elements[i].connection == ConnectionType::Series) ? "Series" : "Shunt";
        desc += QString("%1 %2").arg(connStr).arg(elements[i].valueString());
    }

    return desc;
}

// MatchingCalculator methods
MatchingCalculator::MatchingCalculator()
    : m_sourceZ(50.0, 0.0)
    , m_loadZ(50.0, 0.0)
    , m_frequency(1e9)
    , m_z0(50.0)
{
}

void MatchingCalculator::setSourceImpedance(const Complex& zs)
{
    m_sourceZ = zs;
}

void MatchingCalculator::setLoadImpedance(const Complex& zl)
{
    m_loadZ = zl;
}

void MatchingCalculator::setFrequency(double freq_hz)
{
    m_frequency = freq_hz;
}

void MatchingCalculator::setZ0(double z0)
{
    m_z0 = z0;
}

double MatchingCalculator::reactanceToInductance(double x, double freq)
{
    if (freq <= 0.0) {
        return 0.0;
    }
    return x / (2.0 * SmithMath::PI * freq);
}

double MatchingCalculator::reactanceToCapacitance(double x, double freq)
{
    if (freq <= 0.0 || nearlyZero(x)) {
        return 0.0;
    }
    return -1.0 / (2.0 * SmithMath::PI * freq * x);
}

double MatchingCalculator::susceptanceToCapacitance(double b, double freq)
{
    if (freq <= 0.0) {
        return 0.0;
    }
    return b / (2.0 * SmithMath::PI * freq);
}

double MatchingCalculator::susceptanceToInductance(double b, double freq)
{
    if (freq <= 0.0 || nearlyZero(b)) {
        return 0.0;
    }
    return -1.0 / (2.0 * SmithMath::PI * freq * b);
}

std::vector<MatchingSolution> MatchingCalculator::calculateLSection() const
{
    std::vector<MatchingSolution> solutions;

    if (m_frequency <= 0.0 || m_sourceZ.real() <= 0.0 || m_loadZ.real() <= 0.0) {
        return solutions;
    }

    const auto lCandidates = solveReactiveLNetwork(m_loadZ, m_sourceZ);

    for (const auto& candidate : lCandidates) {
        MatchingSolution sol;
        sol.topology = (candidate.order == LOrder::SeriesThenShunt)
                           ? MatchingTopology::LSection
                           : MatchingTopology::LSection_Reversed;
        sol.frequency = m_frequency;
        sol.sourceZ = m_sourceZ;
        sol.loadZ = m_loadZ;
        sol.valid = true;

        if (candidate.order == LOrder::SeriesThenShunt) {
            appendSeriesReactiveElement(sol.elements, candidate.xSeries, m_frequency);
            appendShuntReactiveElement(sol.elements, candidate.bShunt, m_frequency);
        } else {
            appendShuntReactiveElement(sol.elements, candidate.bShunt, m_frequency);
            appendSeriesReactiveElement(sol.elements, candidate.xSeries, m_frequency);
        }

        if (sol.elements.empty()) {
            continue;
        }

        if (!validateSolutionImpedance(sol, m_loadZ, m_sourceZ)) {
            continue;
        }

        if (!containsEquivalentSolution(solutions, sol)) {
            solutions.push_back(sol);
        }
    }

    return solutions;
}

MatchingSolution MatchingCalculator::createLSectionSolution(double x_series,
                                                            double b_shunt,
                                                            bool shuntFirst) const
{
    MatchingSolution sol;
    sol.topology = shuntFirst ? MatchingTopology::LSection_Reversed : MatchingTopology::LSection;
    sol.frequency = m_frequency;
    sol.sourceZ = m_sourceZ;
    sol.loadZ = m_loadZ;
    sol.valid = true;

    if (shuntFirst) {
        appendShuntReactiveElement(sol.elements, b_shunt, m_frequency);
        appendSeriesReactiveElement(sol.elements, x_series, m_frequency);
    } else {
        appendSeriesReactiveElement(sol.elements, x_series, m_frequency);
        appendShuntReactiveElement(sol.elements, b_shunt, m_frequency);
    }

    return sol;
}

std::vector<MatchingSolution> MatchingCalculator::calculatePiNetwork(double targetQ) const
{
    std::vector<MatchingSolution> solutions;

    const double rs = m_sourceZ.real();
    const double rl = m_loadZ.real();
    if (m_frequency <= 0.0 || rs <= 0.0 || rl <= 0.0 || targetQ <= 0.0) {
        return solutions;
    }

    const double rVirt = std::min(rs, rl) / (1.0 + targetQ * targetQ);
    if (rVirt <= 0.0) {
        return solutions;
    }

    const Complex zVirt(rVirt, 0.0);
    const auto loadToVirt = solveReactiveLNetwork(m_loadZ, zVirt);
    const auto virtToSource = solveReactiveLNetwork(zVirt, m_sourceZ);

    std::vector<LSolverResult> leftCandidates;
    std::vector<LSolverResult> rightCandidates;

    for (const auto& item : loadToVirt) {
        if (item.order == LOrder::ShuntThenSeries) {
            leftCandidates.push_back(item);
        }
    }
    for (const auto& item : virtToSource) {
        if (item.order == LOrder::SeriesThenShunt) {
            rightCandidates.push_back(item);
        }
    }

    for (const auto& left : leftCandidates) {
        for (const auto& right : rightCandidates) {
            MatchingSolution sol;
            sol.topology = MatchingTopology::PiNetwork;
            sol.frequency = m_frequency;
            sol.sourceZ = m_sourceZ;
            sol.loadZ = m_loadZ;
            sol.valid = true;

            const double seriesTotal = left.xSeries + right.xSeries;
            appendShuntReactiveElement(sol.elements, left.bShunt, m_frequency);      // load side shunt
            appendSeriesReactiveElement(sol.elements, seriesTotal, m_frequency);      // middle series
            appendShuntReactiveElement(sol.elements, right.bShunt, m_frequency);      // source side shunt

            if (sol.elements.empty()) {
                continue;
            }

            if (!validateSolutionImpedance(sol, m_loadZ, m_sourceZ)) {
                continue;
            }

            if (!containsEquivalentSolution(solutions, sol)) {
                solutions.push_back(sol);
            }
        }
    }

    return solutions;
}

std::vector<MatchingSolution> MatchingCalculator::calculateTNetwork(double targetQ) const
{
    std::vector<MatchingSolution> solutions;

    const double rs = m_sourceZ.real();
    const double rl = m_loadZ.real();
    if (m_frequency <= 0.0 || rs <= 0.0 || rl <= 0.0 || targetQ <= 0.0) {
        return solutions;
    }

    const double rVirt = std::max(rs, rl) * (1.0 + targetQ * targetQ);
    if (rVirt <= 0.0) {
        return solutions;
    }

    const Complex zVirt(rVirt, 0.0);
    const auto loadToVirt = solveReactiveLNetwork(m_loadZ, zVirt);
    const auto virtToSource = solveReactiveLNetwork(zVirt, m_sourceZ);

    std::vector<LSolverResult> leftCandidates;
    std::vector<LSolverResult> rightCandidates;

    for (const auto& item : loadToVirt) {
        if (item.order == LOrder::SeriesThenShunt) {
            leftCandidates.push_back(item);
        }
    }
    for (const auto& item : virtToSource) {
        if (item.order == LOrder::ShuntThenSeries) {
            rightCandidates.push_back(item);
        }
    }

    for (const auto& left : leftCandidates) {
        for (const auto& right : rightCandidates) {
            MatchingSolution sol;
            sol.topology = MatchingTopology::TNetwork;
            sol.frequency = m_frequency;
            sol.sourceZ = m_sourceZ;
            sol.loadZ = m_loadZ;
            sol.valid = true;

            const double shuntTotal = left.bShunt + right.bShunt;
            appendSeriesReactiveElement(sol.elements, left.xSeries, m_frequency);     // load side series
            appendShuntReactiveElement(sol.elements, shuntTotal, m_frequency);        // middle shunt
            appendSeriesReactiveElement(sol.elements, right.xSeries, m_frequency);    // source side series

            if (sol.elements.empty()) {
                continue;
            }

            if (!validateSolutionImpedance(sol, m_loadZ, m_sourceZ)) {
                continue;
            }

            if (!containsEquivalentSolution(solutions, sol)) {
                solutions.push_back(sol);
            }
        }
    }

    return solutions;
}

std::vector<MatchingSolution> MatchingCalculator::calculateSingleStub() const
{
    std::vector<MatchingSolution> solutions;

    // This transmission-line matcher targets the system impedance Z0.
    Complex yL = Complex(1.0, 0.0) / (m_loadZ / m_z0);
    const double g = yL.real();
    const double b = yL.imag();

    if (std::abs(g - 1.0) < 1e-10 && std::abs(b) < 1e-10) {
        return solutions;
    }

    if (g <= 0.0 || m_frequency <= 0.0 || m_z0 <= 0.0) {
        return solutions;
    }

    const double lambda = 3e8 / m_frequency;
    const double beta = 2.0 * SmithMath::PI / lambda;

    // Solve Re{y(d)} = 1 for t = tan(beta * d).
    const double qa = b * b + g * g - g;
    const double qb = -2.0 * b;
    const double qc = 1.0 - g;

    std::vector<double> tanSolutions;
    if (std::abs(qa) < kEpsilon) {
        if (std::abs(qb) < kEpsilon) {
            return solutions;
        }
        tanSolutions.push_back(-qc / qb);
    } else {
        double discriminant = qb * qb - 4.0 * qa * qc;
        if (discriminant < -kEpsilon) {
            return solutions;
        }
        discriminant = std::max(0.0, discriminant);
        const double root = std::sqrt(discriminant);
        tanSolutions.push_back((-qb + root) / (2.0 * qa));
        if (!nearlyZero(root)) {
            tanSolutions.push_back((-qb - root) / (2.0 * qa));
        }
    }

    for (const double t : tanSolutions) {
        double d = std::atan(t) / beta;
        if (d < 0.0) {
            d += lambda / 2.0;
        }

        const Complex numerator = yL + Complex(0.0, t);
        const Complex denominator = Complex(1.0, 0.0) + Complex(0.0, t) * yL;
        const Complex yIn = numerator / denominator;
        const double bStub = -yIn.imag();

        // Open stub
        {
            MatchingSolution sol;
            sol.topology = MatchingTopology::SingleStubOpen;
            sol.frequency = m_frequency;
            sol.sourceZ = m_sourceZ;
            sol.loadZ = m_loadZ;
            sol.valid = true;

            double lOpen = std::atan(bStub) / beta;
            if (lOpen < 0.0) {
                lOpen += lambda / 2.0;
            }

            MatchingElement line;
            line.type = ComponentType::TransmissionLine;
            line.connection = ConnectionType::Series;
            line.value = d;
            line.label = QString("TL: %1 mm").arg(d * 1000.0, 0, 'f', 2);
            sol.elements.push_back(line);

            MatchingElement stub;
            stub.type = ComponentType::OpenStub;
            stub.connection = ConnectionType::Shunt;
            stub.value = lOpen;
            stub.label = QString("Open Stub: %1 mm").arg(lOpen * 1000.0, 0, 'f', 2);
            sol.elements.push_back(stub);

            sol.description = QString("Open stub at d=%1mm, l=%2mm")
                                  .arg(d * 1000.0, 0, 'f', 2)
                                  .arg(lOpen * 1000.0, 0, 'f', 2);

            solutions.push_back(sol);
        }

        // Short stub
        {
            MatchingSolution sol;
            sol.topology = MatchingTopology::SingleStubShort;
            sol.frequency = m_frequency;
            sol.sourceZ = m_sourceZ;
            sol.loadZ = m_loadZ;
            sol.valid = true;

            double lShort = 0.0;
            if (nearlyZero(bStub)) {
                lShort = lambda / 4.0;
            } else {
                lShort = std::atan(-1.0 / bStub) / beta;
                if (lShort < 0.0) {
                    lShort += lambda / 2.0;
                }
            }

            MatchingElement line;
            line.type = ComponentType::TransmissionLine;
            line.connection = ConnectionType::Series;
            line.value = d;
            line.label = QString("TL: %1 mm").arg(d * 1000.0, 0, 'f', 2);
            sol.elements.push_back(line);

            MatchingElement stub;
            stub.type = ComponentType::ShortStub;
            stub.connection = ConnectionType::Shunt;
            stub.value = lShort;
            stub.label = QString("Short Stub: %1 mm").arg(lShort * 1000.0, 0, 'f', 2);
            sol.elements.push_back(stub);

            sol.description = QString("Short stub at d=%1mm, l=%2mm")
                                  .arg(d * 1000.0, 0, 'f', 2)
                                  .arg(lShort * 1000.0, 0, 'f', 2);

            solutions.push_back(sol);
        }
    }

    return solutions;
}

std::vector<MatchingSolution> MatchingCalculator::calculateQuarterWave() const
{
    std::vector<MatchingSolution> solutions;

    const double rl = m_loadZ.real();
    const double xl = m_loadZ.imag();
    const double rs = m_sourceZ.real();

    if (rl <= 0.0 || rs <= 0.0) {
        return solutions;
    }

    if (std::abs(xl) < 1e-10) {
        const double zQw = std::sqrt(rs * rl);
        const double lambda = 3e8 / m_frequency;
        const double length = lambda / 4.0;

        MatchingSolution sol;
        sol.topology = MatchingTopology::QuarterWave;
        sol.frequency = m_frequency;
        sol.sourceZ = m_sourceZ;
        sol.loadZ = m_loadZ;
        sol.valid = true;

        MatchingElement elem;
        elem.type = ComponentType::TransmissionLine;
        elem.connection = ConnectionType::Series;
        elem.value = zQw; // characteristic impedance
        elem.label = QString("Lambda/4 TL: Z0=%1 Ohm, L=%2 mm")
                         .arg(zQw, 0, 'f', 1)
                         .arg(length * 1000.0, 0, 'f', 2);
        sol.elements.push_back(elem);

        sol.description = QString("Quarter-wave transformer Z0=%1 Ohm").arg(zQw, 0, 'f', 1);
        solutions.push_back(sol);
        return solutions;
    }

    // For reactive load, first cancel Xl with a series reactance, then apply lambda/4 transform.
    const double xCancel = -xl;
    const double zQw = std::sqrt(rs * rl);

    MatchingSolution sol;
    sol.topology = MatchingTopology::QuarterWave;
    sol.frequency = m_frequency;
    sol.sourceZ = m_sourceZ;
    sol.loadZ = m_loadZ;
    sol.valid = true;

    MatchingElement cancelElem;
    cancelElem.connection = ConnectionType::Series;
    if (xCancel > 0.0) {
        cancelElem.type = ComponentType::Inductor;
        cancelElem.value = reactanceToInductance(xCancel, m_frequency);
        cancelElem.label = QString("L: %1").arg(formatValue(cancelElem.value, "H"));
    } else {
        cancelElem.type = ComponentType::Capacitor;
        cancelElem.value = reactanceToCapacitance(xCancel, m_frequency);
        cancelElem.label = QString("C: %1").arg(formatValue(cancelElem.value, "F"));
    }
    if (std::isfinite(cancelElem.value) && cancelElem.value > 0.0) {
        sol.elements.push_back(cancelElem);
    }

    MatchingElement tlElem;
    tlElem.type = ComponentType::TransmissionLine;
    tlElem.connection = ConnectionType::Series;
    tlElem.value = zQw;
    tlElem.label = QString("Lambda/4 TL: Z0=%1 Ohm").arg(zQw, 0, 'f', 1);
    sol.elements.push_back(tlElem);

    sol.description = QString("Quarter-wave transformer with reactance cancellation");
    solutions.push_back(sol);

    return solutions;
}

std::vector<MatchingSolution> MatchingCalculator::calculateAll() const
{
    std::vector<MatchingSolution> all;

    const auto lSec = calculateLSection();
    all.insert(all.end(), lSec.begin(), lSec.end());

    const auto pi = calculatePiNetwork();
    all.insert(all.end(), pi.begin(), pi.end());

    const auto t = calculateTNetwork();
    all.insert(all.end(), t.begin(), t.end());

    const auto stub = calculateSingleStub();
    all.insert(all.end(), stub.begin(), stub.end());

    const auto quarterWave = calculateQuarterWave();
    all.insert(all.end(), quarterWave.begin(), quarterWave.end());

    return all;
}

} // namespace SmithTool
