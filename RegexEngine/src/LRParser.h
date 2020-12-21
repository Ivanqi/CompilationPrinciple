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
class State;

class LRParser
{
    public:
        /**
         * 解析代码，生成AST
         */
        static ASTNode* parse(string script, GrammarNode *grammar);

    private:
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
        static GrammarNFAState* grammarToNFA(GrammarNode *grammar, vector<GrammarNode*>& allNodes);

        /**
         * 为每个GrammarNode中的命名节点生成一个或多个产生式
         * 比如, add -> add + mul | mul 会被拆成两个产生式：add->add + mul，以及 add->mul
         * 
         * 但右边存在未被充分拆解，比如: add -> add (+ | -) mul。其中的（+|-）还需要进一步拆解
         */
        static void generateProduction(map<string, GrammarNode*> nodes, set<Production*>& productions);

        /**
         * 把产生式右边的Or节点都展开，变成最简单的产生式
         * 比如 add -> add (+ | -) mul. 其中的 (+ | -) 还需要进一步拆解，变成两条
         *  add -> add + mul
         *  以及 add -> add - mul
         */
        static void simplifyProductions(map<string, GrammarNode*> nodes, set<Production*>& productions);

        /**
         * 为每个production产生一个子图
         * 子图中每个状态的Item的"."的位置依次后移
         * 比如:
         *  add -> .add + mul
         *  add -> add. + mul
         *  add -> add + .mul
         *  add -> add + mul.
         */
        static void calcSubGraphs(set<Production*> productions, map<Production*, GrammarNFAState*> subGraphs, vector<GrammarNFAState*> states);

        /**
         * 把各个子图通过Epsilon转换连接在一起
         * 比如:
         *  add -> add + .mul 可以建立两条连接，分别是
         *      mul -> .mul * pri
         *      以及 mul -> .pri
         *  
         */
        static void linkSubGraphs(map<Production*, GrammarNFAState*> subGraphs, vector<GrammarNFAState*> states);

        /**
         * 把NFA转换成DFA
         * 
         * @param startState 起始的NFA状态
         * @param grammarNames 所有符号的集合，包括终结符和非终结符
         */
        static vector<DFAState*> NFA2DFA(State *startState, vector<string> grammarNames, map<State*, set<State*>> closures);

        /**
         * 根据NFA State 集合，查找是否已经存在一个DFAState ，包含同样的NFA状态集合
         */
        static DFAState* findDFAState(vector<DFAState*> dfaStates, set<State*> states);

        /**
         * 比较两个NFA state 的集合是否相等
         */
        static bool sameStateSet(set<State*> stateSet1, set<State*> stateSet2);

        /**
         * 计算所有的节点的Closure
         */
        static map<State*, set<State*>> calcClosure(State *state);

        static bool calcClosure(State *state, map<State*, set<State*>> closures, set<State*> calculated);

        /**
         * 计算一个状态集合的闭包，包括这些状态以及可以通过epsilon到达的状态
         */
        static void addClosure(set<State*> states, map<State*, set<State*>> calculatedClosures);

        /**
         * 计算从某个状态集合，在接受某个字符以后，会迁移到哪些新的集合
         */
        static set<State*> move(set<State*> states, string grammarName);
};

#endif