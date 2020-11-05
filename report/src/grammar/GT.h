#ifndef GT_H
#define GT_H

#include "BinaryOp.h"

class GT: public BinaryOp
{
    antlrcpp::Any op(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType *targetType);
};

#endif