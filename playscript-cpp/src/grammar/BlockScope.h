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
            BlockScope()
            {
                index = 1;
                this->name = "block" + std::to_string(index++);
            }

            BlockScope(Scope *enclosingScope, ParserRuleContext *ctx)
            {
                index = 1;
                this->name = "block" + std::to_string(index++);
                this->enclosingScope = enclosingScope;
                this->ctx = ctx;
            }

            std::string toString()
            {
                return "Block" + name;
            }
    };
};
#endif