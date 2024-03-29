#include "Class.h"
#include "This.h"
#include "Super.h"
#include "Function.h"
#include "DefaultConstructor.h"
using namespace play;

Class::Class(std::string name, ParserRuleContext *ctx): parentClass(nullptr), superRef(nullptr)
{
    this->name = name;
    this->ctx = ctx;

    thisRef = new This(this, ctx);
    thisRef->setType(this);
}

std::string Class::getName()
{
    return name;
}

Scope* Class::getEnclosingScope()
{
    return enclosingScope;
}

Class* Class::getParentClass()
{
    return parentClass;
}

void Class::setParentClass(Class* theClass)
{
    parentClass = theClass;

    // 其实superRef引用的也是自己
    superRef = new Super(parentClass, ctx);
    superRef->setType(parentClass);
}

This* Class::getThis()
{
    return thisRef;
}

Super* Class::getSuper()
{
    return superRef;
}

// 是否包含某个Variable， 包括自身及父类
Variable* Class::getVariable(std::string name)
{
    Variable *rtn = Scope::getVariable(name);

    if (rtn == nullptr && parentClass != nullptr) {
        rtn = parentClass->getVariable(name);   // TODO 是否要检查visibility
    }

    return rtn;
}

Class* Class::getClass(std::string name)
{
    Class *rtn = Scope::getClass(name);

    if (rtn == nullptr && parentClass != nullptr) {
        rtn = parentClass->getClass(name);
    }

    return rtn;
}

// 找到某个构造函数。不需要往父类去找，在本级找就行类
Function* Class::findConstructor(std::vector<Type*> paramTypes)
{
    Function *rtn = Scope::getFunction(name, paramTypes);   // TODO是否要检查 visibility
    return rtn;
}

/**
 * 在自身及父类中找到某个方法
 * @param name
 * @param paramTypes 参数类型列表。该参数不允许为空，如果没有参数，需要传入一个0长度的列表
 */
Function* Class::getFunction(std::string name, std::vector<Type*> paramTypes)
{
    // 在本级查找这个方法
    Function *rtn = Scope::getFunction(name, paramTypes);   // TODO是否要检查 visibility

    // 如果在本级找不到，那么递归的从父类中查找
    if (rtn == nullptr && parentClass != nullptr) {
        rtn = parentClass->getFunction(name, paramTypes);
    }

    return rtn;
}

Variable* Class::getFunctionVariable(std::string name, std::vector<Type*> paramTypes)
{
    Variable *rtn = Scope::getFunctionVariable(name, paramTypes);

    if (rtn == nullptr && parentClass != nullptr) {
        rtn = parentClass->getFunctionVariable(name, paramTypes);
    }

    return rtn;
}


// 是否包含某个Symbol.这时候要把父类的成员考虑进来
bool Class::containsSymbol(Symbol *symbol)
{
    // this 关键字
    if (symbol == thisRef || symbol == superRef) {
        return true;
    }

    bool rtn = false;
    rtn = std::count(symbols.begin(), symbols.end(), symbol);

    if (!rtn && parentClass != nullptr) {
        rtn = parentClass->containsSymbol(symbol);
    }
    return rtn;
}

// 当自身是目标类型的子类型的时候，返回true;
bool Class::isType(Type *type)
{
    if (this == type) { // shortcut
        return true;
    }

    Class *tmp = dynamic_cast<Class*>(type);
    if (tmp != nullptr) {
        return tmp->isAncestor(this);
    }
    return false;
}

/**
 * 本类型是不是另一个类型的祖先类型
 * @param theClass
 * @return
 */
bool Class::isAncestor(Class *theClass)
{
    if (theClass->getParentClass() != nullptr) {
        if (theClass->getParentClass() == this) {
            return true;
        } else {
            return isAncestor(theClass->getParentClass());
        }
    }
    return false;
}


DefaultConstructor* Class::defaultConstructor()
{
    if (defaultConstructor_ == nullptr) {
        defaultConstructor_ = new DefaultConstructor(this->name, this);
    }
    return defaultConstructor_;
}