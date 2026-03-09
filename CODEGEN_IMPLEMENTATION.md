# CodeGenerator Implementation

## Overview

The CodeGenerator has been fully implemented in `src/CodeGenerator.cpp`. It translates Sup AST nodes into valid C++ code.

## Implemented Features

### 1. Headers and Includes (Task 10.2)
- Generates necessary C++ headers: `<iostream>`, `<string>`, `<vector>`, `<cmath>`
- Creates forward declarations for all functions

### 2. Function Generation (Task 10.3)
- Generates complete C++ function definitions
- Maps Sup types to C++ types:
  - `int` → `int`
  - `float` → `double`
  - `string` → `std::string`
  - `bool` → `bool`
  - `void` → `void`
- Handles function parameters with correct types
- Generates function signatures for forward declarations

### 3. Variable and Expression Generation (Task 10.4)
- **Variables**: Supports `var` and `const` declarations with initializers
- **Binary Operations**: Handles all operators (+, -, *, /, ==, !=, <, >, <=, >=)
  - Maps `and` → `&&`
  - Maps `or` → `||`
- **Unary Operations**: Handles negation, logical not
  - Maps `not` → `!`
- **Literals**: Properly formats numbers, strings, booleans
  - String literals are properly escaped (handles \n, \r, \t, \\, \")
- **Identifiers**: Direct name mapping
- **Function Calls**: Generates C++ function call syntax with arguments

### 4. Control Flow Generation (Task 10.5)
- **If Statements**: Generates if/else blocks with proper indentation
- **While Loops**: Generates while loops with condition and body
- **For Loops**: Generates range-based for loops (C++11 style)
  - Maps `for x in iterable` → `for (auto x : iterable)`

### 5. Code Safety and Correctness (Task 10.6)
- **String Escaping**: All special characters in string literals are properly escaped
  - Prevents code injection through string literals
  - Handles: `\n`, `\r`, `\t`, `\\`, `\"`
- **Null Checks**: All generation methods check for null pointers
- **Proper Indentation**: 4 spaces per level for readable output
- **Parentheses**: Binary operations wrapped in parentheses to preserve precedence

## Code Structure

```cpp
CodeGenerator
├── generate()                    // Main entry point
├── emitHeaders()                 // Generate #include directives
├── emitForwardDeclarations()     // Generate function prototypes
├── generateFunction()            // Generate function definitions
├── generateStatement()           // Dispatch to specific statement generators
├── generateExpression()          // Dispatch to specific expression generators
├── generateVariable()            // Variable declarations
├── generateReturn()              // Return statements
├── generateIf()                  // If/else statements
├── generateWhile()               // While loops
├── generateFor()                 // For loops
├── generateBinaryOp()            // Binary operations
├── generateUnaryOp()             // Unary operations
├── generateLiteral()             // Literal values
├── generateIdentifier()          // Variable/function names
├── generateFunctionSignature()   // Function signatures
├── mapSupTypeToCpp()            // Type mapping
└── getIndent()                   // Indentation helper
```

## Example Transformation

### Input (Sup):
```sup
func add(a: int, b: int) -> int {
    return a + b
}

func main() -> int {
    var result = add(5, 3)
    return 0
}
```

### Output (C++):
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int add(int a, int b);
int main();

int add(int a, int b) {
    return (a + b);
}

int main() {
    int result = add(5, 3);
    return 0;
}
```

## Requirements Satisfied

The implementation satisfies the following requirements from the spec:

- **4.1**: Generates valid C++ source code from validated AST
- **4.2**: Includes necessary C++ headers
- **4.3**: Generates C++ functions with correct signatures
- **4.4**: Generates C++ variable declarations
- **4.5**: Maps Sup types to corresponding C++ types
- **4.6**: Generates C++ parameters with correct types
- **4.7**: Generates C++ return statements
- **4.8**: Generates equivalent C++ operators
- **4.9**: Ensures generated code is syntactically valid
- **4.10**: Preserves semantics of original Sup program
- **16.1**: Preserves program semantics in generated C++ code
- **16.2**: Type-safe Sup programs generate type-safe C++ code
- **20.1-20.7**: Correct type mapping (int→int, float→double, string→std::string, bool→bool, void→void)

## Testing

A manual test file `test_codegen_manual.cpp` has been created to verify basic functionality.

To test the CodeGenerator:
1. Build the project using CMake
2. Run the test: `./test_codegen_manual`
3. Verify the generated C++ code is syntactically correct

## Future Enhancements

Potential improvements for future iterations:
- Support for arrays/vectors
- Support for structs/classes
- More sophisticated for-loop handling (range expressions)
- Optimization of generated code (remove unnecessary parentheses)
- Support for break/continue statements
- Support for comments in generated code
