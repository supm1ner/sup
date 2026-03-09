#ifndef AST_H
#define AST_H

#include "Token.h"
#include <vector>
#include <memory>
#include <string>
#include <map>

namespace Sup {

// Node types for the AST
enum class NodeType {
    PROGRAM,
    FUNCTION_DECL,
    VARIABLE_DECL,
    IF_STMT,
    WHILE_LOOP,
    FOR_LOOP,
    RETURN_STMT,
    EXPRESSION,
    BINARY_OP,
    UNARY_OP,
    LITERAL,
    IDENTIFIER,
    CALL_EXPR
};

// Base AST Node
class ASTNode {
public:
    NodeType nodeType;
    Position position;
    std::map<std::string, std::string> metadata;
    
    explicit ASTNode(NodeType type, const Position& pos = Position())
        : nodeType(type), position(pos) {}
    
    virtual ~ASTNode() = default;
};

// Program node (root)
class ProgramNode : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> statements;
    
    ProgramNode() : ASTNode(NodeType::PROGRAM) {}
};

// Function declaration node
class FunctionNode : public ASTNode {
public:
    std::string name;
    std::string returnType;
    std::vector<std::pair<std::string, std::string>> parameters; // (name, type)
    std::vector<std::unique_ptr<ASTNode>> body;
    
    FunctionNode() : ASTNode(NodeType::FUNCTION_DECL) {}
};

// Variable declaration node
class VariableNode : public ASTNode {
public:
    std::string name;
    std::string type;
    bool isConst;
    std::unique_ptr<ASTNode> initializer;
    
    VariableNode() : ASTNode(NodeType::VARIABLE_DECL), isConst(false) {}
};

// Expression node
class ExpressionNode : public ASTNode {
public:
    std::string expressionType; // Type of the expression result
    
    ExpressionNode() : ASTNode(NodeType::EXPRESSION) {}
};

// Binary operation node
class BinaryOpNode : public ExpressionNode {
public:
    std::string op;
    std::unique_ptr<ASTNode> left;
    std::unique_ptr<ASTNode> right;
    
    BinaryOpNode() { nodeType = NodeType::BINARY_OP; }
};

// Unary operation node
class UnaryOpNode : public ExpressionNode {
public:
    std::string op;
    std::unique_ptr<ASTNode> operand;
    
    UnaryOpNode() { nodeType = NodeType::UNARY_OP; }
};

// Literal node
class LiteralNode : public ExpressionNode {
public:
    std::string value;
    std::string literalType; // "int", "float", "string", "bool"
    
    LiteralNode() { nodeType = NodeType::LITERAL; }
};

// Identifier node
class IdentifierNode : public ExpressionNode {
public:
    std::string name;
    
    IdentifierNode() { nodeType = NodeType::IDENTIFIER; }
};

// Return statement node
class ReturnNode : public ASTNode {
public:
    std::unique_ptr<ASTNode> value;
    
    ReturnNode() : ASTNode(NodeType::RETURN_STMT) {}
};

// If statement node
class IfNode : public ASTNode {
public:
    std::unique_ptr<ASTNode> condition;
    std::vector<std::unique_ptr<ASTNode>> thenBranch;
    std::vector<std::unique_ptr<ASTNode>> elseBranch;
    
    IfNode() : ASTNode(NodeType::IF_STMT) {}
};

// While loop node
class WhileNode : public ASTNode {
public:
    std::unique_ptr<ASTNode> condition;
    std::vector<std::unique_ptr<ASTNode>> body;
    
    WhileNode() : ASTNode(NodeType::WHILE_LOOP) {}
};

// For loop node
class ForNode : public ASTNode {
public:
    std::string variable;
    std::unique_ptr<ASTNode> iterable;
    std::vector<std::unique_ptr<ASTNode>> body;
    
    ForNode() : ASTNode(NodeType::FOR_LOOP) {}
};

// Function call expression node
class CallExprNode : public ExpressionNode {
public:
    std::string functionName;
    std::vector<std::unique_ptr<ASTNode>> arguments;
    
    CallExprNode() { nodeType = NodeType::CALL_EXPR; }
};

} // namespace Sup

#endif // AST_H
