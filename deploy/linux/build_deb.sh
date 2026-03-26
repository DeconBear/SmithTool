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

# Run CPack from build directory so .deb output lands in BUILD_DIR.
(cd "${BUILD_DIR}" && cpack --config "CPackConfig.cmake" -G DEB)

shopt -s nullglob
debs=( "${BUILD_DIR}"/*.deb )
if [[ ${#debs[@]} -eq 0 ]]; then
  echo "ERROR: No .deb package generated under ${BUILD_DIR}"
  echo "Hint: search recent package files:"
  find "${PROJECT_DIR}" -maxdepth 3 -type f -name "*.deb" -print || true
  exit 1
fi

cp -f "${debs[@]}" "${OUTPUT_DIR}/"

echo
echo "Done. Debian packages:"
ls -1 "${OUTPUT_DIR}"/*.deb
