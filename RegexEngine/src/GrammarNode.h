#ifndef GRAMMARNODE_H
#define GRAMMARNODE_H
#include <vector>
using namespace std;

// 语法节点的类型
enum GrammarNodeType
{
    And,    // 并运算
    Or,     // 或运算
    Char,   // 字符，用于表达词法规则
    Token,  // 一个Token，用于表达语法规则
    Epsilon // 空集
};

/**
 * 能够表达EBNF的对象
 * 
 * 1. 每个 GrammarNode 可以有多个子节点
 * 2. 子节点之间可以是And关系，或Or关系，由type属性确定
 * 3. minTimes和maxTimes属性规定了该节点的重复次数。比如对于+号，minTimes = 1, maxTimes = -1, -1代表很多个
 * 4. 该节点可以有名称，也就是词法规则和语法规则中左边的部分，如果没有名称，系统会根据它的父节点的名称生成自己的缺省名称，并且以下划线开头。如_add_or_1
 */
class GrammarNode
{
    private:
        // 子节点
        vector<GrammarNode*> children;

        // 节点类型
        GrammarNodeType type;

        // 用于词法规则，指该节点能匹配的字符集合。其中Charset可以是一个树状集合，由多个子结合构成。比如: [a-z][A-Z][0-9]等
};

#endif