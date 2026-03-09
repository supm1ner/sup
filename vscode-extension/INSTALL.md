# Installation Guide for Sup Language VS Code Extension

This guide will help you install and use the Sup Language extension for Visual Studio Code.

## Prerequisites

- Visual Studio Code version 1.60.0 or higher
- (Optional) Node.js and npm if you want to build from source

## Installation Methods

### Method 1: Install from VSIX (Recommended)

1. **Package the extension** (if not already packaged):
   ```bash
   cd vscode-extension
   # If you have vsce installed:
   vsce package
   # This will create a .vsix file
   ```

2. **Install in VS Code**:
   - Open Visual Studio Code
   - Press `Ctrl+Shift+X` (Windows/Linux) or `Cmd+Shift+X` (Mac) to open Extensions view
   - Click on the "..." (More Actions) button at the top of the Extensions view
   - Select "Install from VSIX..."
   - Navigate to the `vscode-extension` directory
   - Select the `.vsix` file (e.g., `sup-language-0.1.0.vsix`)
   - Click "Install"

3. **Verify installation**:
   - Open a `.sup` file or create a new file with `.sup` extension
   - You should see syntax highlighting applied automatically

### Method 2: Install from Source (Development)

1. **Copy extension to VS Code extensions folder**:

   **Windows**:
   ```bash
   xcopy /E /I vscode-extension "%USERPROFILE%\.vscode\extensions\sup-language-0.1.0"
   ```

   **Linux/Mac**:
   ```bash
   cp -r vscode-extension ~/.vscode/extensions/sup-language-0.1.0
   ```

2. **Reload VS Code**:
   - Press `Ctrl+Shift+P` (Windows/Linux) or `Cmd+Shift+P` (Mac)
   - Type "Reload Window" and press Enter

3. **Verify installation**:
   - Open a `.sup` file
   - Syntax highlighting should be active

### Method 3: Development Mode

For development and testing:

1. **Open extension in VS Code**:
   ```bash
   cd vscode-extension
   code .
   ```

2. **Launch Extension Development Host**:
   - Press `F5` or go to Run > Start Debugging
   - A new VS Code window will open with the extension loaded
   - Open or create a `.sup` file in this window to test

## Building the Extension

If you want to create a `.vsix` package:

1. **Install vsce** (VS Code Extension Manager):
   ```bash
   npm install -g @vscode/vsce
   ```

2. **Package the extension**:
   ```bash
   cd vscode-extension
   vsce package
   ```

   This will create a file like `sup-language-0.1.0.vsix`

## Usage

Once installed, the extension works automatically:

1. **Open a Sup file**:
   - Open any file with `.sup` extension
   - Or create a new file and save it with `.sup` extension

2. **Syntax highlighting** will be applied automatically

3. **Use VS Code features**:
   - **Comment toggling**: `Ctrl+/` (Windows/Linux) or `Cmd+/` (Mac)
   - **Auto-closing**: Type `{`, `(`, `[`, `"`, or `'` and the closing character will be added automatically
   - **Code folding**: Click the folding icons in the gutter or use `Ctrl+Shift+[` to fold and `Ctrl+Shift+]` to unfold

## Testing the Extension

Create a test file `test.sup`:

```sup
# Test file for Sup language

func add(a: int, b: int) -> int {
    return a + b
}

func main() -> int {
    var x = 10
    var y = 20
    var result = add(x, y)
    
    if result > 25 {
        print("Result is greater than 25")
    } else {
        print("Result is 25 or less")
    }
    
    return 0
}
```

You should see:
- Keywords (`func`, `var`, `if`, `else`, `return`) highlighted
- Types (`int`) highlighted
- Strings highlighted
- Numbers highlighted
- Comments highlighted
- Operators highlighted

## Troubleshooting

### Extension not working

1. **Check VS Code version**: Ensure you have VS Code 1.60.0 or higher
2. **Reload window**: Press `Ctrl+Shift+P` and run "Reload Window"
3. **Check file extension**: Make sure your file has `.sup` extension
4. **Reinstall**: Uninstall and reinstall the extension

### Syntax highlighting not appearing

1. **Check language mode**: Look at the bottom-right corner of VS Code. It should say "Sup"
2. **Manually set language**: Click on the language indicator and select "Sup"
3. **Check theme**: Some themes may not show all colors. Try a different theme

### Building issues

1. **Install dependencies**: Make sure Node.js and npm are installed
2. **Update vsce**: Run `npm install -g @vscode/vsce` to get the latest version
3. **Check package.json**: Ensure all required fields are present

## Uninstallation

1. Open VS Code
2. Go to Extensions view (`Ctrl+Shift+X`)
3. Find "Sup Language Support"
4. Click the gear icon
5. Select "Uninstall"

## Support

For issues, questions, or contributions, please visit the project repository.
