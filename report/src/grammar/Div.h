#ifndef DIV_H
#define DIV_H

#include "BinaryOp.h"

class Div: public BinaryOp
{
    antlrcpp::Any op(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType *targetType);
};

#endif