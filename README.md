# CppVsCodeDemo

A minimal C++ project template for personal development in Visual Studio Code with CMake presets.

## Build presets

This project uses CMake presets with the `Ninja` generator and provides three toolchain options:

- `gcc-debug` / `gcc-release`: build with `gcc` and `g++`
- `clang-debug` / `clang-release`: build with `clang` and `clang++`
- `msvc-debug` / `msvc-release`: build with `cl.exe`

## Development environment

Before building, make sure these tools are available in `PATH`:

- `cmake` 3.25 or newer
- `ninja`
- one supported C/C++ toolchain:
  - `gcc` and `g++` for the `gcc-*` presets
  - `clang` and `clang++` for the `clang-*` presets
  - `cl.exe` for the `msvc-*` presets

### Recommended on Windows: MSYS2 UCRT64

For the `gcc-*` and `clang-*` presets, `MSYS2 UCRT64` is a reasonable default on Windows. It provides a consistent toolchain and uses the modern Universal CRT instead of the older `msvcrt` runtime.

Typical packages:

- `mingw-w64-ucrt-x86_64-gcc`
- `mingw-w64-ucrt-x86_64-clang`
- `mingw-w64-ucrt-x86_64-cmake`
- `mingw-w64-ucrt-x86_64-ninja`
- `mingw-w64-ucrt-x86_64-gdb`

Recommended usage:

1. Install MSYS2.
2. Open the `MSYS2 UCRT64` shell.
3. Install the packages above with `pacman`.
4. Start VS Code from that shell with `code .`, or make sure `C:\msys64\ucrt64\bin` is in `PATH`.

If you use the `msvc-*` presets instead, install Visual Studio Build Tools or Visual Studio with the C++ workload, then build from a Developer PowerShell or Developer Command Prompt so `cl.exe` is available.

## Structure

```
.
├── src/
│   ├── Calculator.h / Calculator.cpp   # core logic
│   ├── export.h / export.cpp           # DLL export interface
│   └── main.cpp                        # executable entry point
├── CMakeLists.txt
├── CMakePresets.json
└── test_dll.py                         # Python script to verify DLL
```

New `.cpp` files placed anywhere under `src/` are picked up automatically — no CMake changes needed.

## Build modes

The project supports two build modes controlled by the `BUILD_LIB` option:

| Mode | Command | Output |
|---|---|---|
| Executable (default) | `BUILD_LIB=OFF` | `MAIN.exe` |
| Shared library | `BUILD_LIB=ON` | `LIB.dll` |

## Command line workflow

### Executable

```powershell
cmake --preset msvc-debug
cmake --build --preset msvc-debug
.\build\msvc-debug\bin\MAIN.exe
```

### Shared library (DLL)

```powershell
cmake --preset msvc-release -DBUILD_LIB=ON
cmake --build --preset msvc-release
```

### Test the DLL from Python

```powershell
python test_dll.py
```

## VS Code workflow

1. Select a configure preset in VS Code, such as `gcc-debug` or `msvc-debug`.
2. Run CMake configure and build from the status bar or command palette.
3. Use `MAIN` as the active launch target in CMake Tools.
4. Start debugging with the matching launch configuration.

## Recommended VS Code extensions

- `ms-vscode.cpptools`
- `ms-vscode.cmake-tools`
