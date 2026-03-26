# Cross-Platform Packaging

This project supports packaging for:

- Windows (`.exe` installer via Inno Setup)
- Debian/Ubuntu (`.deb` via CPack)

## Windows

Use the existing Windows packaging pipeline:

```bat
deploy\windows\build.bat
iscc deploy\windows\smithtool.iss
```

Output:

- Deploy payload: `deploy\release\`
- Installer: `deploy\windows\installer\*.exe`

## Debian

Use the Linux packaging script:

```bash
chmod +x deploy/linux/build_deb.sh
./deploy/linux/build_deb.sh
```

Output:

- Debian package: `deploy/linux/dist/*.deb`

## Important

- Build Windows package on Windows toolchain.
- Build Debian package on Debian/Ubuntu (native machine, container, or CI runner).
