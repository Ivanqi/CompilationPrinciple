#ifndef BINARYOP_H
#define BINARYOP_H
#include "antlr4-runtime.h"
#include "PrimitiveType.h"

class PrimitiveType;
class BinaryOp
{
    public:
        // 支持向量运算
        antlrcpp::Any vectorOp(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType *targetType);

        virtual antlrcpp::Any op(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType *targetType) = 0;

};

#endif