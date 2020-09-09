#include "Class.h"
#include "This.h"
#include "Super.h"
// #include "Function.h"
#include "DefaultConstructor.h"
using namespace play;

Class::Class(std::string, ParserRuleContext *ctx)
{
    this->name = name;
    this->ctx = ctx;

    thisRef = new This(this, ctx);
    thisRef->setType(this);

    rootClass = new Class("Object", NULL);
}

std::string Class::getName()
{
    return name;
}

Scope* Class::getEnclosingScope()
{
    return enclosingScope;
}

bool Class::isType(Type *type)
{
    // if (this == type) {
    //     return true;
    // }

    // Class *tmp = dynamic_cast<Class*>(type);
    // if (tmp != NULL) {
    //     return ((Class *)type)->isAncestor(this);
    // }
    return false;
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

    if (rtn == NULL && parentClass != NULL) {
        rtn = parentClass->getVariable(name);   // TODO 是否要检查visibility
    }

    return rtn;
}

Class* Class::getClass(std::string name)
{
    Class *rtn = Scope::getClass(name);

    if (rtn == NULL && parentClass != NULL) {
        rtn = parentClass->getClass(name);
    }

    return rtn;
}