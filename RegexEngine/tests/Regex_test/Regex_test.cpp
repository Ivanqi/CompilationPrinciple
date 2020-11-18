#include "Regex.h"
#include "GrammarNode.h"
#include <iostream>
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
    State **states = regexToNFA(rootNode);
    states[0]->dump();
}

int main() {
    
    test_case_1();
    return 0;
}