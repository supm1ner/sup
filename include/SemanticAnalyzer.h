#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include "AST.h"
#include <string>
#include <map>
#include <vector>
#include <memory>

namespace Sup {

// Symbol kinds
enum class SymbolKind {
    VARIABLE,
    FUNCTION,
    PARAMETER
};

// Symbol information
struct Symbol {
    std::string name;
    std::string type;
    SymbolKind kind;
    bool isConst;
    
    // Default constructor for std::map
    Symbol() : name(""), type(""), kind(SymbolKind::VARIABLE), isConst(false) {}
    
    Symbol(const std::string& n, const std::string& t, SymbolKind k, bool c = false)
        : name(n), type(t), kind(k), isConst(c) {}
};

// Symbol table with scope support
class SymbolTable {
public:
    SymbolTable();
    
    // Scope management
    void enterScope();
    void exitScope();
    
    // Symbol operations
    void define(const std::string& name, const Symbol& symbol);
    Symbol* resolve(const std::string& name);
    bool isDefined(const std::string& name) const;
    
private:
    std::vector<std::map<std::string, Symbol>> scopes_;
    size_t currentScope_;
};

// Semantic analyzer
class SemanticAnalyzer {
public:
    SemanticAnalyzer();
    
    // Main analysis method
    bool analyze(ProgramNode* ast);
    
    // Type checking
    std::string checkTypes(ASTNode* node);
    
    // Symbol resolution
    void resolveSymbols(ASTNode* node);
    
    // Validation
    std::vector<std::string> validateSemantics(ASTNode* node);
    
    // Get errors
    const std::vector<std::string>& getErrors() const { return errors_; }

private:
    SymbolTable symbolTable_;
    std::vector<std::string> errors_;
    std::string currentFunction_;
    
    // Helper methods
    void reportError(const std::string& message, const Position& position);
    bool isTypeCompatible(const std::string& expected, const std::string& actual);
    
    // Analysis methods for different node types
    void analyzeFunction(FunctionNode* node);
    void analyzeVariable(VariableNode* node);
    void analyzeExpression(ASTNode* node);
    std::string inferExpressionType(ASTNode* node);
};

} // namespace Sup

#endif // SEMANTIC_ANALYZER_H
