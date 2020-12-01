#include "LLParser.h"
#include "SampleGrammar.h"

void test_case_1() {
    string script1 = "2+3*(4+5)";
    LLParser::parse(script1, SampleGrammar::statementGrammar());
}

int main() {

    test_case_1();
    return 0;
}