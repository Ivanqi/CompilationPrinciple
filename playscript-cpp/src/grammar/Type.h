#ifndef TYPE_H
#define TYPE_H

#pragma once

#include "Scope.h"
#include <string>

class Type
{
    public:
        virtual std::string getName();

        virtual Scope* getEnclosingScope();

        /**
         * 本类型是不是is目标类型，也就是能否用来替换目标类型
         * 以面向对象为例，子类 is 父类。 子类可以出现在任何需要父类的地方
         */
        bool isType(Type *type);
};

#endif