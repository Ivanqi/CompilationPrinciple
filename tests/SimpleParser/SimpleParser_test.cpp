#include <iostream>
#include <exception>
#include "SimpleParser.h"
using namespace std;

void test_case_1(SimpleParser *parser) {

    try {
        string script = "int age = 45+2; age= 20; age+10*2;";
        cout << "解析：" << script << endl;
        ASTNode *tree = parser->parse(script);
        parser->dumpAST(tree, "");

    } catch(exception &e) {
       cout << e.what() << endl;
    }
}

// 测试异常语法
void test_case_2(SimpleParser *parser) {

    try {
        string script = "2+3+;";
        cout << "解析：" << script << endl;
        ASTNode *tree = parser->parse(script);
        // parser->dumpAST(tree, "");
    } catch (exception &e) {
        cout << e.what() << endl;
    }
}

// 测试异常语法
void test_case_3(SimpleParser *parser) {

    try {
        string script = "2+3*;";
        cout << "解析：" << script << endl;
        ASTNode *tree = parser->parse(script);
        parser->dumpAST(tree, "");
    } catch (exception &e) {
        cout << e.what() << endl;
    }
}

int main() {

    SimpleParser *parser = new SimpleParser();
    test_case_2(parser);
    return 0;
}