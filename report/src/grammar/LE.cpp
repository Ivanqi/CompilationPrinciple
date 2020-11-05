#include "LE.h"
#include "PrimitiveType.h"
#include <string.h>

antlrcpp::Any LE::op(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType *targetType)
{
    antlrcpp::Any rtn = nullptr;
    
    if (targetType == PrimitiveType::Integer) {
        rtn = obj1.as<int>() <= obj2.as<int>();

    } else if (targetType == PrimitiveType::Float) {
        rtn = obj1.as<float>() <= obj2.as<float>(); 

    } else if (targetType == PrimitiveType::Long) {
        rtn = obj1.as<long>() <= obj2.as<long>();
        
    } else if (targetType == PrimitiveType::Double) {
        rtn = obj1.as<double>() <= obj2.as<double>();

    } else if (targetType == PrimitiveType::Short) {
        rtn = obj1.as<short>() <= obj2.as<short>();
        
    }

    return rtn;
}