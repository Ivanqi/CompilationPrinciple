#ifndef SUPER_H
#define SUPER_H

#pragma once
#include "Variable.h"
#include "Scope.h"
#include "ParserRuleContext.h"
using namespace antlr4;

namespace play 
{
    // 用来表示this关键字的符号
    class Super: public Variable
    {
        public:
            Super(Scope *theClass, ParserRuleContext *ctx): Variable(typeid(this).name(), theClass, ctx)
            {
            }

        private:
            Scope* Class()
            {
                return enclosingScope;
            }
    };
};

#endif