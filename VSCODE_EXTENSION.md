# VS Code Extension for Sup Language

This document provides information about the VS Code extension for the Sup programming language.

## Location

The VS Code extension is located in the `vscode-extension/` directory of this repository.

## Quick Start

### Installation

1. Navigate to the extension directory:
   ```bash
   cd vscode-extension
   ```

2. Package the extension (requires vsce):
   ```bash
   # Install vsce if you don't have it
   npm install -g @vscode/vsce
   
   # Package the extension
   vsce package
   ```

3. Install in VS Code:
   - Open VS Code
   - Press `Ctrl+Shift+X` (or `Cmd+Shift+X` on Mac)
   - Click the "..." menu at the top
   - Select "Install from VSIX..."
   - Choose the generated `.vsix` file

### Testing

Open any `.sup` file (e.g., `examples/hello.sup` or `examples/math.sup`) and you'll see syntax highlighting automatically applied.

## Features

The extension provides:

- ✅ **Syntax Highlighting**: Complete highlighting for all Sup language constructs
  - Keywords: `func`, `var`, `const`, `if`, `else`, `while`, `for`, `return`, etc.
  - Types: `int`, `float`, `string`, `bool`, `void`, `list`, `dict`
  - Operators: `+`, `-`, `*`, `/`, `==`, `!=`, `and`, `or`, `not`, etc.
  - Strings, numbers, comments, and more

- ✅ **Editor Features**:
  - Auto-closing brackets, parentheses, and quotes
  - Comment toggling with `Ctrl+/` (or `Cmd+/`)
  - Code folding support
  - Proper indentation

## Documentation

Comprehensive documentation is available in the `vscode-extension/` directory:

- **README.md** - User documentation with features and examples
- **INSTALL.md** - Detailed installation instructions
- **QUICKSTART.md** - Quick start guide for users and developers
- **EXTENSION_SUMMARY.md** - Complete implementation summary
- **CHANGELOG.md** - Version history

## Example

Here's what Sup code looks like with the extension:

```sup
# Simple Hello World program in Sup

func main() -> int {
    var message = "Hello, Sup!"
    print(message)
    return 0
}
```

All elements (keywords, types, strings, comments, operators) will be properly highlighted.

## Development

To work on the extension:

1. Open the extension directory in VS Code:
   ```bash
   cd vscode-extension
   code .
   ```

2. Press `F5` to launch the Extension Development Host

3. Make changes to `syntaxes/sup.tmLanguage.json`

4. Reload the development host with `Ctrl+R` (or `Cmd+R`)

## Requirements Fulfilled

This extension fulfills **Requirements 10.1-10.6** from the Sup language specification:

- ✅ 10.1: Provides syntax highlighting for .sup files
- ✅ 10.2: Applies highlighting when .sup files are opened
- ✅ 10.3: Recognizes and highlights Sup keywords
- ✅ 10.4: Recognizes and highlights Sup operators
- ✅ 10.5: Recognizes and highlights Sup string literals
- ✅ 10.6: Recognizes and highlights Sup comments

Optional features (10.7-10.9: auto-completion, hover info, diagnostics) are not implemented in this version but can be added in the future.

## Technical Details

- **Extension ID**: `sup-language`
- **Language ID**: `sup`
- **File Extension**: `.sup`
- **Grammar Scope**: `source.sup`
- **Grammar Type**: TextMate
- **Minimum VS Code Version**: 1.60.0

## Future Enhancements

Possible future additions:

1. **Auto-completion** (Task 18.3) - Suggest keywords and identifiers
2. **Error Diagnostics** (Task 18.4) - Show compilation errors in editor
3. **Hover Information** (Task 18.5) - Display type information on hover
4. **Language Server** - For advanced features like go-to-definition, find references, etc.

## Support

For issues or questions about the extension, please refer to the documentation in the `vscode-extension/` directory or the main project README.

## License

MIT License - See the main project LICENSE file for details.
