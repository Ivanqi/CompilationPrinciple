#include "GrammarTransition.h"

/**
 * 是否满足迁移条件
 * 算法：输入的GrammarNode和迁移条件相等
 */
bool GrammarTransition::match(string grammarName)
{
    if (isEpsilon()) {
        return false;
    }

    return condition_ == grammarName;
}

bool GrammarTransition::match(Any obj)
{
    if (obj.is<string>()) {
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