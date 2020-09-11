#ifndef SYMBOL_H
#define SYMBOL_H
#pragma once
#include <string>
#include "ParserRuleContext.h"
using namespace antlr4;

namespace play
{
    class Scope;

    class Symbol
    {
        protected:
            // 符号的名称
            std::string name;

            // 所属于作用域
            Scope *enclosingScope;

            // 可见性，比如public还是private
            int visibility = 0;

        public:
            // Symbol 关联的AST节点
            ParserRuleContext *ctx;
        
        public:
            std::string getName();

            Scope* getEnclosingScope();

            void setEnclosingScope(Scope *sc);

            void setCtx(ParserRuleContext *x);
    };
};
#endif