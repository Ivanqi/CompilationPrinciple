#pragma once
#include "Variable.h"
#include "Class.h"
#include "PlayScriptBaseVisitor.h"

// 用来表示this关键字的符号
class Super: public Variable
{
    public:
        Super(Class *theClass, PlayScriptParser::ExpressionContext *ctx): Variable(typeid(this).name(), theClass, ctx)
        {
        }

        
};