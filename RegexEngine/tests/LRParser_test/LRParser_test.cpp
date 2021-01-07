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

void test_case_2() {
    /**
     * 示例2
     *  带有加减乘除的语法，并且支持标识符
     *  NFA状态数：32，DFA状态数：17
     * 
     *  语法：
     *  expression	: add ;
     *  add		: mul | add ('+' | '-') mul ;
     *  mul		: pri | mul ('*' | '/') pri ;
     *  pri		: ID | INT_LITERAL | LPAREN expression RPAREN ;
     */
    string script2 = "a - 3 / (4 + 5)";
    LRParser::parse(script2, SampleGrammar::leftRecursiveExpressionGrammar());
}

void test_case_3() {
    /**
     * 示例3：
     *  更加完整的表达式语法
     *  NFA状态数：67，DFA状态数：33
     * 
     * 语法：
     *  expression	: assign ;
     *  assign	: equal | assign '=' equal ;
     *  equal	: rel | equal ('==' | '!=') rel ;
     *  rel		: add | rel ('>=' | '>' | '<=' | '<') add ;
     *  add		: mul | add ('+' | '-') mul ;
     *  mul		: pri | mul ('*' | '/') pri ;
     *  pri		: ID | INT_LITERAL | LPAREN expression RPAREN ;
     */
    string script3 = "a = 2 - 3 > (4 + 5)"; //带有赋值，比较等运算
    LRParser::parse(script3, SampleGrammar::fullLeftRecursiveExpressionGrammar());
}

int main() {

    test_case_2();
    return 0;
}