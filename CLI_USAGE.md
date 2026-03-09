# Sup CLI Tool - Usage Guide

## Overview

The Sup CLI tool provides commands for compiling and running Sup programs. It implements a complete compilation pipeline: Lexer → Parser → Semantic Analyzer → Code Generator → C++ Compiler.

## Commands

### 1. `sup version`

Display the compiler version.

```bash
sup version
```

**Output:**
```
Sup Compiler v0.1.0
```

### 2. `sup compile <file.sup>`

Compile a Sup source file to an executable.

**Basic usage:**
```bash
sup compile hello.sup
```

**With custom output name:**
```bash
sup compile hello.sup -o myprogram
```

**With debug symbols:**
```bash
sup compile hello.sup --debug
```

**Compilation Pipeline:**
1. **Lexical Analysis** - Tokenizes the source code
2. **Parsing** - Builds an Abstract Syntax Tree (AST)
3. **Semantic Analysis** - Validates types and symbols
4. **Code Generation** - Generates C++ code
5. **C++ Compilation** - Compiles to native executable

**Output Files:**
- `<filename>.cpp` - Generated C++ source code
- `<filename>` or `<filename>.exe` - Compiled executable

### 3. `sup dev <file.sup>`

Compile and immediately run a Sup program (development mode).

```bash
sup dev examples/hello.sup
```

**Features:**
- Automatically enables debug symbols (`-g` flag)
- Compiles the program
- Runs the executable immediately
- Displays the program's exit code

**Example output:**
```
Reading examples/hello.sup...
Lexical analysis...
Parsing...
Semantic analysis...
Generating C++ code...
Writing C++ code to hello.cpp...
Compiling C++ code with g++...
Compilation successful!
Executable: hello

--- Running program ---
Hello, Sup!

--- Program finished with exit code 0 ---
```

## Options

### `-o <output>`

Specify the output executable name (for `compile` command).

```bash
sup compile program.sup -o myapp
```

### `-d, --debug`

Enable debug symbols in the compiled executable.

```bash
sup compile program.sup --debug
```

## Error Handling

The CLI tool provides clear error messages at each stage:

### Lexical Errors
```
Lexical error: Unterminated string at line 5, column 10
```

### Parse Errors
```
Parse error: Expected ')' at line 8, column 15
```

### Semantic Errors
```
Semantic error: Undefined variable 'x' at line 12
```

### Code Generation Errors
```
Code generation error: Cannot generate code from null AST
```

### C++ Compilation Errors
```
Error: C++ compilation failed
Command: g++ -std=c++17 hello.cpp -o hello
```

## Requirements

### Compiler Detection

The CLI tool automatically detects available C++ compilers:

- **Windows**: Uses `cl.exe` (MSVC)
- **Linux/macOS**: Tries `g++` first, then `clang++`

### C++ Standard

Generated C++ code requires C++17 or later.

## Examples

### Example 1: Hello World

**File: hello.sup**
```sup
func main() -> int {
    var message = "Hello, Sup!"
    print(message)
    return 0
}
```

**Compile and run:**
```bash
sup dev hello.sup
```

### Example 2: Math Operations

**File: math.sup**
```sup
func add(a: int, b: int) -> int {
    return a + b
}

func main() -> int {
    var result = add(5, 3)
    print(result)
    return 0
}
```

**Compile:**
```bash
sup compile math.sup -o calculator
```

**Run:**
```bash
./calculator  # Linux/macOS
calculator.exe  # Windows
```

### Example 3: Development Workflow

For rapid development and testing:

```bash
# Edit your code
vim myprogram.sup

# Test immediately
sup dev myprogram.sup

# Make changes and test again
sup dev myprogram.sup

# When ready, create optimized build
sup compile myprogram.sup -o myprogram
```

## Exit Codes

- `0` - Success
- `1` - Compilation error (lexical, parse, semantic, or code generation)
- `1` - File I/O error
- `1` - Invalid command or arguments
- For `dev` command: Returns the exit code of the executed program

## Troubleshooting

### "Error: Could not open file"

- Check that the file exists
- Verify the file path is correct
- Ensure you have read permissions

### "Error: Input file must have .sup extension"

- Sup source files must end with `.sup`
- Rename your file: `mv program.txt program.sup`

### "Error: C++ compilation failed"

- Ensure a C++ compiler is installed and in PATH
- Check the generated `.cpp` file for issues
- Verify C++17 support in your compiler

### "No input file specified"

- Provide a source file: `sup compile myfile.sup`

## Implementation Details

### Compilation Pipeline

```
.sup file
    ↓
[Lexer] → Tokens
    ↓
[Parser] → AST
    ↓
[Semantic Analyzer] → Validated AST
    ↓
[Code Generator] → C++ code
    ↓
[C++ Compiler] → Executable
```

### Type Mapping

Sup types are mapped to C++ types:

- `int` → `int`
- `float` → `double`
- `string` → `std::string`
- `bool` → `bool`
- `void` → `void`

### Generated Code Structure

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// Forward declarations
int main();

// Function implementations
int main() {
    // Generated code
    return 0;
}
```

## Future Enhancements

Planned features for future versions:

- Package management (`sup install <package>`)
- Optimization levels (`-O1`, `-O2`, `-O3`)
- Watch mode for automatic recompilation
- Better error messages with code snippets
- Cross-compilation support
- REPL mode for interactive development
