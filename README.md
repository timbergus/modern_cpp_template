# Modern C++ Playground

A playground for experimenting with modern C++ features and libraries. It can be used as template for your own projects.

To use it, clone the repository and open it in your favorite IDE. You can then build and run the example code provided in the `src` directory.

## Requirements

- C++23 compatible compiler
- Make for tooling
- CMake for building
- VSCode with C++ extension

## Getting Started

1. Clone the repository
2. Replace name and description in `CMakeLists.txt` file to personalize your distribution.
3. Run the example with `make start`. It will init and build the project, and run the example code.
4. Modify the example code in the `src` directory to experiment with different C++ features.
5. Package your project for distribution using `make package`.

## C++ Properties (c_cpp_properties.json)

```json
{
  "configurations": [
    {
      "name": "Mac",
      "includePath": ["${workspaceFolder}/**"],
      "defines": [],
      "compileCommands": ["${workspaceFolder}/build/compile_commands.json"],
      "compilerPath": "/opt/homebrew/opt/llvm/bin/clang++",
      "cStandard": "c23",
      "cppStandard": "c++26"
    }
  ],
  "version": 4
}
```
