#include "Lexer.h"
#include "SampleGrammar.h"
#include "GrammarNode.h"
#include "Regex.h"
#include "CharSet.h"
#include "DFAState.h"
#include "Tokens.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void test_case_1() {
    GrammarNode *lexerGrammar = SampleGrammar::commonLexerGrammar();
    vector<State*> nfaStates = Regex::regexToNFA(lexerGrammar);
    vector<shared_ptr<DFAState>> dfaStates = Regex::NFA2DFA(nfaStates[0], CharSet::ascii);

    cout << "dump NFA:" << endl;
    // State::showState(nfaStates[0]);

    cout << "dump DFA:" << endl;
    // DFAState::showDFAState(dfaStates);
    cout << endl;

    string code = "int i = 0; i + 100; if (a == 10) println(a); a <= b;";
    vector<Tokens> tokens = Lexer::tokenize(code, dfaStates[0].get(), lexerGrammar);

    cout << "dump Tokens:" << endl;
    for (Tokens token : tokens){
        cout << token.toString() << endl;
    }

    // 销毁内存
    for (int i = 0; i < nfaStates.size(); i++) {
        State::deleteState(nfaStates[i]);
    }

    delete lexerGrammar;
}

int main() {

    test_case_1();
    return 0;
}

