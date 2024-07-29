# CPP Project Boilerplate

This is a boilerplate for a C++ project.

## Setup

### Prerequisites

Ensure you have the following tools installed on your system:

1. **C++ Compiler and Build Tools**

   You can install either `build-essential` (which includes `g++`) or `g++` directly.

   - Option 1: Install `build-essential`:

     ```sh
     sudo apt update
     sudo apt install build-essential
     ```

   - Option 2: Install `g++` directly:

     ```sh
     sudo apt update
     sudo apt install g++
     ```

2. **GDB (GNU Debugger)**

   ```sh
   sudo apt install gdb
   ```

3. **CMake**

   ```sh
   sudo apt install cmake
   ```

4. **clang-format**

   ```sh
   sudo apt install clang-format
   ```

5. **Visual Studio Code** with the following extensions:
   - C/C++ by Microsoft
   - CMake Tools by Microsoft

To install the C/C++ extension:

1. Open Visual Studio Code.
2. Go to Extensions view by pressing `Ctrl+Shift+X`.
3. Search for `C/C++` by Microsoft and click Install.

To install the CMake Tools extension:

1. Open Visual Studio Code.
2. Go to Extensions view by pressing `Ctrl+Shift+X`.
3. Search for `CMake Tools` by Microsoft and click Install.

## How to Compile, Run, Clean, and Debug the Project

### Compile the Project

To compile the project, use the `make` command. This will generate the executable file in the `output` directory.

```sh
make
```

### Run the Project

To run the compiled executable, use the make run command. This will compile the project (if necessary) and then run the executable.

```sh
make run
```

### Clean the Project

To clean up the build files, including object files and the executable, use the make clean command.

```sh
make clean
```

### Debug the Project

Make sure you have installed GDB on your system. To debug the project.

#### Debugging using GDB in the Terminal

1. Compile the project with debugging symbols.

   ```sh
   make
   ```

2. Run `gdb` with the executable.

   ```sh
   gdb ./output/main
   ```

3. Inside gdb, set breakpoints and run the program:

   ```sh
   (gdb) break main
   (gdb) run
   ```

4. Use typical gdb commands to step through the code, inspect variables, etc.

   ```sh
   (gdb) step
   (gdb) print variable_name
   ```

#### Debugging using Visual Studio Code

We can also debug the project using Visual Studio Code. To do this, follow these steps:

1. Open the project in Visual Studio Code.
2. Open the file you want to debug.
3. Set breakpoints by clicking on the left margin of the editor window.
4. Press `F5` to start debugging.
5. Use shortcuts like `F10` to step over, `F11` to step into, etc.
6. Use the debug panel on the left to inspect variables, call stack, etc.

## File Structure

The project has the following file structure:

- `src/`: Contains the source files (`.cpp`).
- `include/`: Contains the header files (`.hpp`).
- `output/`: Contains the compiled executable.
- `lib/`: Contains third-party libraries (`.a` , etc...)
- `Makefile`: Contains the build, run, clean, and debug commands.
- `.clang-format`: Contains the formatting style for clang-format.
- `.vscode/`: Contains the Visual Studio Code settings and configurations for C++.
