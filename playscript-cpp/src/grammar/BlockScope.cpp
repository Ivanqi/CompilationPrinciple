#include "BlockScope.h"
using namespace play;

BlockScope::BlockScope()
{
    index = 1;
    this->name = "block " + std::to_string(index++);
}

BlockScope::BlockScope(Scope *enclosingScope, ParserRuleContext *ctx)
{
    index = 1;
    this->name = "block " + std::to_string(index++);
    this->enclosingScope = enclosingScope;
    this->ctx = ctx;
}

std::string BlockScope::toString()
{
    return "Block " + name;
}