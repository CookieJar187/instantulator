# Instantulator

Instantulator is a calculator that instantly returns the result without having to press a "=" button.
Feed the Instantulator a single string input and its algorithm will return you the result dynamically as you type.
The Instantulator currently only supports addition and subtraction.

## Technologies

- C++20
- CMake
- vcpkg
- OpenGL

## Dependencies

- glad
- GLFW
- ImGui

## Requirements

- CMake
- Git
- vcpkg
- A C++20 compiler

---

## Setup

The setup instructions bellow were tested on Windows 11 using PowerShell and MSVC. Minor adjustments may be required for other environments.

This project uses **vcpkg** to manage dependencies. To build the project, run the following commands:

### 1. Clone and bootstrap `vcpkg` (Skip this step if you already have vcpkg installed):
   Choose a location outside the project directory. For example:
   ```bash
   cd C:\
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   .\bootstrap-vcpkg.bat
   ```

### 2. Set environment variable:
   ```bash
   setx VCPKG_ROOT "C:\vcpkg"
   ```

### 3. Clone this repository:
   ```bash
   git clone https://github.com/CookieJar187/instantulator.git
   cd instantulator
   ```

### 4. In the project directory, configure the project by running:
   ```bash
   cmake -S . -B build ` -DCMAKE_TOOLCHAIN_FILE="$env:VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"
   ```

This will automatically install any dependencies listed in `vcpkg.json`.

### 5. Build
   ```bash
   cmake --build build
   ```

### 6. Run the project with:
   ```bash
   ./build/Debug/Instantulator.exe
   ```

---

## Current Project Status

This project is still in early development. Issues are to be expected and features may be subject to change.