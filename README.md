# Modern C++ Template

A template for experimenting with modern C++ features and libraries. It can be used as a starting point for your own projects.

To use it, in GitHub, click on "Use this template" button.

Then, clone the new repository and open it in your favorite IDE. You can then build and run the example code provided in the `src` directory.

## Requirements

- C++23 compatible compiler.
- Make for tooling.
- CMake for building.
- VSCode with C++ extension.

## Getting Started

1. Clone the repository.
2. Change project name in `CMakeLists.txt` and `Makefile`.
3. Replace author's name and project description in `CMakeLists.txt` file to personalize your distribution.
4. Run the example with `make start`. It will init and build the project, and run the example code.
5. Modify the example code in the `src` directory to experiment with different C++ features.
6. Create your project documentation using `make documentation`.
7. Package your project for distribution using `make package`.

## Included Libraries

- **fmt**: A modern formatting library for C++.
- **my_ho_lib**: A custom header-only library.
- **my_lib**: A custom static library.

It includes fmt to include the downloading system for commercial libraries. It will be downloaded automatically from GitHub and linked to your project.

## C++ Properties

You can define this properties into `.vscode/c_cpp_properties.json`.

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

## Resources

- [CMake Documentation](https://cmake.org/documentation/)
- [Doxygen Documentation](https://www.doxygen.nl/manual/index.html)
- [CPack Documentation](https://cmake.org/cmake/help/latest/module/CPack.html)
