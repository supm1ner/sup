# Sup Language Support for VS Code

This extension provides language support for the Sup programming language in Visual Studio Code.

## Features

- **Syntax Highlighting**: Full syntax highlighting for `.sup` files including:
  - Keywords (func, var, const, if, else, while, for, return, etc.)
  - Operators (+, -, *, /, ==, !=, and, or, not, etc.)
  - String literals (single and double quoted)
  - Numeric literals (integers and floats)
  - Comments (# line comments)
  - Function declarations and calls
  - Built-in types (int, float, string, bool, void, list, dict)
  - Constants (true, false, null)

- **Auto-closing Pairs**: Automatic closing of brackets, parentheses, and quotes
- **Comment Toggling**: Easy comment toggling with standard VS Code shortcuts
- **Code Folding**: Support for folding code blocks

## Installation

### From VSIX (Local Installation)

1. Download the `.vsix` file
2. Open VS Code
3. Go to Extensions view (Ctrl+Shift+X)
4. Click on the "..." menu at the top
5. Select "Install from VSIX..."
6. Choose the downloaded `.vsix` file

### From Source

1. Clone the repository
2. Navigate to the `vscode-extension` directory
3. Run `vsce package` to create a `.vsix` file
4. Install the `.vsix` file as described above

## Usage

Once installed, the extension will automatically activate when you open a `.sup` file. The syntax highlighting will be applied automatically.

## Example

```sup
# Simple Hello World program in Sup

func main() -> int {
    var message = "Hello, Sup!"
    print(message)
    return 0
}
```

## Language Features

### Keywords
- Control flow: `if`, `else`, `elif`, `while`, `for`, `in`, `return`, `break`, `continue`
- Declarations: `func`, `var`, `const`, `import`, `from`, `class`, `struct`, `enum`

### Types
- Primitive types: `int`, `float`, `string`, `bool`, `void`
- Collection types: `list`, `dict`

### Operators
- Arithmetic: `+`, `-`, `*`, `/`, `%`, `++`, `--`
- Comparison: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Logical: `and`, `or`, `not`
- Assignment: `=`, `+=`, `-=`, `*=`, `/=`
- Arrow: `->` (for function return types)

### Comments
- Line comments start with `#`

## Requirements

- Visual Studio Code version 1.60.0 or higher

## Known Issues

None at this time.

## Release Notes

### 0.1.0

Initial release of Sup Language Support:
- Syntax highlighting for all Sup language constructs
- Auto-closing pairs for brackets and quotes
- Comment toggling support
- Code folding support

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.

## License

MIT License
