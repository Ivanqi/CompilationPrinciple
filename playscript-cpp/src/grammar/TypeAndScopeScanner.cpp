#include "TypeAndScopeScanner.h"
#include "BlockScope.h"
#include "Class.h"
#include "NameSpace.h"
#include "Function.h"
using namespace play;


TypeAndScopeScanner::TypeAndScopeScanner(AnnotatedTree *at_): at(at_)
{
}

// 在遍历树的过程中，当前的Scope
Scope* TypeAndScopeScanner::currentScope()
{
    if (scopeStack.size() > 0) {
        Scope* top = scopeStack.top();
        scopeStack.pop();
        return top;
    } else {
        return NULL;
    }
}

Scope* TypeAndScopeScanner::pushScope(Scope *scope, ParserRuleContext *ctx)
{
    at->node2Scope.insert(std::pair<ParserRuleContext*, Scope*>(ctx, scope));
    scope->setCtx(ctx);

    scopeStack.push(scope);
    return scope;
}

void TypeAndScopeScanner::popScope() {
    scopeStack.pop();
}

void TypeAndScopeScanner::enterProg(PlayScriptParser::ProgContext *ctx)
{
    NameSpace *scope = new NameSpace("", currentScope(), ctx);
    at->namespaces = scope; // scope的根
    pushScope(scope, ctx);
}

void TypeAndScopeScanner::exitProg(PlayScriptParser::ProgContext *ctx)
{
    popScope();
}


void TypeAndScopeScanner::enterBlock(PlayScriptParser::BlockContext *ctx) 
{
    // 对于函数，不需要再额外建一个scope
    PlayScriptParser::FunctionBodyContext *tmp = dynamic_cast<PlayScriptParser::FunctionBodyContext*>(ctx->parent);
    if (tmp != NULL) {
        BlockScope *scope = new BlockScope(currentScope(), ctx);
        currentScope()->addSymbol(scope);
        pushScope(scope, ctx);
    }
}

void TypeAndScopeScanner::exitBlock(PlayScriptParser::BlockContext *ctx)
{
    PlayScriptParser::FunctionBodyContext *tmp = dynamic_cast<PlayScriptParser::FunctionBodyContext*>(ctx->parent);
    if (tmp != NULL) {
        popScope();
    }
}

void TypeAndScopeScanner::enterStatement(PlayScriptParser::StatementContext *ctx) 
{
    // 为for建立额外的Scope
    if (ctx->FOR() != NULL) {
        BlockScope *scope = new BlockScope(currentScope(), ctx);
        currentScope()->addSymbol(scope);
        pushScope(scope, ctx);
    }
}

void TypeAndScopeScanner::exitStatement(PlayScriptParser::StatementContext *ctx) 
{
    //释放for语句的外层scope
    if (ctx->FOR() != NULL) {
        popScope();
    }
}

void TypeAndScopeScanner::enterFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx)  
{
    std::string idName = ctx->IDENTIFIER()->getText();

    // 注意：目前function信息并不完整，参数要等到Typesolver中去确定
    Function *function = new Function(idName, currentScope(), ctx);

    at->types.push_back(function);

    currentScope()->addSymbol(function);
    
    // 创建一个新的scope
    pushScope(function, ctx);
}

void TypeAndScopeScanner::exitFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx) 
{
    popScope();
}

void TypeAndScopeScanner::enterClassDeclaration(PlayScriptParser::ClassDeclarationContext *ctx)
{
    // 把类的签名存到符号表中，不能跟已有符号名称冲突
    std::string idName = ctx->IDENTIFIER()->getText();

    Class *theClass = new Class(idName, ctx);
    at->types.push_back(theClass);
}

void TypeAndScopeScanner::exitClassDeclaration(PlayScriptParser::ClassDeclarationContext *ctx)
{

}