#include "This.h"
using namespace play;
This::This(Scope *theClass, ParserRuleContext *ctx): Variable(typeid(this).name(), theClass, ctx)
{

}

Scope* This::Class()
{
    return enclosingScope;
}