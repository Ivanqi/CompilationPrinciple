#include "Regex.h"
#include "GrammarNode.h"
#include "State.h"
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
    vector<State> states = Regex::regexToNFA(rootNode);

    for (int i = 0; i < states.size(); i++) {
        cout << states[i].toString() << endl;
    }

    State::dump(states[0]);
    cout << endl;

    // 用NFA来匹配
    Regex::matchWithNFA(states[0], "int");
    // Regex::matchWithNFA(states[0], "intA");
    // Regex::matchWithNFA(states[0], "23");
    // Regex::matchWithNFA(states[0], "0A");

    delete rootNode;
}

int main() {

    test_case_1();
    return 0;
}