#ifndef COMMON_H
#define COMMON_H
#include "antlr4-runtime.h"
class Common
{
    public:
        static auto conversionType(antlrcpp::Any obj)
        {
            auto tmp = 0;

            if (obj.is<int>()) {
                tmp = obj.as<int>();
            } else if (obj.is<double>()) {
                tmp = obj.as<double>();
            } else if (obj.is<float>()) {
                tmp = obj.as<float>();
            } else if (obj.is<long>()) {
                tmp = obj.as<long>();
            }
            return tmp;
        }
};

#endif