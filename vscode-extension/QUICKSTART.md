# Quick Start Guide - Sup Language VS Code Extension

This guide will help you quickly get started with developing or using the Sup Language extension.

## For Users

### Quick Installation

1. **Package the extension**:
   ```bash
   cd vscode-extension
   # If you don't have vsce, install it first:
   # npm install -g @vscode/vsce
   vsce package
   ```

2. **Install in VS Code**:
   - Open VS Code
   - Press `Ctrl+Shift+P` (or `Cmd+Shift+P` on Mac)
   - Type "Extensions: Install from VSIX"
   - Select the generated `.vsix` file

3. **Test it**:
   - Open the included `test-sample.sup` file
   - You should see beautiful syntax highlighting!

### Quick Test

Create a new file `hello.sup`:

```sup
# My first Sup program
func main() -> int {
    var message = "Hello, Sup!"
    print(message)
    return 0
}
```

Save it and watch the syntax highlighting come to life!

## For Developers

### Project Structure

```
vscode-extension/
├── package.json              # Extension manifest
├── language-configuration.json  # Language configuration
├── syntaxes/
│   └── sup.tmLanguage.json  # TextMate grammar
├── README.md                 # User documentation
├── CHANGELOG.md             # Version history
├── INSTALL.md               # Installation guide
├── icon.svg                 # Extension icon
├── test-sample.sup          # Test file
└── .vscodeignore           # Files to exclude from package
```

### Key Files

1. **package.json**: Defines the extension metadata and contributions
   - Language ID: `sup`
   - File extension: `.sup`
   - Grammar scope: `source.sup`

2. **language-configuration.json**: Defines language-specific editor behavior
   - Comment style: `#`
   - Bracket pairs: `{}`, `[]`, `()`
   - Auto-closing pairs
   - Folding markers

3. **syntaxes/sup.tmLanguage.json**: TextMate grammar for syntax highlighting
   - Keywords: `func`, `var`, `const`, `if`, `else`, etc.
   - Types: `int`, `float`, `string`, `bool`, `void`
   - Operators: `+`, `-`, `*`, `/`, `==`, `!=`, `and`, `or`, etc.
   - Comments, strings, numbers

### Testing During Development

1. **Open in VS Code**:
   ```bash
   cd vscode-extension
   code .
   ```

2. **Launch Extension Development Host**:
   - Press `F5`
   - Or: Run > Start Debugging
   - A new VS Code window opens with the extension loaded

3. **Test changes**:
   - Open `test-sample.sup` in the development host
   - Make changes to the grammar
   - Reload the development host: `Ctrl+R` (or `Cmd+R`)

### Modifying Syntax Highlighting

Edit `syntaxes/sup.tmLanguage.json`:

```json
{
  "repository": {
    "keywords": {
      "patterns": [
        {
          "name": "keyword.control.sup",
          "match": "\\b(if|else|while|for|return)\\b"
        }
      ]
    }
  }
}
```

**Pattern structure**:
- `name`: Scope name (determines color based on theme)
- `match`: Regular expression to match
- `begin`/`end`: For multi-line patterns (like strings)
- `captures`: To highlight parts of a match differently

**Common scope names**:
- `keyword.control.*` - Control flow keywords
- `keyword.operator.*` - Operators
- `storage.type.*` - Type names
- `string.quoted.*` - String literals
- `constant.numeric.*` - Numbers
- `comment.line.*` - Comments
- `entity.name.function.*` - Function names

### Adding New Features

#### Add a new keyword:

1. Edit `syntaxes/sup.tmLanguage.json`
2. Add to the keywords pattern:
   ```json
   "match": "\\b(if|else|while|for|return|mynewkeyword)\\b"
   ```

#### Add a new operator:

1. Edit `syntaxes/sup.tmLanguage.json`
2. Add to the operators pattern:
   ```json
   "match": "(==|!=|<=|>=|<|>|mynewop)"
   ```

#### Add auto-closing for a new character:

1. Edit `language-configuration.json`
2. Add to `autoClosingPairs`:
   ```json
   { "open": "<", "close": ">" }
   ```

### Building and Publishing

1. **Update version** in `package.json`

2. **Update CHANGELOG.md** with changes

3. **Build the package**:
   ```bash
   vsce package
   ```

4. **Test the package**:
   - Install the `.vsix` file in VS Code
   - Test all features

5. **Publish** (if you have a publisher account):
   ```bash
   vsce publish
   ```

### Debugging Tips

1. **Check scope inspector**:
   - Press `Ctrl+Shift+P` > "Developer: Inspect Editor Tokens and Scopes"
   - Click on any token to see its scope
   - Verify your grammar is matching correctly

2. **Check console**:
   - In the Extension Development Host
   - Help > Toggle Developer Tools
   - Look for errors in the console

3. **Reload window**:
   - After making changes
   - Press `Ctrl+R` in the Extension Development Host

### Common Issues

**Syntax highlighting not working**:
- Check the `scopeName` in `sup.tmLanguage.json` matches `package.json`
- Verify the file extension is `.sup`
- Check for JSON syntax errors in grammar file

**Extension not loading**:
- Check `package.json` for errors
- Verify `engines.vscode` version
- Check VS Code version compatibility

**Grammar not matching**:
- Use the scope inspector to debug
- Test regex patterns in a regex tester
- Remember to escape special characters: `\\b`, `\\(`, `\\.`

## Resources

- [VS Code Extension API](https://code.visualstudio.com/api)
- [TextMate Grammar Guide](https://macromates.com/manual/en/language_grammars)
- [Syntax Highlight Guide](https://code.visualstudio.com/api/language-extensions/syntax-highlight-guide)
- [Publishing Extensions](https://code.visualstudio.com/api/working-with-extensions/publishing-extension)

## Next Steps

### Optional Enhancements (Tasks 18.3-18.5)

1. **Auto-completion** (Task 18.3):
   - Implement a completion provider
   - Suggest keywords, functions, variables

2. **Error diagnostics** (Task 18.4):
   - Integrate with Sup compiler
   - Show errors in the editor

3. **Hover information** (Task 18.5):
   - Show type information on hover
   - Display function signatures

These require implementing a Language Server or extension activation code.

## Support

For questions or issues, please refer to the main project documentation.
