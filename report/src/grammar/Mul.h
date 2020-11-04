#ifndef MUL_H
#define MUL_H

#include "BinaryOp.h"

class Mul: public BinaryOp
{
    antlrcpp::Any op(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType targetType);
};

#endif