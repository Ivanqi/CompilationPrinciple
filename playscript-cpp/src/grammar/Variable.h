#ifndef VARIABLE_H
#define VARIABLE_H
#pragma once

#include <string>
#include "Symbol.h"
#include "ParserRuleContext.h"
using namespace antlr4;

namespace play
{
    class Type;
    class Scope;

    class Variable: public Symbol
    {
        protected:
            // 变量类型
            Type *type;

            // 是否允许多次重复，这是一个创新的参数机制
            int multiplicity;

            // 作为parameter的变量的属性，缺省值
            void* defaultValue = NULL;
        
        public:
            Variable()
            {
            }

            Variable(std::string name, Scope *enclosingScope, ParserRuleContext *ctx);

            // 是不是类的属性
            bool isClassMember();

            std::string toString();

            Type* getType();

            void setType(Type *t);
    };
};
#endif
