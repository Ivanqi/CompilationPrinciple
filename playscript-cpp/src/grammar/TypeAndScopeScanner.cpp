#include "TypeAndScopeScanner.h"
#include "BlockScope.h"
#include "Class.h"
#include "NameSpace.h"
#include "Function.h"
#include "PrimitiveType.h"
using namespace play;


TypeAndScopeScanner::TypeAndScopeScanner(AnnotatedTree *at): at_(at)
{
}

// 在遍历树的过程中，当前的Scope
Scope* TypeAndScopeScanner::currentScope()
{
    if (scopeStack.size() > 0) {
        Scope* top = scopeStack.top();
        return top;
    } else {
        return nullptr;
    }
}

Scope* TypeAndScopeScanner::pushScope(Scope *scope, ParserRuleContext *ctx)
{
    at_->node2Scope[ctx] = scope;   // 关联 ctx 与 scope
    scope->setCtx(ctx);             // 设置scope 的 ctx

    scopeStack.push(scope);
    return scope;
}

void TypeAndScopeScanner::popScope() {
    scopeStack.pop();
}

// scope的根
void TypeAndScopeScanner::enterProg(PlayScriptParser::ProgContext *ctx)
{
    NameSpace *scope = new NameSpace("root", currentScope(), ctx);
    at_->namespaces = scope; // scope的根
    pushScope(scope, ctx);
}

void TypeAndScopeScanner::exitProg(PlayScriptParser::ProgContext *ctx)
{
    popScope();
}

// Block 节点
void TypeAndScopeScanner::enterBlock(PlayScriptParser::BlockContext *ctx) 
{
    // 对于函数，不需要再额外建一个scope
    // 这里之所以能够 父类 instanceof 子类。是因为ctx->parent本身实例化的是FunctionBodyContext。但是被转换成了ParseTree
    PlayScriptParser::FunctionBodyContext *tmp = dynamic_cast<PlayScriptParser::FunctionBodyContext*>(ctx->parent);
    if (tmp != nullptr) {
        BlockScope *scope = new BlockScope(currentScope(), ctx);
        currentScope()->addSymbol(scope);
        pushScope(scope, ctx);
    }
}

void TypeAndScopeScanner::exitBlock(PlayScriptParser::BlockContext *ctx)
{
    PlayScriptParser::FunctionBodyContext *tmp = dynamic_cast<PlayScriptParser::FunctionBodyContext*>(ctx->parent);
    if (tmp != nullptr) {
        popScope();
    }
}

// statement 节点
void TypeAndScopeScanner::enterStatement(PlayScriptParser::StatementContext *ctx) 
{
    // 为for建立额外的Scope
    if (ctx->FOR() != nullptr) {
        BlockScope *scope = new BlockScope(currentScope(), ctx);
        currentScope()->addSymbol(scope);
        pushScope(scope, ctx);
    }
}

void TypeAndScopeScanner::exitStatement(PlayScriptParser::StatementContext *ctx) 
{
    //释放for语句的外层scope
    if (ctx->FOR() != nullptr) {
        popScope();
    }
}

// FunctionDeclaration 节点
void TypeAndScopeScanner::enterFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx)  
{
    std::string idName = ctx->IDENTIFIER()->getText();
    // 注意：目前function信息并不完整，参数要等到Typesolver中去确定
    Function *function = new Function(idName, currentScope(), ctx);

    at_->types.push_back(function);
    currentScope()->addSymbol(function);
    
    // 创建一个新的scope
    pushScope(function, ctx);
}

void TypeAndScopeScanner::exitFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx) 
{
    popScope();
}

// ClassDeclaration 节点
void TypeAndScopeScanner::enterClassDeclaration(PlayScriptParser::ClassDeclarationContext *ctx)
{
    // 把类的签名存到符号表中，不能跟已有符号名称冲突
    std::string idName = ctx->IDENTIFIER()->getText();

    Class *theClass = new Class(idName, ctx);
    at_->types.push_back(theClass);

    if (at_->lookupClass(currentScope(), idName) != nullptr) {
        at_->log("duplicate class name: " + idName, ctx);   // 只是报警，但仍然可以解析
    }
    currentScope()->addSymbol(theClass);

    // 创建一个新的scope
    pushScope(theClass, ctx);
}

void TypeAndScopeScanner::exitClassDeclaration(PlayScriptParser::ClassDeclarationContext *ctx)
{
    popScope();   
}