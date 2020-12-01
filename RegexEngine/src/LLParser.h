#ifndef LLPARSER_H
#define LLPARSER_H

/**
 * LL算法实现的语法解析器
 *  包括
 *      1. 计算First集合
 *      2. 计算Follow集合
 *      3. 通过递归下降算法，使用First和Follow集合实现带有预测能力的语法分析
 * 
 * 另外，里面计算First和Follow集合，都是基于GrammarNode来做的。有可能代码有点长，看起来费力
 * 特别是计算Follow集合的时候，要考虑如何计算产生式中最后一个元素的后面跟着的是谁
 * 
 * 如果不基于GrammarNode的结构，先转化成简单的产生式再计算，应该会简单一些
 */
#include <string>
#include <set>
#include <map>
using std::string;
using std::set;
using std::map;

class ASTNode;
class GrammarNode;
class TokenReader;

class LLParser
{
    public:
        /**
         * 解析代码, 生成AST
         * @param script
         * @grammar 所使用的语法的入口结点
         */
        static ASTNode* parse(string script, GrammarNode* grammar);

        /**
         * 计算First集合
         * 采用了不动点法
         */
        static map<GrammarNode*, set<string>> caclFirstSets(GrammarNode* grammar);

        /**
         * 对First集合做一次计算
         * @param grammar
         * @param firstSets
         * @return 如果这次计算，First集合的成员都没有变动，则返回true
         */
        static bool caclFirstSets(GrammarNode* grammar, map<GrammarNode*, set<string>> firstSets, set<GrammarNode*> calculated);

        /**
         * 计算Follow集合
         * 对所有节点计算
         * @param grammar 入口语法节点
         * @return
         */
        static map<GrammarNode*, set<string>> caclFollowSets(GrammarNode *grammar, map<GrammarNode*, set<string>> firstSets);

        /**
         * 计算一遍Follow节点
         */
        static bool caclFollowSets(GrammarNode *grammar, map<GrammarNode*, set<string>> followSets, 
                                    map<GrammarNode*, set<string>> rightChildrenSets,
                                    map<GrammarNode*, set<string>> firstSets,
                                    set<GrammarNode> calculated);

    private:
        /**
         * 把某个节点的Follow集合，也给它所有右边分支的后代节点
         */
        static bool addToRightChild(GrammarNode *grammar, set<string> followSet, 
                                    map<GrammarNode*, set<string>> followSets, map<GrammarNode*, set<GrammarNode*>> rightChildrenSets,
                                    set<GrammarNode*> added);

        /**
         * 语法分析
         * 匹配一个语法规则，生成一个AST节点
         */
        static ASTNode* match(GrammarNode* grammar, TokenReader *tokenReader, map<GrammarNode*, set<string>> firstSets,
                             map<GrammarNode*, set<string>> followSets);

        // 打印输出First或Follow集合
        static void dumpFirstFollowSets(map<GrammarNode*, set<string>> sets);
};


#endif