# Third-Party Notices

This project uses third-party software.

## Qt 6

- Project: Qt
- Website: https://www.qt.io/
- Documentation: https://doc.qt.io/qt-6/
- License model: Open source (LGPLv3/GPLv3 for many modules) or commercial

This repository currently links these Qt modules (see `CMakeLists.txt`):

- `Qt6::Core`
- `Qt6::Gui`
- `Qt6::Widgets`

## Distribution and Compliance Notes

If you distribute binaries built against open-source Qt modules, you must
follow the applicable Qt license obligations (for example LGPLv3/GPLv3).
Typical requirements include:

- Preserve copyright and license notices.
- Provide the relevant license texts with your distribution.
- Clearly state any modifications made to Qt itself.
- For LGPL-based distribution, allow end users to relink/replace LGPL libraries
  (dynamic linking is the common approach).
- Keep reverse-engineering rights required by LGPL for debugging modifications.

Official references:

- https://doc.qt.io/qt-6/licensing.html
- https://www.qt.io/development/open-source-lgpl-obligations
- https://www.qt.io/faq/qt-open-source-licensing
- https://doc.qt.io/qt-6/licenses-used-in-qt.html

## Disclaimer

This file is an engineering checklist aid, not legal advice.
