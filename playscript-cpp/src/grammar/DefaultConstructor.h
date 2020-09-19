#ifndef DEAUTLCONSTRUCTOR_H
#define DEAUTLCONSTRUCTOR_H

#pragma once
#include <string>
#include "Function.h"
#include "Class.h"

namespace play 
{
    class Class;
    /**
     * 代表一个缺省的构造函数
     * 这不是在程序里声明的。因此没有对应的FunctionDeclarationContext
     */
    class DefaultConstructor: public Function
    {
        public:
            DefaultConstructor(std::string name, Class *theClass): Function(name, theClass, NULL)
            {

            }

            Class* Class()
            {
                return (play::Class*)enclosingScope;
            }
    };
};

#endif