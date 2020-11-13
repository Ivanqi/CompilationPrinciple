#include "Div.h"
#include "PrimitiveType.h"
#include <string.h>
#include <iostream>

antlrcpp::Any Div::op(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType *targetType)
{
    antlrcpp::Any rtn = nullptr;
    
    if (targetType == PrimitiveType::Integer) {
        rtn = obj1.as<int>() / obj2.as<int>();

    } else if (targetType == PrimitiveType::Float) {
        rtn = obj1.as<float>() / obj2.as<float>(); 

    } else if (targetType == PrimitiveType::Long) {
        rtn = obj1.as<long>() / obj2.as<long>();
        
    } else if (targetType == PrimitiveType::Double) {
        if (!obj1.is<double>()) {
            std::cout << "obj1 isn't double" << std::endl;
        } 

        if (!obj2.is<int>()) {
            std::cout << "obj2 isn't int" << std::endl;
        }
        rtn = obj1.as<double>() / obj2.as<double>();


    } else if (targetType == PrimitiveType::Short) {
        rtn = obj1.as<short>() / obj2.as<short>();
        
    }

    return rtn;
}