#include "Regex.h"
#include "State.h"
#include "GrammarNode.h"
#include "DFAState.h"
#include "CharTransition.h"

#include <string.h>

/**
 * 把正则表达式翻译成NFA
 */
vector<shared_ptr<State>> Regex::regexToNFA(GrammarNode *node)
{
    State *beginState = nullptr;
    State *endState = nullptr;
    vector<shared_ptr<State>> lastChildState;
    vector<shared_ptr<State>> childState;

    switch (node->getType()) {
        // 转换 s|t
        case GrammarNodeType::Or:
            beginState = new State();
            endState = new State(true);

            for (size_t i = 0; i < node->getChildren().size(); i++) {
                // 递归，生成子图，返回头尾两个状态
                GrammarNode *child = node->getChildren()[i].get();
                childState = regexToNFA(child);

                // beginState，通过ε接到子图的开始状态
                beginState->addTransition(new CharTransition(), childState[0].get());

                // 子图的结束状态，通过ε接到endState
                childState[1].get()->addTransition(new CharTransition(), endState);
                childState[1].get()->setAcceptable(false);
            }
            break;

        // 转换 st
        case GrammarNodeType::And:
            for (int i = 0; i < node->getChildCount(); i++) {
                childState = regexToNFA(node->getChild(i)); // 生成子图
                if (lastChildState.size() > 0) {
                    // 把前一个子图的接受状态和后一个子图的开始状态合并，把两个子图接到一起
                    lastChildState[1].get()->copyTransitions(childState[0].get());
                    lastChildState[1].get()->setAcceptable(false);
                }

                lastChildState = childState;

                if (i == 0) {
                    beginState = childState[0].get(); // 整体的开始状态
                    endState = childState[1].get();
                } else {
                    endState = childState[1].get();   // 整体的接受状态
                }
            }
            break;
            
        // 处理普通的字符
        case GrammarNodeType::Char:
            beginState = new State();
            endState = new State(true);
            // 图的边上是当前节点的charSet,也就是导致迁移字符的集合，比如所有字母
            beginState->addTransition(new CharTransition(node->getCharSet()), endState);
            break;
    }

    vector<shared_ptr<State>> rtn;

    // 考虑重复的情况，增加必要的节点和边
    if (node->getMinTimes() != 1 || node->getMaxTimes() != 1) {
        rtn = addRepitition(beginState, endState, node);
    } else {
        rtn.emplace_back(shared_ptr<State>(beginState));
        rtn.emplace_back(shared_ptr<State>(endState));
    }

    // 为命了名的语法节点做标记，后面将用来设置Token类型
    if (node->getName().length() > 0) {
        rtn[1].get()->setGrammarNode(node);
    }
    return rtn;
}

/**
 * 支持 * ? +
 * 在两边增加额外的状态，并增加额外的连线
 */
vector<shared_ptr<State>> Regex::addRepitition(State *state1, State *state2, GrammarNode *node)
{
    State *beginState;
    State *endState;

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
    } else {    // 1次
        beginState = state1;
        endState = state2;
    }

    vector<shared_ptr<State>> rtn;
    rtn.emplace_back(shared_ptr<State>(beginState));
    rtn.emplace_back(shared_ptr<State>(endState));

    return rtn;
}

/**
 * 看看str是否符合NFA
 * 
 * @param state NFA的起始状态
 * @param str
 * @return
 */
bool Regex::matchWithNFA(State *state, string str)
{
    cout << "NFA matching: '" << str << "'" << endl;
    int index = matchWithNFA(state, str, 0);

    bool match = index == str.length();

    cout << "matched?: " << match << "\n";

    return match;
}

/**
 * 用NFA来匹配字符串
 * @param state 当前所在的状态
 * @param chars 要匹配的字符串，用数组表示
 * @param indexi1 当前匹配的字符开始的位置
 * @return 匹配后，新的index的位置。指向匹配成功的字符的下一个字符
 */
int Regex::matchWithNFA(State *state, string str, int index1)
{
    cout << "trying state : " << state->getName() << ", index = " << index1 << endl;

    int index2 = index1;

    for (Transition *transition: state->getTransitions()) {
        State *nextState = state->getState(transition);
        // epsilon转换
        if (transition->isEpsilon()) {
            index2 = matchWithNFA(nextState, str, index1);
            if (index2 == str.length()) {
                break;
            }
        } else if (transition->match(str[index1])) {  // 消化一个字符，指针前移
            index2++;   // 消耗掉一个字符

            if (index2 < str.length()) {
                index2 = matchWithNFA(nextState, str, index1 + 1);
            } else {
                /**
                 * 如果已经扫描完所有的字符
                 * 检查当前状态是否是接受状态，或者可以通过epsilon到达接受状态
                 * 如果状态机还没有到达接受状态，本次匹配失败
                 */
                if (acceptable(nextState)) {
                    break;
                } else {
                    index2 = -1;
                }
            }   
        }
    }

    return index2;
}

// bool Regex::matchWithDFA(DFAState *state, string str);

/**
 * 基于DFA做字符串匹配
 */
// bool Regex::matchWithDFA(DFAState *state, char *chars, int index);

/**
 * 查找单曲状态是不是一个接受状态，或者可以通过epsilon迁移到一个接受状态
 */
bool Regex::acceptable(State *state)
{
    if (state->isAcceptable()) {
        return true;
    }

    bool rtn = false;

    for (Transition *transition : state->getTransitions()) {
        if (transition->isEpsilon()) {
            State *nextState = state->getState(transition);
            if (nextState->isAcceptable()) {
                rtn = true;
                break;
            } else {
                rtn = acceptable(nextState);
                if (rtn) {
                    break;
                }
            }
        }
    }
    return rtn;
}

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

    // // int 关键字
    GrammarNode *intNode = node->createChild(GrammarNodeType::And);
    intNode->createChild(new CharSet('i'));
    intNode->createChild(new CharSet('n'));
    intNode->createChild(new CharSet('t'));

    // // 标识符
    GrammarNode *idNode = node->createChild(GrammarNodeType::And);
    GrammarNode *firstLetter = idNode->createChild(CharSet::letter.get());

    GrammarNode *letterOrDigit = idNode->createChild(CharSet::letterOrDigit.get());
    letterOrDigit->setRepeatTimes(0, -1);

    // // 数字字面量
    GrammarNode *literalNode = node->createChild(CharSet::digit.get());
    literalNode->setRepeatTimes(1, -1);

    return node;
}

/**
 * 正则表达式: a[a-zA-Z0-9]*bc
 */
// GrammarNode* Regex::sampleGrammar2()
// {

// }