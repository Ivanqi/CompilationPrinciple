#include "Scope.h"
#include "Symbol.h"
#include "Variable.h"
#include "Function.h"
#include "Class.h"

using namespace play;

void Scope::addSymbol(Symbol *symbol)
{
    symbols.push_back(symbol);
    // symbol->enclosingScope = this;
    symbol->setEnclosingScope(this);
}

Variable* Scope::getVariable(std::string name)
{
    return getVariable(this, name);
}

Variable* Scope::getVariable(Scope *scope, std::string name)
{
    for (Symbol *s : scope->symbols) {
        if (dynamic_cast<Variable*>(s) != nullptr && s->getName() == name) {
            return dynamic_cast<Variable*>(s);
        }
    }
    return nullptr;
}

std::string Scope::toString()
{
    return "Scope: " + name; 
}

Class* Scope::getClass(std::string name)
{
    return getClass(this, name);
}


/**
 * 是否包含某个Function
 * @param name
 * @param paramTypes 参数类型。不允许为空，该参数不允许为空。如果没有参数，需要传入一个0长度的列表
 */
Function* Scope::getFunction(std::string name, std::vector<Type*>paramTypes)
{
    return getFunction(this, name, paramTypes);
}

/**
 * 是否包含某个Function。这是个静态方法，可以作为工具方法重用。避免类里要超找父类的情况
 */
Function* Scope::getFunction(Scope *scope, std::string name, std::vector<Type*> paramTypes)
{
    Function *rtn = nullptr;
    for (Symbol *s: scope->symbols) {
        Function *tmpFunc = dynamic_cast<Function*> (s);
        if (tmpFunc != nullptr && s->getName() == name) {
            if (tmpFunc->matchParameterTypes(paramTypes)) {
                rtn = tmpFunc;
                break;
            }
        }
    }
    return rtn;
}

/**
 * 获取一个函数类型的变量，能匹配相应的参数类型
 */
Variable* Scope::getFunctionVariable(std::string name, std::vector<Type*> paramTypes)
{
    return getFunctionVariable(this, name, paramTypes);
}

Variable* Scope::getFunctionVariable(Scope *scope, std::string name, std::vector<Type*> paramTypes)
{
    Variable *rtn = nullptr;
    for (Symbol *s: scope->symbols) {

        Variable *tmpVar = dynamic_cast<Variable*>(s);
        FunctionType *tmpFuncType = (tmpVar != nullptr) ? dynamic_cast<FunctionType*>(tmpVar->getType()) : nullptr;

        if (tmpVar != nullptr && tmpFuncType != nullptr && s->getName() == name) {
            Variable *v = tmpVar;
            FunctionType *functionType = tmpFuncType;
            if (functionType->matchParameterTypes(paramTypes)) {
                rtn = v;
                break;
            }
        }
    }

    return rtn;
}


Class* Scope::getClass(Scope *scope, std::string name)
{
    for (Symbol *s : scope->symbols) {
        if (dynamic_cast<Class*>(s) != nullptr && s->getName() == name) {
            return dynamic_cast<Class*>(s);
        }
    }
    return nullptr;
}

// 是否包含某个Symbol
bool Scope::containsSymbol(Symbol *symbol)
{
    int len = symbols.size();
    if (len <= 0) {
        return false;
    }

    // O(n)
    for (int i = 0; i < len; i++) {
        if (symbols[i] == symbol) {
            return true;
        }
    }
    return false;
}