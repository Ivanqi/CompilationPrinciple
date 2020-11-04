#ifndef LT_H
#define LT_H

#include "BinaryOp.h"

class LT: public BinaryOp
{
    antlrcpp::Any op(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType targetType);
};

#endif