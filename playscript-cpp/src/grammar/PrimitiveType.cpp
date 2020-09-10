#include "PrimitiveType.h"
#include "Scope.h"

using namespace play;

PrimitiveType* PrimitiveType::Integer = new PrimitiveType("Integer");
PrimitiveType* PrimitiveType::Long = new PrimitiveType("Long");
PrimitiveType* PrimitiveType::Float = new PrimitiveType("Float");
PrimitiveType* PrimitiveType::Double = new PrimitiveType("Double");
PrimitiveType* PrimitiveType::Boolean = new PrimitiveType("Boolean");
PrimitiveType* PrimitiveType::Byte = new PrimitiveType("Byte");
PrimitiveType* PrimitiveType::Char = new PrimitiveType("Char");
PrimitiveType* PrimitiveType::Short = new PrimitiveType("Short");
PrimitiveType* PrimitiveType::String = new PrimitiveType("String");
PrimitiveType* PrimitiveType::Null = new PrimitiveType("Null");

PrimitiveType* PrimitiveType::getUpperType(Type *type1, Type *type2)
{
    PrimitiveType *type;
    if (type1 == PrimitiveType::String || type2 == PrimitiveType::String) {
        type = PrimitiveType::String;
    } else if (type1 == PrimitiveType::Double || type2 == PrimitiveType::Double) {
        type = PrimitiveType::Double;
    } else if (type1 == PrimitiveType::Float || type2 == PrimitiveType::Float) {
        type = PrimitiveType::Float;
    } else if (type1 == PrimitiveType::Long || type2 == PrimitiveType::Long) {
        type = PrimitiveType::Long;
    } else if (type1 == PrimitiveType::Integer || type2 == PrimitiveType::Integer) {
        type = PrimitiveType::Integer;
    } else if (type1 == PrimitiveType::Short || type2 == PrimitiveType::Short) {
        type = PrimitiveType::Short;
    } else {
        type = PrimitiveType::Byte;
    }

    return type;
}

// 某个类型是不是数值型的（以便进行数值型运算）
bool PrimitiveType::isNumeric(Type *type)
{
    if (type == PrimitiveType::Byte || type ==  PrimitiveType::Short || type ==  PrimitiveType::Integer 
        || type == PrimitiveType::Long || type ==  PrimitiveType::Float || type ==  PrimitiveType::Double) {
        return true;
    } else {
        return false;
    }
}