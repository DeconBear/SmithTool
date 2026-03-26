# Open-Source Distribution Compliance Checklist

Use this checklist before releasing binaries.

## 1) Project License Files

- [ ] Include this repository `LICENSE` file in release packages.
- [ ] Keep copyright headers/notices intact.

## 2) Qt License Compliance (when using Qt open-source edition)

- [ ] Confirm which Qt modules are used in the final build.
- [ ] Confirm each used module license from:
      https://doc.qt.io/qt-6/licenses-used-in-qt.html
- [ ] Bundle third-party notice file (`THIRD_PARTY_NOTICES.md`).
- [ ] Bundle applicable Qt license texts with binaries.
- [ ] If Qt itself was modified, provide patch/source details.

For LGPL-based distribution:

- [ ] Prefer dynamic linking for Qt libraries.
- [ ] Provide users a practical way to replace/relink LGPL libraries.
- [ ] Preserve LGPL-required reverse-engineering rights for debugging
      modifications.

## 3) Source/Binary Release Artifacts

- [ ] Publish source code corresponding to the release tag.
- [ ] Publish build instructions and dependencies.
- [ ] Keep binary package and source tag aligned (same commit hash/version).

## 4) Internal Release Record

- [ ] Record Qt version, compiler version, and build flags.
- [ ] Record links to license evidence used for this release.
- [ ] Save generated SBOM/dependency manifest (if your pipeline supports it).

## Notes

Official Qt licensing references:

- https://doc.qt.io/qt-6/licensing.html
- https://www.qt.io/development/open-source-lgpl-obligations
- https://www.qt.io/faq/qt-open-source-licensing

This checklist is not legal advice.
