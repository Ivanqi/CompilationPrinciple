#ifndef THIS_H
#define THIS_H

#pragma once
#include "Variable.h"
#include "Class.h"
#include "ParserRuleContext.h"
using namespace antlr4;

namespace play
{
    class Class;

    // 用来表示this 关键字的符号
    class This: public Variable
    {
        public:

            This(Class *theClass, ParserRuleContext *ctx)
            {
                Scope *tmp = dynamic_cast<Scope*>(theClass);
                // Variable("xxxx", tmp, ctx);
            }

        private:
            // Class* Class()
            // {
            //     return (Class*) enclosingScope;
            // }
    };
};

#endif