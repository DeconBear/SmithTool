#!/usr/bin/env bash
set -euo pipefail

# SmithTool Debian package build script
# Usage:
#   ./deploy/linux/build_deb.sh

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(cd "${SCRIPT_DIR}/../.." && pwd)"
BUILD_DIR="${PROJECT_DIR}/build-debian-release"
OUTPUT_DIR="${SCRIPT_DIR}/dist"

BUILD_TYPE="${BUILD_TYPE:-Release}"
INSTALL_PREFIX="${INSTALL_PREFIX:-/usr}"
GENERATOR="${GENERATOR:-Ninja}"

echo "==================================="
echo "SmithTool Debian Package Builder"
echo "==================================="
echo "Project: ${PROJECT_DIR}"
echo "Build:   ${BUILD_DIR}"
echo "Output:  ${OUTPUT_DIR}"
echo

mkdir -p "${BUILD_DIR}" "${OUTPUT_DIR}"

cmake -S "${PROJECT_DIR}" -B "${BUILD_DIR}" \
  -G "${GENERATOR}" \
  -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
  -DCMAKE_INSTALL_PREFIX="${INSTALL_PREFIX}"

cmake --build "${BUILD_DIR}" --config "${BUILD_TYPE}" -j"$(nproc)"

cpack --config "${BUILD_DIR}/CPackConfig.cmake" -G DEB

find "${BUILD_DIR}" -maxdepth 1 -type f -name "*.deb" -exec cp -f {} "${OUTPUT_DIR}/" \;

echo
echo "Done. Debian packages:"
ls -1 "${OUTPUT_DIR}"/*.deb
