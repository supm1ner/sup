#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include "AST.h"
#include <vector>
#include <memory>
#include <string>

namespace Sup {

class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);
    
    // Main parsing method
    std::unique_ptr<ProgramNode> parse();
    
    // Parse different constructs
    std::unique_ptr<ASTNode> parseStatement();
    std::unique_ptr<ASTNode> parseExpression();
    std::unique_ptr<FunctionNode> parseFunction();

private:
    std::vector<Token> tokens_;
    size_t current_;
    std::vector<std::string> errors_;
    
    // Helper methods
    const Token& currentToken() const;
    const Token& peek(int offset = 1) const;
    bool isAtEnd() const;
    void advance();
    bool match(TokenType type);
    bool check(TokenType type) const;
    Token expect(TokenType type, const std::string& message);
    std::string parseTypeName(); // Parse type name (can be KEYWORD or IDENTIFIER)
    
    // Error reporting
    void reportError(const std::string& message, const Position& position);
    
    // Parsing methods (to be implemented)
    std::unique_ptr<ASTNode> parsePrimaryExpression();
    std::unique_ptr<ASTNode> parseBinaryExpression(int precedence);
    std::unique_ptr<ASTNode> parseUnaryExpression();
    std::unique_ptr<VariableNode> parseVariableDeclaration();
    std::unique_ptr<IfNode> parseIfStatement();
    std::unique_ptr<WhileNode> parseWhileLoop();
    std::unique_ptr<ForNode> parseForLoop();
    std::unique_ptr<ReturnNode> parseReturnStatement();
    
    // Operator precedence
    int getOperatorPrecedence(const std::string& op) const;
};

} // namespace Sup

#endif // PARSER_H
