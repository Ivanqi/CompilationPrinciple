#include "Function.h"
#include "Variable.h"
#include "DefaultFunctionType.h"
#include "Class.h"
using namespace play;


Function::Function(std::string name, Scope *enclosingScope, ParserRuleContext *ctx)
{
    this->name = name;
    this->enclosingScope = enclosingScope;
    this->ctx = ctx;
}

std::string Function::getName()
{
    return name;
}

Type* Function::getReturnType()
{
    return returnType;
}

std::vector<Type*> Function::getParamTypes()
{
    for (Variable *param: parameters) {
        paramTypes.push_back(param->getType());
    }

    return paramTypes;
}

Scope* Function::getEnclosingScope()
{
    return enclosingScope;
}

std::string Function::toString()
{
    return "Function " + name;
}

bool Function::isType(Type *type)
{
    FunctionType *ft = dynamic_cast<FunctionType*>(type);
    if (ft != nullptr) {
        return DefaultFunctionType::isType(this, ft);
    }
    return false;
}

/**
 * 检查改函数是否匹配所需的参数
 */
bool Function::matchParameterTypes(std::vector<Type*> paramTypes)
{
    // 比较每个参数
    if (parameters.size() != paramTypes.size()) {
        return false;
    }

    bool match = true;

    for (int i = 0; i < paramTypes.size(); i++) {
        Variable *var = parameters[i];
        Type *type = paramTypes[i];
        Type *tmpType = var->getType();
        if (!tmpType || !tmpType->isType(type)) {
            match = false;
            break;
        }
    }

    return match;
}

/**
 * 该函数是不是类的方法
 */
bool Function::isMethod()
{
    Class *tmp = dynamic_cast<Class*>(enclosingScope);
    return (tmp != nullptr ? true : false);
}

/**
 * 该函数是不是类的构建函数
 */
bool Function::isConstructor()
{
    if (enclosingScope == nullptr) {
        return false;
    }
    
    Scope *tmp = dynamic_cast<Class*>(enclosingScope);
    if (tmp != nullptr) {
        return (enclosingScope->getName() == name);
    }
    return false;
}