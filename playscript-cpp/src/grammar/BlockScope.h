#ifndef BLOCKSCOPE_H
#define BLOCKSCOPE_H
#pragma once
#include <string>
#include "Scope.h"
#include "PlayScriptBaseVisitor.h"
#include "ParserRuleContext.h"
using namespace antlr4;

namespace play
{
    class BlockScope: public Scope
    {
        private:
            int index;

        public:
            BlockScope();

            BlockScope(Scope *enclosingScope, ParserRuleContext *ctx);

            std::string toString();
    };
};
#endif