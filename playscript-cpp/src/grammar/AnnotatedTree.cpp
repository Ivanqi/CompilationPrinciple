#include "AnnotatedTree.h"
#include "Token.h"
#include "Scope.h"
#include "Class.h"
#include "NameSpace.h"
#include "Function.h"
#include "CompilationLog.h"

#include <iostream>

using namespace play;

void AnnotatedTree::log(std::string message, int type, ParserRuleContext *ctx)
{
    CompilationLog log;
    log.ctx = ctx;
    log.message = message;
    log.line = ctx->getStart()->getLine();
    log.type = type;

    std::cout << log.toString() << std::endl;
}

void AnnotatedTree::log(std::string message, ParserRuleContext *ctx)
{
    log(message, CompilationLog::ERROR, ctx);
}

bool AnnotatedTree::hasCompilationError()
{
    for (CompilationLog log: logs) {
        if (log.type == CompilationLog::ERROR) {
            return true;
        }
    }
    return false;
}

// 通过名称查找Variable.逐级Scope查找
Variable* AnnotatedTree::lookupVariable(Scope *scope, std::string idName)
{
    Variable *rtn = scope->getVariable(idName);

    if (rtn == NULL && scope->getEnclosingScope() != NULL) {
        rtn = lookupVariable(scope->getEnclosingScope(), idName);
    }

    return rtn;
}

// 通过名称查找Class。逐级Scope查找。
Class* AnnotatedTree::lookupClass(Scope *scope, std::string idName)
{
    Class *rtn = scope->getClass(idName);

    if (rtn == NULL && scope->getEnclosingScope() != NULL) {
        rtn = lookupClass(scope->getEnclosingScope(), idName);
    }
    
    return rtn;
}

Type* AnnotatedTree::lookupType(std::string idName)
{
    Type *rtn;
    for (Type *type : types) {
        if (type->getName() == idName) {
            rtn = type;
            break;
        }
    }
    return rtn;
}

// 通过方法的名称和方法签名查找Function。逐级Scope查找。
Function* AnnotatedTree::lookupFunction(Scope *scope, std::string idName, std::vector<Type*> paramTypes)
{
    Function *rtn = scope->getFunction(idName, paramTypes);

    if (rtn == NULL && scope->getEnclosingScope() != NULL) {
        rtn = lookupFunction(scope->getEnclosingScope(), idName, paramTypes);
    }

    return rtn;
}

// 查找函数型变量，逐级查找
Variable* AnnotatedTree::lookupFunctionVariable(Scope *scope, std::string idName, std::vector<Type*> paramTypes)
{
    Variable *rtn = scope->getFunctionVariable(idName, paramTypes);

    if (rtn == NULL && scope->getEnclosingScope() != NULL) {
        rtn = lookupFunctionVariable(scope->getEnclosingScope(), idName, paramTypes);
    }

    return rtn;
}

Function* AnnotatedTree::lookupFunction(Scope *scope, std::string name)
{
    Function *rtn;

    Class *scopeTmp = dynamic_cast<Class*>(scope);
    if (scopeTmp != NULL) {
        rtn = getMethodOnlyByName(scopeTmp, name);
    } else {
        rtn = getFunctionOnlyByName(scope, name);
    }

    if (rtn == NULL && scope->getEnclosingScope() != NULL) {
        rtn = lookupFunction(scope->getEnclosingScope(), name);
    }

    return rtn;
}

Function* AnnotatedTree::getMethodOnlyByName(Class *theClass, std::string name)
{
    Function *rtn = getFunctionOnlyByName(theClass, name);

    if (rtn == NULL && theClass->getParentClass() != NULL) {
        rtn = getMethodOnlyByName(theClass->getParentClass(), name);
    }

    return rtn;
}

Function* AnnotatedTree::getFunctionOnlyByName(Scope *scope, std::string name)
{
    for (Symbol *s: scope->symbols) {
        Function *tmp = (Function*)s;
        if (tmp != NULL && s->getName() == name) {
            return tmp;
        }
    }
    return NULL;
}

 /**
 * 查找某节点所在的Scope
 * 算法：逐级查找父节点，找到一个对应着Scope的上级节点
 */
Scope* AnnotatedTree::enclosingScopeOfNode(ParserRuleContext *node)
{
    Scope *rtn;

    // ParserRuleContext *parent = node->getParent();
    return rtn;
}
