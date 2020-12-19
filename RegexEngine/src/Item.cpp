#include "Item.h"

// 返回点符号后面的语法名称
std::string Item::getNextGrammarName()
{
    if (position < production->rhs.size()) {
        return production->rhs[position];
    }
    return "";
}

// 点符号是否在Item的末尾
bool Item::atEnd()
{
    return position == production->rhs.size();
}

std::string Item::toString()
{
    std::string sb;
    sb.append(production->lhs).append("->");
    for (int i = 0; i < production->rhs.size(); i++) {
        if (i == position) {
            sb.append(". ");
        }
        std::string tmp = production->rhs[i];
        sb.append(tmp).append(" ");
    }

    if (position == production->rhs.size()) {
        sb.append(".");
    }

    return sb;
}