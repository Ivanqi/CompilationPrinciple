#include "BinaryOp.h"
#include "PrimitiveType.h"
#include <vector>

antlrcpp::Any BinaryOp::vectorOp(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType *targetType)
{
    antlrcpp::Any rtn = nullptr;

    std::vector<antlrcpp::Any> list1;

    antlrcpp::Any data2;

    if (obj1.is<std::vector<antlrcpp::Any>>()) {
        list1 = obj1.as<std::vector<antlrcpp::Any>>();
        data2 = obj2;

    } else if (obj2.is<std::vector<antlrcpp::Any>>()) {
        list1 = obj2.as<std::vector<antlrcpp::Any>>();
        data2 = obj2;
    }

    if (list1.size() > 0) {
        std::vector<antlrcpp::Any> vector;
        for (int i = 0; i < list1.size(); i++) {
            antlrcpp::Any o1 = list1[i];
            antlrcpp::Any o2 = data2;

            if (data2.is<std::vector<antlrcpp::Any>>()) {
                std::vector<antlrcpp::Any> tmp  = data2.as<std::vector<antlrcpp::Any>>();
                o2 = tmp[i];
            }
            antlrcpp::Any value = op(o1, o2, targetType);
            vector.push_back(value);
        }
        rtn = vector;

    } else {
        rtn = op(obj1, obj2, targetType);
    }

    return rtn;
}