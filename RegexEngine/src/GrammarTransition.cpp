#include "GrammarTransition.h"
#include <iostream>

/**
 * 是否满足迁移条件
 * 算法：输入的GrammarNode和迁移条件相等
 */
bool GrammarTransition::match(string grammarName)
{
    if (isEpsilon()) {
        return false;
    }
    bool ret = (condition_ == grammarName);
    if (ret == 1) {
        std::cout << "GrammarTransition::match: " << condition_ << " | " << grammarName << " | ret:" << ret << std::endl;
    }
    return ret;
}

bool GrammarTransition::match(Any obj)
{
    bool ret = obj.is<string>();
    std::cout << "bool GrammarTransition::match(Any obj): " << ret << std::endl;
    if (ret) {
        return match(obj.as<string>());
    } else {
        return false;
    }
}

bool GrammarTransition::isEpsilon()
{
    return (condition_.size() == 0);
}

string GrammarTransition::toString()
{
    if (isEpsilon()) {
        return "ε";
    } else {
        return condition_;
    }
}