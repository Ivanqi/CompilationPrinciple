#ifndef PRIMITIVETYPE_H
#define PRIMITIVETYPE_H
#pragma once

#include "Type.h"
#include <string>

namespace play
{
    class Scope;

    class PrimitiveType final: public Type
    {
        private:
            std::string name_;

        public:
            // 把常见的基础数据类型都定义出来
            static PrimitiveType* Integer;
            static PrimitiveType* Long;
            static PrimitiveType* Float;
            static PrimitiveType* Double;
            static PrimitiveType* Boolean;
            static PrimitiveType* Byte;
            static PrimitiveType* Char;
            static PrimitiveType* Short;
            

            //增加String为基础类型
            static PrimitiveType* String;

            static PrimitiveType* Null;


        public:
            std::string getName()
            {
                return name_;
            }

            Scope* getEnclosingScope()
            {
                return NULL;
            }

            std::string toString()
            {
                return name_;
            }

            bool isType(Type *type);

            PrimitiveType(std::string name):name_(name)
            {
            }

            // 计算两个类型中比较“高”的一级，比如int和long相加，要取long
            static PrimitiveType* getUpperType(Type *type1, Type *type2);

            // 某个类型是不是数值型的（以便进行数值型运算）
            static bool isNumeric(Type *type);
    };
};
#endif