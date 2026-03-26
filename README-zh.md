# SmithTool

[English](README.md) | [简体中文](README-zh.md)

SmithTool 是一个用于射频阻抗匹配与匹配网络设计的交互式史密斯圆图桌面应用，基于 **C++17 + Qt 6 Widgets** 开发。

## 功能

- 交互式史密斯圆图显示
- 源/负载阻抗编辑（直角坐标与极坐标）
- 匹配元件设计（串/并联 R/L/C）
- 匹配向导（L / Pi / T 等拓扑）
- Touchstone 文件导入（`.s1p`、`.s2p`）
- SPICE 网表导出
- 界面语言可选：**英语 / 简体中文**

## 依赖

- CMake >= 3.16
- 支持 C++17 的编译器
- Qt 6（`Core`、`Gui`、`Widgets`）

### Windows（推荐 MSYS2 MinGW64）

在 MSYS2 中安装工具链与 Qt6：

```powershell
pacman -S --needed mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake mingw-w64-x86_64-ninja mingw-w64-x86_64-qt6-base mingw-w64-x86_64-qt6-tools
```

### Debian / Ubuntu

```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake ninja-build qt6-base-dev qt6-base-dev-tools qt6-tools-dev-tools
```

## 构建

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

## 运行

- Windows 可执行文件示例：`SmithTool/build-msys/SmithTool.exe`
- 菜单切换语言：`Language -> English / Simplified Chinese`
- 语言偏好会保存，并在重启后生效。

## 终端用户运行时（Windows）

- 终端用户**不需要单独安装 Qt**。
- 请使用以下打包产物之一：
  - Windows 安装向导（`Setup.exe`）
  - Windows 便携包（`windows-portable.zip`）
- 这些发布包已包含 Qt 运行时和 MinGW 运行时 DLL。
- 不要单独分发/使用裸 `SmithTool.exe`（缺少配套 DLL 时无法运行）。

## 打包

- Windows 安装包（`.exe`）：基于 Inno Setup
- Debian 安装包（`.deb`）：基于 CPack/DEB

详细说明见：

- [PACKAGING.md](PACKAGING.md)
- [deploy/linux/README.md](deploy/linux/README.md)
- [deploy/windows/build.bat](deploy/windows/build.bat)

## 开源合规（Qt）

本项目面向 Qt6 动态链接的开源发布场景。
发布前请完成清单并在发布物中包含许可证与第三方声明：

- [COMPLIANCE_CHECKLIST.md](COMPLIANCE_CHECKLIST.md)
- [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md)
- [LICENSE](LICENSE)

## 许可证

MIT License，详见 [LICENSE](LICENSE)。
