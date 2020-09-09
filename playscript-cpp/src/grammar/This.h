#ifndef THIS_H
#define THIS_H

#pragma once
#include "Variable.h"
#include "Scope.h"
#include "ParserRuleContext.h"
using namespace antlr4;

namespace play
{

    // 用来表示this 关键字的符号
    class This: public Variable
    {
        public:
            This()
            {
            }

            This(Scope *theClass, ParserRuleContext *ctx);

        private:
            Scope* Class();
    };
};

#endif