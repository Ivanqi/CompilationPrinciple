#include "Regex.h"
#include "State.h"
#include "GrammarNode.h"
#include "DFAState.h"
#include "CharTransition.h"

using namespace std;

/**
 * 把正则表达式翻译成NFA
 */
State** Regex::regexToNFA(GrammarNode *node)
{
    State *beginState = nullptr;
    State *endState = nullptr;
    State **lastChildState = new State*[2];
    State **childState = nullptr;

    switch (node->getType()) {
        // 转换 s|t
        case GrammarNodeType::Or:
            beginState = new State();   // 新的开始状态
            endState = new State();     // 新的接受状态

            for (GrammarNode *child: node->getChildren()) {
                // 递归，生成子图，返回头尾两个状态
                State **childState = regexToNFA(child);

                // beginState，通过ε接到子图的开始状态
                beginState->addTransition(new CharTransition(), childState[0]);

                // 子图的结束状态，通过ε接到endState
                childState[1]->addTransition(new CharTransition(), endState);
                childState[1]->setAcceptable(false);
            }
            break;
        // 转换 st
        case GrammarNodeType::And:
            for (int i = 0; i < node->getChildCount(); i++) {
                State **childState = regexToNFA(node->getChild(i)); // 生成子图
                if (lastChildState != nullptr) {
                    // 把前一个子图的接受状态和后一个子图的开始状态合并，把两个子图接到一起
                    lastChildState[1]->copyTransitions(childState[0]);
                    lastChildState[1]->setAcceptable(false);
                }
                lastChildState = childState;

                if (i == 0) {
                    beginState = childState[0]; // 整体的开始状态
                    endState = childState[1];
                } else {
                    endState = childState[1];   // 整体的接受状态
                }
            }
            break;
        // 处理普通的字符
        case GrammarNodeType::Char:
            beginState = new State();
            endState = new State();

            // 图的边上是当前节点的charSet,也就是导致迁移字符的集合，比如所有字母
            beginState->addTransition(new CharTransition(node->getCharSet()), endState);
            break;
    }

    State **rtn = nullptr;

    // 考虑重复的情况，增加必要的节点和边
    if (node->getMinTimes() != 1 || node->getMaxTimes() != 1) {
        rtn = addRepitition(beginState, endState, node);
    } else {
        rtn = new State*[2];
        rtn[0] = beginState;
        rtn[1] = endState;
    }

    // 为命了名的语法节点做标记，后面将用来设置Token类型
    if (node->getName().length() > 0) {
        rtn[1]->setGrammarNode(node);
    }
    return rtn;
}

/**
 * 支持 * ? +
 * 在两边增加额外的状态，并增加额外的连线
 */
State** Regex::addRepitition(State *state1, State *state2, GrammarNode *node)
{
    State *beginState = nullptr;
    State *endState = nullptr;

    // 允许循环
    if (node->getMaxTimes() == -1 || node->getMaxTimes() > 1) {
        state2->addTransition(new CharTransition(node->getMaxTimes()), state1);
    }

    // 允许0次，这时候要再加上两个节点
    if (node->getMinTimes() == 0) {
        beginState = new State();
        endState = new State(true);

        beginState->addTransition(new CharTransition(), state1);
        state2->addTransition(new CharTransition(), endState);
        state2->setAcceptable(false);

        beginState->addTransition(new CharTransition(), endState);
    } else {
        beginState = state1;
        endState = state2;
    }

    State **rtn = new State*[2];
    rtn[0] = beginState;
    rtn[1] = endState;
    return rtn;
}

/**
 * 看看str是否符合NFA
 * 
 * @param state NFA的起始状态
 * @param str
 * @return
 */
// bool Regex::matchWithNFA(State *state, string str);

/**
 * 用NFA来匹配字符串
 * @param state 当前所在的状态
 * @param chars 要匹配的字符串，用数组表示
 * @param indexi 当前匹配的字符开始的位置
 * @return 匹配后，新的index的位置。指向匹配成功的字符的下一个字符
 */
// int Regex::matchWithNFA(State *state, char *chars, int index1);

// bool Regex::matchWithDFA(DFAState *state, string str);

/**
 * 基于DFA做字符串匹配
 */
// bool Regex::matchWithDFA(DFAState *state, char *chars, int index);

/**
 * 查找单曲状态是不是一个接受状态，或者可以通过epsilon迁移到一个接受状态
 */
// bool Regex::acceptable(State *state);

/**
 * 把NFA转换成
 */
// std::vecotr<DFAState*> Regex::NFA2DFA(State *startState, std::vecotr<char> alphabet);

/**
 * 根据NFA State集合，查找是否已经存在一个DFAState，包含同样的NFA状态
 */
// DFAState Regex::findDFAState(std::vector<DFAState*> dfaStates, std::set<State*> states);

/**
 * 比较两个NFA state的集合是否相等
 */
// bool Regex::matchWithDFAsmaeStateSet(std::set<State*>stateSet1, std::set<State*>stateSet2);

/**
 * 计算某个state通过epsilon能到达的所有State
 */
// std::set<State*> Regex::calcClosure(State *state, std::map<State*, std::set<State*>> calculatedClosures);

/**
 * 计算一个集合的闭包，包活这些状态以及可以通过epsilon到达的状态
 */
// void Regex::calcClosure(std::set<State*>states, std::map<State*, std::set<State*>> calculatedClosures)
// {

// }

/**
 * 计算从某个集合状态，在接受某个字符以后，会迁移到哪些新的集合
 */
// std::set<State*> Regex::move(std::set<State*> states, char ch)
// {

// }

/**
 * 创建一个示例用的正则表达式
 * int | [a-zA-z][a-zA-Z0-9]* | [0-9]*
 */
GrammarNode* Regex::sampleGrammar1()
{
    GrammarNode *node = new GrammarNode("regex1", GrammarNodeType::Or);

    // int 关键字
    GrammarNode *intNode = node->createChild(GrammarNodeType::And);
    intNode->createChild(new CharSet('i'));
    intNode->createChild(new CharSet('n'));
    intNode->createChild(new CharSet('t'));

    // 标识符
    GrammarNode *idNode = node->createChild(GrammarNodeType::And);
    GrammarNode *firstLetter = idNode->createChild(CharSet::letter);

    GrammarNode *letterOrDigit = idNode->createChild(CharSet::letterOrDigit);
    letterOrDigit->setRepeatTimes(0, -1);

    // 数字字面量
    GrammarNode *literalNode = node->createChild(CharSet::digit);
    literalNode->setRepeatTimes(1, -1);

    return node;
}

/**
 * 正则表达式: a[a-zA-Z0-9]*bc
 */
// GrammarNode* Regex::sampleGrammar2()
// {

// }