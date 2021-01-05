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
    char tmp = obj.as<char>();
    return match(tmp);
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
        CharSet *charSet = condition;
        if (charSet->subSets.size() > 10) {
            charSet = charSet->getShorterForm();
        }
        return charSet->toString();
    }
}