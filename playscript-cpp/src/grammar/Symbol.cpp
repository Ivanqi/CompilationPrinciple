#include "Symbol.h"
#include "Scope.h"

using namespace play;

std::string Symbol::getName()
{
    return name;
}

Scope* Symbol::getEnclosingScope()
{
    return enclosingScope;
}

void Symbol::setEnclosingScope(Scope *sc)
{
    enclosingScope = sc;
}

void Symbol::setCtx(ParserRuleContext *x)
{
    ctx = x;
}