#ifndef DEAUTLCONSTRUCTOR_H
#define DEAUTLCONSTRUCTOR_H

#pragma once
#include <string>
#include "Scope.h"
#include "Function.h"

namespace play 
{
    /**
     * 代表一个缺省的构造函数
     * 这不是在程序里声明的。因此没有对应的FunctionDeclarationContext
     */
    class DefaultConstructor: public Function
    {
        protected:
            DefaultConstructor(std::string name, Scope *theClass): Function(name, theClass, NULL)
            {

            }

        public:
            Scope* Class()
            {
                return enclosingScope;
            }
    };
};

#endif