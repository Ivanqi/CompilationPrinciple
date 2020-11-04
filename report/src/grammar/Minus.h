#ifndef MINUS_H
#define MINUS_H

#include "BinaryOp.h"

class Minus: public BinaryOp
{
    antlrcpp::Any op(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType targetType);
};

#endif