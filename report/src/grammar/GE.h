#ifndef GE_H
#define GE_H

#include "BinaryOp.h"

class GE: public BinaryOp
{
    antlrcpp::Any op(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType targetType);
};

#endif