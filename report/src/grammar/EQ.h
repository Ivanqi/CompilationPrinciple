#ifndef EQ_H
#define EQ_H

#include "BinaryOp.h"

class EQ: public BinaryOp
{
    antlrcpp::Any op(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType targetType);
};

#endif