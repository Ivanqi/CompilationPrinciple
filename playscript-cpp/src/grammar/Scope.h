#ifndef SCOPE_H
#define SCOPE_H
#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <Symbol.h>
// #include "FunctionType.h"
namespace play 
{
    class Variable;
    class Function;
    class Type;
    class Class;

    class Scope: public Symbol
    {
        public:
            // 该Scope 中的成员，包括变量，方法，类等
            std::vector<Symbol*> symbols;

            // 向scope中添加符号，同时设置好该符号的enclosingScope
            void addSymbol(Symbol *symbol);

            // 是否包含某个Variable
            Variable* getVariable(std::string name);

            static Variable* getVariable(Scope *scope, std::string name);

            virtual std::string toString();

            /**
             * 是否包含某个Function
             * @param name
             * @param paramTypes 参数类型。不允许为空，该参数不允许为空。如果没有参数，需要传入一个0长度的列表
             */
            Function* getFunction(std::string name, std::vector<Type*>paramTypes);
        
            /**
             * 是否包含某个Function。这是个静态方法，可以作为工具方法重用。避免类里要超找父类的情况
             */
            static Function* getFunction(Scope *scope, std::string name, std::vector<Type*> paramTypes);

            /**
             * 获取一个函数类型的变量，能匹配相应的参数类型
             */
            Variable* getFunctionVariable(std::string name, std::vector<Type*> paramTypes);

            static Variable* getFunctionVariable(Scope *scope, std::string name, std::vector<Type*> paramTypes);

            // 是否包含某个Class
            Class* getClass(std::string name);

            static Class* getClass(Scope *scope, std::string name);

            // 是否包含某个Symbol
            bool containsSymbol(Symbol *symbol);
    };
};
#endif