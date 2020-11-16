#include "Add.h"
#include "PrimitiveType.h"
#include "common.h"

antlrcpp::Any Add::op(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType *targetType)
{
    antlrcpp::Any rtn = nullptr;

    auto obj1V = Common::conversionType(obj1);
    auto obj2V = Common::conversionType(obj2);
    
    if (targetType == PrimitiveType::String) {
        rtn = obj1.as<std::string>() + obj2.as<std::string>();

    } else if (targetType == PrimitiveType::Integer) {
        int tmp1 = obj1V;
        int tmp2 = obj2V;
        rtn = obj1V + obj2V;

    } else if (targetType == PrimitiveType::Float) {
        float tmp1 = obj1V;
        float tmp2 = obj2V;
        rtn = tmp1 + tmp2; 

    } else if (targetType == PrimitiveType::Long) {
        long tmp1 = obj1V;
        long tmp2 = obj2V;
        rtn = tmp1 + tmp2; 
        
    } else if (targetType == PrimitiveType::Double) {
        double tmp1 = obj1V;
        double tmp2 = obj2V;
        rtn = tmp1 + tmp2;

    } else if (targetType == PrimitiveType::Short) {
        short tmp1 = obj1V;
        short tmp2 = obj2V;
        rtn = tmp1 + tmp2;
        
    }

    return rtn;
}