#include "LLParser.h"
#include "SampleGrammar.h"
#include "GrammarNode.h"

void test_case_1() {
    string script1 = "2+3*(4+5)";
    GrammarNode* grammar = SampleGrammar::statementGrammar();

    LLParser::parse(script1, grammar);
}

void test_case_2() {
    string script2 = "int a = 0; a>3;";
    LLParser::parse(script2, SampleGrammar::statementGrammar());
}

void test_case_3() {
    string script3 = "int a = 0; if(a<3) a=3;";
    // LLParser::parse(script3, SampleGrammar::commonLexerGrammar());
}

int main() {

    test_case_1();
    return 0;
}