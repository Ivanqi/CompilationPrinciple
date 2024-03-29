#include "CharTransition.h"
#include <iostream>

/**
 * 是否满足迁移条件
 * 算法
 *  1. 如果没有任何conditions，那么就代表epsilon，就是可以迁移的
 *  2. 否则就要检测字符是否落在CharRange中
 */
bool CharTransition::match(char ch)
{
    if (isEpsilon()) {
        return false;
    }
    return condition->match(ch);
}

bool CharTransition::match(Any obj)
{
    bool ret = obj.is<char>();
    if (ret) {
        char tmp = obj.as<char>();
        return match(tmp);
    } else {
        return false;
    }
}

bool CharTransition::isEpsilon()
{
    return condition->isEmpty();
}

std::string CharTransition::toString()
{
    if (isEpsilon()){
        return "ε";
    } else {
        if (condition->subSets.size() > 10) {
            shared_ptr<CharSet> charSetTmp = condition->getShorterFormx();
            return charSetTmp->toString();
        } else {
            return condition->toString();
        }
    }
}