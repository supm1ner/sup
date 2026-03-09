#ifndef TOKEN_H
#define TOKEN_H

#include <string>

namespace Sup {

// Token types for the Sup language
enum class TokenType {
    // Keywords
    KEYWORD,
    
    // Identifiers and literals
    IDENTIFIER,
    NUMBER,
    STRING,
    
    // Operators
    OPERATOR,
    
    // Punctuation
    LPAREN,      // (
    RPAREN,      // )
    LBRACE,      // {
    RBRACE,      // }
    SEMICOLON,   // ;
    COMMA,       // ,
    DOT,         // .
    
    // Special
    NEWLINE,
    EOF_TOKEN
};

// Position in source code
struct Position {
    int line;
    int column;
    
    Position(int l = 1, int c = 1) : line(l), column(c) {}
};

// Token structure
struct Token {
    TokenType type;
    std::string value;
    Position position;
    
    Token(TokenType t, const std::string& v, int line, int col)
        : type(t), value(v), position(line, col) {}
    
    Token(TokenType t, const std::string& v, const Position& pos)
        : type(t), value(v), position(pos) {}
};

} // namespace Sup

#endif // TOKEN_H
