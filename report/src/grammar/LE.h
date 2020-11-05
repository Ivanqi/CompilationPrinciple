#ifndef LE_H
#define LE_H

#include "BinaryOp.h"

class LE: public BinaryOp
{
    antlrcpp::Any op(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType *targetType);
};

#endif