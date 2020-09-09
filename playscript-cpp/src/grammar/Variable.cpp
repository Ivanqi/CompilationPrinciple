#include "Variable.h"
#include "Scope.h"
#include "Type.h"

using namespace play;

Variable::Variable(std::string name, Scope *enclosingScope, ParserRuleContext *ctx)
{
    this->name = name;
    this->enclosingScope = enclosingScope;
    this->ctx = ctx;
}

bool Variable::isClassMember()
{
    // Scope *sc = dynamic_cast<Scope*>(enclosingScope);
    // return (sc != NULL) ? true: false;
    return false;
}

std::string Variable::toString()
{
    return "Variable " + name + " -> ";
}

Type* Variable::getType()
{
    return type;
}

void Variable::setType(Type *t)
{
    type = t;
}