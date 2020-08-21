#include <iostream>
#include <string>
#include "SimpleLexer.h"
using namespace std;

void test_case_1() {
    SimpleLexer *lexer = new SimpleLexer();
    string script = "int age = 45;";
    cout << "parse: " << script;

    SimpleTokenReader *tokenReader = lexer->tokensize(script);
    lexer->dump(tokenReader);
}

//测试inta的解析
void test_case_2() {
    SimpleLexer *lexer = new SimpleLexer();
    string script = "inta age = 45;";
    cout << "parse: " << script;

    SimpleTokenReader *tokenReader = lexer->tokensize(script);
    lexer->dump(tokenReader);
}

//测试in的解析
void test_case_3() {
    SimpleLexer *lexer = new SimpleLexer();
    string script = "in age = 45;";
    cout << "parse: " << script;

    SimpleTokenReader *tokenReader = lexer->tokensize(script);
    lexer->dump(tokenReader);
}

//测试>=的解析
void test_case_4() {
    SimpleLexer *lexer = new SimpleLexer();
    string script = "age >= 45;";
    cout << "parse: " << script;

    SimpleTokenReader *tokenReader = lexer->tokensize(script);
    lexer->dump(tokenReader);
}

//测试>的解析
void test_case_5() {
    SimpleLexer *lexer = new SimpleLexer();
    string script = "age > 45;";
    cout << "parse: " << script;

    SimpleTokenReader *tokenReader = lexer->tokensize(script);
    lexer->dump(tokenReader);
}

int main() {

    test_case_1();
    cout << endl << endl;
    test_case_2();

    cout << endl << endl;
    test_case_3();

    cout << endl << endl;
    test_case_4();

    cout << endl << endl;
    test_case_5();

    return 0;
}
