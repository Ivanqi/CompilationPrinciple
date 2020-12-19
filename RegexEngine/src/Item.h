#ifndef ITEM_H
#define ITEM_H

#include <string>

#include "Production.h"

/**
 * 一个Item就是带有“.”的产生式
 * 我们用GrammarNode加上一个Position属性，来表示Item
 * Position的值，代表所期待的下一个子节点
 * 如果它的值是grammar的子节点数量，就意味着这个Grammar已经处理完了
 */
class Item
{
    public:
        // 该Item对应的产生式
        Production *production{nullptr};

        // 点符号的位置.取值从0到grammar.getChildCount
        int position{0};

        Item(Production *produ, int pos):production(produ), position(pos)
        {
            
        }

        // 返回点符号后面的语法名称
        std::string getNextGrammarName();

        // 点符号是否在Item的末尾
        bool atEnd();

        std::string toString();

};

#endif