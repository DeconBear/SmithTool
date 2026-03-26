# Linux (Debian) Packaging

This directory contains Debian package build assets for SmithTool.

## Prerequisites (Debian/Ubuntu)

```bash
sudo apt update
sudo apt install -y \
  build-essential cmake ninja-build cpack \
  qt6-base-dev qt6-base-dev-tools
```

## Build `.deb`

From project root:

```bash
chmod +x deploy/linux/build_deb.sh
./deploy/linux/build_deb.sh
```

Package output:

- `deploy/linux/dist/*.deb`

## Install package

```bash
sudo apt install ./deploy/linux/dist/smithtool_*.deb
```

## Notes

- Package metadata is defined in `CMakeLists.txt` through CPack variables.
- Runtime dependencies are resolved via `CPACK_DEBIAN_PACKAGE_SHLIBDEPS`.
