#include "Regex.h"
#include "GrammarNode.h"
#include "State.h"
#include "CharSet.h"
#include "DFAState.h"

#include <iostream>
#include <vector>
using namespace std;

/**
 * 第一个例子
 * 正则表达式：int|[a-zA-Z][a-zA-Z0-9]*|[0-9]+
 * 也就是：int关键字、标识符或数字字面量
 */
void test_case_1() {
    GrammarNode *rootNode = Regex::sampleGrammar1();
    rootNode->dump();


    cout << "\nNFA states:" << endl;
    vector<State*> states = Regex::regexToNFA(rootNode);

    State::showState(states[0]);
    cout << endl;

    // 用NFA来匹配
    Regex::matchWithNFA(states[0], "int");
    Regex::matchWithNFA(states[0], "intA");
    Regex::matchWithNFA(states[0], "23");
    Regex::matchWithNFA(states[0], "0A");

    // 转换成DFA
    cout << "\nNFA to DFA:" << endl;
    vector<shared_ptr<DFAState>> dfaStates = Regex::NFA2DFA(states[0], CharSet::letterAndDigits);
    DFAState::showDFAState(dfaStates);
    cout << endl;

    //用DFA来匹配
    Regex::matchWithDFA(dfaStates[0].get(), "int");
    Regex::matchWithDFA(dfaStates[0].get(), "intA");
    Regex::matchWithDFA(dfaStates[0].get(), "23");
    Regex::matchWithDFA(dfaStates[0].get(), "0A");

    // 销毁内存
    for (int i = 0; i < states.size(); i++) {
        State::deleteState(states[i]);
    }
    delete rootNode;
}

/**
 * 第二个例子
 * 正则表达式: a[a-zA-Z0-9]*bc, 也就是以a开头，bc结尾，中间可以是任何字母或数字
 */
void test_case_2()
{
    GrammarNode *rootNode2 = Regex::sampleGrammar2();
    rootNode2->dump();

    cout << "\nNFA states:" << endl;
    vector<State*> states = Regex::regexToNFA(rootNode2);

    State::showState(states[0]);
    cout << endl;

    // 用NFA来匹配
    Regex::matchWithNFA(states[0], "abc");
    Regex::matchWithNFA(states[0], "abcbbbcbc");
    Regex::matchWithNFA(states[0], "abde");

    // 转换成DFA
    cout << "\nNFA to DFA:" << endl;
    vector<shared_ptr<DFAState>> dfaStates2 = Regex::NFA2DFA(states[0], CharSet::letterAndDigits);
    DFAState::showDFAState(dfaStates2);
    cout << endl;

     //用DFA来匹配
    Regex::matchWithDFA(dfaStates2[0].get(), "abc");
    Regex::matchWithDFA(dfaStates2[0].get(), "abcbbbcbc");
    Regex::matchWithDFA(dfaStates2[0].get(), "abcb");

    // 销毁内存
    for (int i = 0; i < states.size(); i++) {
        State::deleteState(states[i]);
    }
    delete rootNode2;
}

int main() {

    test_case_2();
    return 0;
}