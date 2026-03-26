# SmithTool

[English](README.md) | [简体中文](README-zh.md)

SmithTool is an interactive Smith Chart desktop application for RF impedance matching and matching-network design, built with **C++17 + Qt 6 Widgets**.

## Features

- Interactive Smith chart visualization
- Source/load impedance editing (rectangular and polar)
- Matching element design (series/shunt R/L/C)
- Matching wizard (L/Pi/T and additional topologies)
- Touchstone file import (`.s1p`, `.s2p`)
- SPICE netlist export
- UI language selection: **English / Simplified Chinese**

## Requirements

- CMake >= 3.16
- C++17 compiler
- Qt 6 (`Core`, `Gui`, `Widgets`)

### Windows (recommended: MSYS2 MinGW64)

Install toolchain and Qt6 in MSYS2:

```powershell
pacman -S --needed mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake mingw-w64-x86_64-ninja mingw-w64-x86_64-qt6-base mingw-w64-x86_64-qt6-tools
```

### Debian / Ubuntu

```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake ninja-build qt6-base-dev qt6-base-dev-tools qt6-tools-dev-tools
```

## Build

### Windows

```powershell
cmake -S SmithTool -B SmithTool/build-msys -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=E:/msys2/mingw64
cmake --build SmithTool/build-msys -j4
```

### Debian / Linux

```bash
cmake -S SmithTool -B SmithTool/build-linux -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build SmithTool/build-linux -j$(nproc)
```

## Run

- Windows executable (example): `SmithTool/build-msys/SmithTool.exe`
- Switch language in menu: `Language -> English / Simplified Chinese`
- Language preference is saved and applied after restart.

## Packaging

- Windows installer (`.exe`): Inno Setup pipeline
- Debian package (`.deb`): CPack/DEB pipeline

See details:

- [PACKAGING.md](PACKAGING.md)
- [deploy/linux/README.md](deploy/linux/README.md)
- [deploy/windows/build.bat](deploy/windows/build.bat)

## Open-Source Compliance (Qt)

This project is intended for open-source distribution with Qt6 dynamic linking.
Before release, complete the checklist and include notices/licenses in artifacts:

- [COMPLIANCE_CHECKLIST.md](COMPLIANCE_CHECKLIST.md)
- [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md)
- [LICENSE](LICENSE)

## License

MIT License. See [LICENSE](LICENSE).
