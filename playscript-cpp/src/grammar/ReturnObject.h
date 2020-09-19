#ifndef RETURNOBJECT_H
#define RETURNOBJECT_H

#include "antlr4-runtime.h"
#include <string>

// 代表return语句的返回值
class ReturnObject
{
    public:
        antlrcpp::Any returnValue; // 真正的返回值

        ReturnObject(antlrcpp::Any value): returnValue(value)
        {
        }

        std::string toString()
        {
            return "ReturnObject";
        }
};

#endif