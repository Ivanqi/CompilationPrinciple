#include "BinaryOp.h"
#include "PrimitiveType.h"
#include "DyArray.h"
#include <stdio.h>
using namespace std;

antlrcpp::Any BinaryOp::vectorOp(antlrcpp::Any obj1, antlrcpp::Any obj2, PrimitiveType *targetType)
{

    antlrcpp::Any rtn = nullptr;

    DyArray<antlrcpp::Any> *list1 = new DyArray<antlrcpp::Any>();

    antlrcpp::Any data2 = nullptr;

    if (obj1.is<DyArray<antlrcpp::Any>*>()) {
        list1 = obj1.as<DyArray<antlrcpp::Any>*>();
        data2 = obj2;

    } else if (obj2.is<DyArray<antlrcpp::Any>*>()) {
        list1 = obj2.as<DyArray<antlrcpp::Any>*>();
        data2 = obj1;
    }

    if (list1->size() > 0) {
        DyArray<antlrcpp::Any> *v = new DyArray<antlrcpp::Any>();
        for (int i = 0; i < list1->size(); i++) {
            antlrcpp::Any o1 = list1->get(i);
            antlrcpp::Any o2 = data2;

            if (data2.is<DyArray<antlrcpp::Any>*>()) {
                DyArray<antlrcpp::Any> *tmp  = data2.as<DyArray<antlrcpp::Any>*>();
                o2 = tmp->get(i);
            }
            
            antlrcpp::Any value = op(o1, o2, targetType);
            v->push_back(value);
        }
        rtn = v;

    } else {
        rtn = op(obj1, obj2, targetType);
    }

    return rtn;
}