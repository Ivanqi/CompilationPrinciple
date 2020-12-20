#include "LRParser.h"
#include "SampleGrammar.h"

#include <string>
using namespace std;

void test_case_1() {
    /**
     * 示例1
     * 这个例子跟文稿中的例子完全一样。操作只有加法和乘法，没有减法和除法
     * 大家可以看看它打印出的NFA和DFA，跟文稿对照着理解
        语法：
        add		: mul | add '+' mul ;
        mul		: pri | mul '*' pri ;
        pri		: INT_LITERAL | LPAREN add RPAREN ;
     */
    string script1 = "2 + 3 * (4 + 5)";
    LRParser::parse(script1, SampleGrammar::simpleLeftRecursiveExpressionGrammar());
}

int main() {

    test_case_1();
    return 0;
}