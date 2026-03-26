@echo off
REM SmithTool Windows Build and Package Script
REM Run this script in an environment where Qt tools are available

setlocal enabledelayedexpansion

echo ===================================
echo SmithTool Windows Build Script
echo ===================================
echo.

REM Get script directory
set SCRIPT_DIR=%~dp0
set PROJECT_DIR=%SCRIPT_DIR%..\..
set BUILD_DIR=%PROJECT_DIR%\build-release
set DEPLOY_DIR=%PROJECT_DIR%\deploy\release
set CMAKE_GENERATOR=%CMAKE_GENERATOR%
set CMAKE_BUILD_TYPE=%CMAKE_BUILD_TYPE%
set CMAKE_PREFIX_PATH=%CMAKE_PREFIX_PATH%
set BUILD_JOBS=%BUILD_JOBS%

if "%CMAKE_GENERATOR%"=="" set CMAKE_GENERATOR=Ninja
if "%CMAKE_BUILD_TYPE%"=="" set CMAKE_BUILD_TYPE=Release
if "%BUILD_JOBS%"=="" set BUILD_JOBS=2

REM Some CI environments provide CMAKE_PREFIX_PATH in a format not usable by cmd/cmake on Windows.
REM If Qt6Config.cmake cannot be found under the provided prefix, clear it and fallback to auto-detection.
if not "%CMAKE_PREFIX_PATH%"=="" (
    if not exist "%CMAKE_PREFIX_PATH%\lib\cmake\Qt6\Qt6Config.cmake" (
        echo INFO: Ignoring invalid CMAKE_PREFIX_PATH value: %CMAKE_PREFIX_PATH%
        set CMAKE_PREFIX_PATH=
    )
)

if "%CMAKE_PREFIX_PATH%"=="" (
    if exist "E:\msys2\mingw64\lib\cmake\Qt6\Qt6Config.cmake" set CMAKE_PREFIX_PATH=E:\msys2\mingw64
)
if "%CMAKE_PREFIX_PATH%"=="" (
    if exist "C:\msys64\mingw64\lib\cmake\Qt6\Qt6Config.cmake" set CMAKE_PREFIX_PATH=C:\msys64\mingw64
)
if "%CMAKE_PREFIX_PATH%"=="" (
    echo WARNING: CMAKE_PREFIX_PATH is not set and no MSYS2 Qt6 path was auto-detected.
    echo          Set CMAKE_PREFIX_PATH to your Qt installation root if configure fails.
)

REM Prefer Qt toolchain bin path to avoid picking an incompatible MinGW from PATH
if not "%CMAKE_PREFIX_PATH%"=="" (
    if exist "%CMAKE_PREFIX_PATH%\bin" (
        set "PATH=%CMAKE_PREFIX_PATH%\bin;%PATH%"
    )
)

set C_COMPILER_ARG=
set CXX_COMPILER_ARG=
if not "%CMAKE_PREFIX_PATH%"=="" (
    if exist "%CMAKE_PREFIX_PATH%\bin\gcc.exe" set C_COMPILER_ARG=-DCMAKE_C_COMPILER=%CMAKE_PREFIX_PATH%\bin\gcc.exe
    if exist "%CMAKE_PREFIX_PATH%\bin\g++.exe" set CXX_COMPILER_ARG=-DCMAKE_CXX_COMPILER=%CMAKE_PREFIX_PATH%\bin\g++.exe
)

echo Project directory: %PROJECT_DIR%
echo Build directory: %BUILD_DIR%
echo Deploy directory: %DEPLOY_DIR%
echo Generator: %CMAKE_GENERATOR%
echo Build type: %CMAKE_BUILD_TYPE%
echo Parallel jobs: %BUILD_JOBS%
echo CMAKE_PREFIX_PATH: %CMAKE_PREFIX_PATH%
if not "%C_COMPILER_ARG%"=="" echo C compiler: %C_COMPILER_ARG%
if not "%CXX_COMPILER_ARG%"=="" echo C++ compiler: %CXX_COMPILER_ARG%
echo.

REM Create build directory
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"
cd /d "%BUILD_DIR%"

echo [1/4] Generating build files...
cmake "%PROJECT_DIR%" -G "%CMAKE_GENERATOR%" -DCMAKE_BUILD_TYPE=%CMAKE_BUILD_TYPE% -DCMAKE_PREFIX_PATH="%CMAKE_PREFIX_PATH%" %C_COMPILER_ARG% %CXX_COMPILER_ARG%
if errorlevel 1 (
    echo ERROR: CMake configuration failed!
    exit /b 1
)

echo.
echo [2/4] Building...
cmake --build . --config %CMAKE_BUILD_TYPE% --parallel %BUILD_JOBS%
if errorlevel 1 (
    echo ERROR: Build failed!
    exit /b 1
)

echo.
echo [3/4] Deploying Qt dependencies...
if not exist "%DEPLOY_DIR%" mkdir "%DEPLOY_DIR%"

set EXE_PATH=
if exist "%BUILD_DIR%\SmithTool.exe" set EXE_PATH=%BUILD_DIR%\SmithTool.exe
if exist "%BUILD_DIR%\%CMAKE_BUILD_TYPE%\SmithTool.exe" set EXE_PATH=%BUILD_DIR%\%CMAKE_BUILD_TYPE%\SmithTool.exe

if "%EXE_PATH%"=="" (
    echo ERROR: SmithTool.exe not found in build output!
    exit /b 1
)

copy /Y "%EXE_PATH%" "%DEPLOY_DIR%\SmithTool.exe"
cd /d "%DEPLOY_DIR%"

set WINDEPLOY=
for %%T in (windeployqt6.exe windeployqt.exe windeployqt6 windeployqt) do (
    where %%T >nul 2>&1
    if not errorlevel 1 (
        set WINDEPLOY=%%T
        goto :deploy_found
    )
)

:deploy_found
if "%WINDEPLOY%"=="" (
    echo ERROR: windeployqt tool not found in PATH.
    echo Please add Qt bin directory to PATH and retry.
    exit /b 1
)

%WINDEPLOY% --release --no-translations SmithTool.exe
if errorlevel 1 (
    echo ERROR: %WINDEPLOY% failed.
    exit /b 1
)

echo.
echo [4/4] Build complete!
echo.
echo Output files are in: %DEPLOY_DIR%
echo.

REM Show file list
echo Files created:
dir /b "%DEPLOY_DIR%\*.exe"
dir /b "%DEPLOY_DIR%\*.dll" 2>nul

echo.
echo To create installer, run Inno Setup with:
echo   iscc "%SCRIPT_DIR%\smithtool.iss"
echo.

endlocal
