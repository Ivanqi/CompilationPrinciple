#ifndef SCOPE_H
#define SCOPE_H
#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "Symbol.h"
// #include "Variable.h"
// #include "Function.h"
// #include "Class.h"

class Scope: public Symbol
{   
    public:
        // 该Scope 中的成员，包括变量，方法，类等
        std::vector<Symbol*> symbols;

        // 向scope中添加符号，同时设置好该符号的enclosingScope
        void addSymbol(Symbol *symbol)
        {
            symbols.push_back(symbol);
            // symbol->enclosingScope = this;
            symbol->setEnclosingScope(this);
        }

        // 是否包含某个Variable
        // Variable* getVariable(std::string name)
        // {
        //     return getVariable(this, name);
        // }

        // Variable* getVariable(Scope *scope, std::string name)
        // {
        //     for (Symbol *s: scope->symbols) {
        //         if (s->getName() == name) {
        //             return static_cast<Variable*> (s);
        //         }
        //     }
        //     return NULL;
        // }


        /**
         * 是否包含某个function
         * @param name
         * #param paramTypes 参数类型。不允许为空，该参数不允许为空。如果没有参数，需要传人一个0长度的列表
         */
        // static Variable* getVariable(Scope *scope, std::string name)
        // {
        //     for (Symbol *s : scope->symbols) {
        //         Variable *tmp = dynamic_cast<Variable*>(s);
        //         if (tmp != NULL && s->name == name) {
        //             return (Variable *)s;
        //         }
        //     }
        //     return NULL;
        // }

        virtual std::string toString()
        {
            return "Scope: " + name; 
        }

    protected:
        /**
         * 是否包含某个Function
         * @param name
         * @param paramTypes 参数类型。不允许为空，该参数不允许为空。如果没有参数，需要传入一个0长度的列表
         */
        // Function* getFunction(std::string name, std::vector<Type*>paramTypes)
        // {
        //     return getFunction(this, name, paramTypes);
        // }
    
        /**
         * 是否包含某个Function。这是个静态方法，可以作为工具方法重用。避免类里要超找父类的情况
         */
        // static Function* getFunction(Scope *scope, std::string name, std::vector<Type*> paramTypes)
        // {
        //     Function *rtn = NULL;
        //     for (Symbol *s: scope->symbols) {
        //         Function *func = dynamic_cast<Function*> (s);
        //         if (func != NULL && s->name == name) {
        //             rtn = func;
        //             break;
        //         }
        //     }
        //     return rtn;
        // }

        /**
         * 获取一个函数类型的变量，能匹配相应的参数类型
         */
        // Variable* getFunctionVariable(std::string name, std::vector<Type*> paramTypes)
        // {
        //     return getFunctionVariable(this, name, paramTypes);
        // }

        // static Variable* getFunctionVariable(Scope *scope, std::string name, std::vector<Type*> paramTypes)
        // {
        //     Variable *rtn = NULL;
        //     for (Symbol *s: scope->symbols) {
        //         Variable *tmp = dynamic_cast<Variable*>(s);
        //         FunctionType *tmp1 = dynamic_cast<FunctionType*>(tmp->getType());
        //         if (tmp != NULL && tmp1 != NULL && s->name == name) {
        //             Variable *v = (Variable *) s;
        //             FunctionType *functionType = tmp1;
        //             if (functionType->matchParameterTypes(paramTypes)) {
        //                 rtn = v;
        //                 break;
        //             }
        //         }
        //     }

        //     return rtn;
        // }

        // 是否包含某个Class
        // Class* getClass(std::string name)
        // {
        //     return getClass(this, name);
        // }

        // static Class* getClass(Scope *scope, std::string name)
        // {
        //     for (Symbol *s : scope->symbols) {
        //         Class *tmp = dynamic_cast<Class*>(s);
        //         if (tmp != NULL && s->name == name) {
        //             return (Class *) s;
        //         }
        //     }
        //     return NULL;
        // }

        // 是否包含某个Symbol
        // bool containsSymbol(Symbol *symbol)
        // {
        //     return (std::find(symbols.begin(), symbols.end(), symbol));
        // }
};
#endif