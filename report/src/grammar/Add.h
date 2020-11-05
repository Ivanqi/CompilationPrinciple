#ifndef ADD_H
#define ADD_H

#include "BinaryOp.h"

class Add: public BinaryOp
{
    antlrcpp::Any op(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType *targetType);
};

#endif