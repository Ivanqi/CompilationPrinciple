#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H
#include "ASTNode.h"
#include "Token.h"
using namespace Tokens;
using namespace ASTNodes;

class SimpleParser
{
    public:

        /**
         * 解析脚本
         * @param scrpt
         */
        ASTNode* parse(string script);

        /**
         * AST的根节点，解析入口
         */
        SimpleASTNode* prog(TokenReader *tokens);

        /**
         * 表达式语句，即表达式后面跟个分号
         */
        SimpleASTNode* expressionStatement(TokenReader *tokens);

        /**
         * 赋值语句，如 age = 10 * 2
         */
        SimpleASTNode* assignmentStatement(TokenReader *tokens);

        /**
         * 整型变量声明，如
         *  int a;
         *  int b = 2 * 3;
         */
        SimpleASTNode* intDeclare(TokenReader *tokens);

        /**
         * 加法表达式
         */
        SimpleASTNode* additive(TokenReader *tokens);

        /**
         * 乘法表达式
         */
        SimpleASTNode* multiplicative(TokenReader *tokens);

        /**
         * 基础表达式
         */
        SimpleASTNode* primary(TokenReader *tokens);

        /**
         * 打印输出AST的树状结构
         */
        void dumpAST(ASTNode *node, string indent);
};

#endif