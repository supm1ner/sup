#ifndef LEXER_H
#define LEXER_H

#include "Token.h"
#include <vector>
#include <string>
#include <set>

namespace Sup {

class Lexer {
public:
    explicit Lexer(const std::string& source);
    
    // Main tokenization method
    std::vector<Token> tokenize();
    
    // Get current position
    Position getCurrentPosition() const;
    
    // Error reporting
    void reportError(const std::string& message, const Position& position);

private:
    std::string source_;
    size_t position_;
    int line_;
    int column_;
    std::vector<std::string> errors_;
    
    // Keywords set
    static const std::set<std::string> keywords_;
    
    // Helper methods
    char currentChar() const;
    char peek(int offset = 1) const;
    void advance();
    bool isAtEnd() const;
    
    // Character classification
    bool isAlpha(char c) const;
    bool isDigit(char c) const;
    bool isAlphaNumeric(char c) const;
    bool isWhitespace(char c) const;
    
    // Token recognition
    Token scanIdentifierOrKeyword();
    Token scanNumber();
    Token scanString(char quote);
    Token scanOperator();
};

} // namespace Sup

#endif // LEXER_H
