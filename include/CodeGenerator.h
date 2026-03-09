#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "AST.h"
#include <string>
#include <sstream>

namespace Sup {

class CodeGenerator {
public:
    CodeGenerator();
    
    // Main code generation method
    std::string generate(ProgramNode* ast);
    
    // Generate different constructs
    std::string generateFunction(FunctionNode* node);
    std::string generateStatement(ASTNode* node, int indentLevel = 0);
    std::string generateExpression(ASTNode* node);

private:
    std::stringstream output_;
    int indentLevel_;
    
    // Helper methods
    std::string getIndent(int level) const;
    std::string mapSupTypeToCpp(const std::string& supType) const;
    std::string generateFunctionSignature(FunctionNode* node);
    
    // Generation methods for different node types
    std::string generateVariable(VariableNode* node);
    std::string generateReturn(ReturnNode* node);
    std::string generateIf(IfNode* node, int indentLevel);
    std::string generateWhile(WhileNode* node, int indentLevel);
    std::string generateFor(ForNode* node, int indentLevel);
    std::string generateBinaryOp(BinaryOpNode* node);
    std::string generateUnaryOp(UnaryOpNode* node);
    std::string generateLiteral(LiteralNode* node);
    std::string generateIdentifier(IdentifierNode* node);
    
    // Code generation utilities
    void emitHeaders();
    void emitForwardDeclarations(ProgramNode* ast);
};

} // namespace Sup

#endif // CODE_GENERATOR_H
