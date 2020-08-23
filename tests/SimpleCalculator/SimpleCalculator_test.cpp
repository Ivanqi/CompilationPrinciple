#include "SimpleCalculator.h"
#include "SimpleLexer.h"
#include <exception>

void test_case_1() {

    SimpleCalculator *calculator = new SimpleCalculator();

    // 测试变量声明语句解析
    string script = "int a = b + 3;";
    cout << "解析变量声明语句：" + script << endl;

    SimpleLexer *lexer = new SimpleLexer();
    SimpleTokenReader *tokenReader = lexer->tokensize(script);

    lexer->dump(tokenReader);
    cout << " ------------------------ " << endl;

    try {
        SimpleASTNode *node = calculator->intDeclare(tokenReader);
        calculator->dumpAST(node, "");
    } catch (exception &e) {
        cout << "异常信息：" << e.what() << endl;
    }
}

// 测试表达式
void test_case_2() {

    SimpleCalculator *calculator = new SimpleCalculator();

    // 测试变量声明语句解析
    string script = "2+3*5;";
    cout << "计算: " + script << " 看上去一切正常. " << endl;
    calculator->evaluate(script);
}

// 测试语法错误
void test_case_3() {

    SimpleCalculator *calculator = new SimpleCalculator();
    string script = "2+";
    cout << script << ", 应该有语法错误。";
    calculator->evaluate(script);
}

// 测试语法错误
void test_case_4() {

    SimpleCalculator *calculator = new SimpleCalculator();
    string script = "2+3+4";
    cout << script << ", 结合性出现错误。";
    calculator->evaluate(script);
}

int main() {

    test_case_2();
    return 0;
}