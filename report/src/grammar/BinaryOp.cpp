#include "BinaryOp.h"
#include "PrimitiveType.h"
#include <vector>
using namespace std;

antlrcpp::Any BinaryOp::vectorOp(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType *targetType)
{
    antlrcpp::Any rtn = nullptr;

    vector<antlrcpp::Any> list1;

    antlrcpp::Any data2 = nullptr;

    if (obj1.is<vector<antlrcpp::Any>>()) {
        list1 = obj1.as<vector<antlrcpp::Any>>();
        data2 = &obj2;

    } else if (obj2.is<vector<antlrcpp::Any>>()) {
        list1 = obj2.as<vector<antlrcpp::Any>>();
        data2 = &obj1;
    }

    if (list1.size() > 0) {
        vector<antlrcpp::Any> v;
        for (int i = 0; i < list1.size(); i++) {
            antlrcpp::Any o1 = &list1[i];
            antlrcpp::Any o2 = &data2;

            if (data2.is<vector<antlrcpp::Any>>()) {
                vector<antlrcpp::Any> tmp  = data2.as<vector<antlrcpp::Any>>();
                o2 = tmp[i];
            }
            antlrcpp::Any value = op(&o1, &o2, targetType);
            v.push_back(value);
        }
        rtn = v;

    } else {
        rtn = op(move(obj1), move(obj2), targetType);
    }

    return rtn;
}