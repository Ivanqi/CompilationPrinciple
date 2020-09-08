#ifndef FUNCTIONTYPE_H
#define FUNCTIONTYPE_H
// #pragma once

#include <vector>
#include "Type.h"
namespace play
{
    class FunctionType: public Type
    {
        public:
            virtual Type* getReturnType() = 0;

            virtual std::vector<Type*> getParamTypes() = 0;

            virtual bool matchParameterTypes(std::vector<Type*> paramTypes) = 0;
    };
};
#endif