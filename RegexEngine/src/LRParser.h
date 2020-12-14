#ifndef LRPARASER_H
#define LRPARASER_H

#include <string>
#include <stack>
#include <vector>
#include <map>
#include <set>
using std::string;
using std::stack;
using std::vector;
using std::map;
using std::set;

class ASTNode;
class GrammarNode;
class TokenReader;
class DFAState;
class Token;
class GrammarNFAState;
class Production;

class LRParser
{
    public:
        /**
         * 解析代码，生成AST
         */
        static ASTNode* parse(string script, GrammarNode *grammar);

        /**
         * 通过移进，规约算法，做语法解析
         */
        static ASTNode* shiftReduce(stack<ASTNode*> stack, TokenReader *tokenReader, DFAState *startState);

        /**
         * 基于栈和左边第一个Token,判断正确的句柄，并做规约操作
         * 成功的情况
         *  1. 可能做了多次reduce, 最后nextToken匹配了当前句柄
         *  2. 遇到了结尾$
         */
        static bool reduce(stack<ASTNode*> stack, Token *nextToken, DFAState *startState);

        /**
         * 把语法翻译成NFA
         */
        static GrammarNFAState* grammarToNFA(GrammarNode *grammar, vector<GrammarNode*> allNodes);

        /**
         * 为每个GrammarNode中的命名节点生成一个或多个产生式
         * 比如, add -> add + mul | mul 会被拆成两个产生式：add->add + mul，以及 add->mul
         * 
         * 但右边存在未被充分拆解，比如: add -> add (+ | -) mul。其中的（+|-）还需要进一步拆解
         */
        static void generateProduction(map<string, GrammarNode*> nodes, set<Production*> productions);
};

#endif