#ifndef REGEX_H
#define REGEX_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

#include "State.h"

using std::vector;
using std::map;
using std::set;

class State;
class GrammarNode;
class DFAState;

class Regex
{   
    public:

        /**
         * 把正则表达式翻译成NFA
         */
        static vector<State*> regexToNFA(GrammarNode *node);

        /**
         * 支持 * ? +
         * 在两边增加额外的状态，并增加额外的连线
         */
        static vector<State*> addRepitition(State *state1, State *state2, GrammarNode *node);
        
        /**
         * 看看str是否符合NFA
         * 
         * @param state NFA的起始状态
         * @param str
         * @return
         */
        static bool matchWithNFA(State *state, string str);

        /**
         * 用NFA来匹配字符串
         * @param state 当前所在的状态
         * @param chars 要匹配的字符串，用数组表示
         * @param indexi 当前匹配的字符开始的位置
         * @return 匹配后，新的index的位置。指向匹配成功的字符的下一个字符
         */
        static int matchWithNFA(State *state, string str, int index1);

        static bool matchWithDFA(DFAState *state, string str);

        /**
         * 基于DFA做字符串匹配
         */
        static bool matchWithDFA(DFAState *state, string str, int index);

        /**
         * 查找单曲状态是不是一个接受状态，或者可以通过epsilon迁移到一个接受状态
         */
        static bool acceptable(State *state);

        /**
         * 把NFA转换成
         */
        static vector<shared_ptr<DFAState>> NFA2DFA(State *startState, std::vector<char> alphabet);

        /**
         * 根据NFA State集合，查找是否已经存在一个DFAState，包含同样的NFA状态
         */
        static DFAState* findDFAState(vector<shared_ptr<DFAState>> dfaStates, vector<State*> states);

        /**
         * 比较两个NFA state的集合是否相等
         */
        static bool sameStateSet(vector<State*>stateSet1, vector<State*>stateSet2);

        /**
         * 计算某个state通过epsilon能到达的所有State
         */
        static vector<State*> calcClosure(State *state, std::map<State*, vector<State*>>& calculatedClosures);

        /**
         * 计算一个集合的闭包，包活这些状态以及可以通过epsilon到达的状态
         */
        static void calcClosure(vector<State*>& states, map<State*, vector<State*>>& calculatedClosures);

        /**
         * 计算从某个集合状态，在接受某个字符以后，会迁移到哪些新的集合
         */
        static vector<State*> move(vector<State*> states, char ch);

        /**
         * 创建一个示例用的正则表达式
         * int | [a-zA-z][a-zA-Z0-9]* | [0-9]*
         */
        static GrammarNode* sampleGrammar1();

        /**
         * 正则表达式: a[a-zA-Z0-9]*bc
         */
        static GrammarNode* sampleGrammar2();

};

#endif