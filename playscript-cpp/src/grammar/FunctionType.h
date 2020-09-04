#pragma once

#include <vector>
#include "Type.h"

class FunctionType: public Type
{
    public:
        Type* getReturnType();

        std::vector<Type*> getParamTypes();

        bool matchParameterTypes(std::vector<Type> paramTypes);
};