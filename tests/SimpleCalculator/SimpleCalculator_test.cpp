#include "SimpleCalculator.h"
#include "SimpleLexer.h"
#include <exception>

void test_case_1() {

    SimpleCalculator *calculator = new SimpleCalculator();

    // 测试变量声明语句解析
    string script = "int a = b + 3";
    cout << "解析变量声明语句：" + script << endl;

    SimpleLexer *lexer = new SimpleLexer();
    SimpleTokenReader *tokenReader = lexer->tokensize(script);

    try {
        SimpleASTNode *node = calculator->intDeclare(tokenReader);
        lexer->dump(tokenReader);
        cout << "-----" << endl;
        calculator->dumpAST(node, "");

    } catch (exception &e) {
        cout << "异常信息：" << e.what() << endl;
    }
}

int main() {

    test_case_1();
    return 0;
}