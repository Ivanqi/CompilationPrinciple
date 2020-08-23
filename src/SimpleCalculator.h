#ifndef SIMPLECALCULATOR_H
#define SIMPLECALCULATOR_H
#include "ASTNode.h"
#include "Token.h"
using namespace Tokens;
using namespace ASTNodes;
/**
 * 一个简单的AST节点的实现
 * 属性包括：类型，文本值，父节点，子节点
 */
class SimpleASTNode: public ASTNode
{
    public:
        SimpleASTNode *parent;
        vector<ASTNode*> children;
        ASTNodeType nodeType;
        string text;

        SimpleASTNode(ASTNodeType nodeType, string text): nodeType(nodeType), text(text)
        {

        }

        ASTNode* getParent()
        {
            return parent;
        }

        vector<ASTNode*> getChildren()
        {
            return children;
        }

        ASTNodeType getType()
        {
            return nodeType;
        }

        string getText()
        {
            return text;
        }

        void addChild(SimpleASTNode *child)
        {
            children.push_back(child);
            child->parent = this;
        }
};

class SimpleCalculator
{
    public:
        /**
         * 执行脚本，并打印输出AST和求值过程
         */
        void evaluate(string script);

        /**
         * 解析脚本，并返回根节点
         */
        ASTNode* parse(string code);

        /**
         * 对某个AST节点求值，并打印求值过程
         * @param node
         * @param indent 打印输出时的缩进量，用tab控制
         */
        int evaluate(ASTNode *node, string indent);

        /**
         * 语法解析: 根节点
         */
        SimpleASTNode* prog(TokenReader *tokens);

        /**
         * 整型变量声明语句，如:
         *  int a;
         *  int b = 2 * 3;
         */
        SimpleASTNode* intDeclare(TokenReader *tokens);

        /**
         * 语法解析：加法表达式
         */
        SimpleASTNode* additive(TokenReader *tokens);

        /**
         * 语法解析：乘法表达式
         */
        SimpleASTNode* multiplicative(TokenReader *tokens);

        /**
         * 语法解析：基础表达式
         */
        SimpleASTNode* primary(TokenReader *tokens);

        /**
         * 打印输出AST的树状结构
         */
        void dumpAST(ASTNode *node, string indent);
};

#endif