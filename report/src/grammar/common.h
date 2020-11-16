#ifndef COMMON_H
#define COMMON_H
#include "antlr4-runtime.h"
#include <stdio.h>
class Common
{
    public:
        static auto conversionType(antlrcpp::Any obj)
        {
            auto ret = 0.0;

            if (obj.is<double>()) {
                double tmp = obj.as<double>();
                ret = tmp;
            } else if (obj.is<float>()) {
                float tmp = obj.as<float>();
                ret = tmp;
            } else if (obj.is<long>()) {
                long tmp = obj.as<long>();
                ret = tmp;
            } else if (obj.is<int>()) {
                int tmp = obj.as<int>();
                ret = tmp;
            } 
            return ret;
        }
};

#endif