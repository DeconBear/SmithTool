# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

SmithTool is an interactive Smith Chart desktop application for RF impedance matching and matching-network design. C++17, Qt 6 Widgets, CMake >= 3.16, Ninja generator.

## Build Commands

**Windows (MSYS2 MinGW64):**
```powershell
cmake -S . -B build-release -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=E:/msys2/mingw64
cmake --build build-release -j4
```

**Linux:**
```bash
cmake -S . -B build-linux -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build-linux -j$(nproc)
```

**Optional CMake flags:**
- `-DBUILD_TESTS=ON` — enable unit tests (Qt6::Test, currently stubbed out)
- `-DBUILD_SHARED_LIBS=ON` — build core/data/ui as a shared library for integration

## Packaging

- **Windows installer:** `deploy\windows\build.bat` then `iscc deploy\windows\smithtool.iss`
- **Debian package:** `deploy/linux/build_deb.sh`
- CI: `.github/workflows/package.yml` builds both on push to main and version tags

## Architecture

Three modules under `src/`, all in the `SmithTool` namespace:

### `src/core/` — RF computation (minimal Qt dependency)
- `smithmath` — Smith Chart math: impedance/admittance ↔ reflection coefficient (Gamma), screen coordinate transforms, constant-R circles, constant-X arcs, VSWR, return loss. `SmithMath` is a static utility class; `Complex = std::complex<double>` is the project-wide type alias.
- `impedance` — impedance/admittance data structures
- `component` — R/L/C value calculations from impedance deltas
- `trace` — trace/segment data for drawing impedance trajectories on the chart
- `matching` — matching network algorithms: L-section, Pi, T, single stub, quarter-wave transformer. `MatchingCalculator` computes solutions; `MatchingSolution`/`MatchingElement` describe results.

### `src/data/` — file I/O
- `touchstone` — Touchstone `.s1p`/`.s2p` file parser
- `sparamdata` — S-parameter data container
- `spiceexporter` — SPICE netlist export (LTspice/Ngspice formats)

### `src/ui/` — Qt Widgets
- `mainwindow` — top-level window, menu/toolbar/dock wiring, language switching, signal routing
- `smithchartwidget` — the central interactive Smith Chart canvas (mouse interaction, rendering)
- `impedanceinputpanel` — source/load impedance entry (rectangular + polar)
- `elementtoolbar` — buttons for adding series/shunt R/L/C elements
- `componentpanel` — dock panel displaying calculated component values
- `circuitview` — schematic rendering of the matching network (source → load)
- `matchingwizard` — dialog for automated matching network design
- `componenteditdialog` — dialog for editing individual component values

### Entry point
`src/main.cpp` — creates QApplication, loads language preference from QSettings, installs QTranslator, shows MainWindow.

## Conventions

- Namespace: `SmithTool` everywhere
- Header guards: `SMITHTOOL_<FILENAME>_H`
- Compiler warnings: `-Wall -Wextra -Wpedantic` (GCC/Clang), `/W4` (MSVC)
- i18n: Qt `.ts`/`.qm` translation files in `resources/translations/`; language switch at runtime via menu, preference stored in QSettings
- Styles: `resources/styles/dark.qss` and `light.qss`, bundled via `resources/resources.qrc`
- The `Complex` type alias (`std::complex<double>`) is defined in `smithmath.h` and re-declared in other core headers that need it
