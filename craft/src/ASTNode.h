#ifndef ASTNODE_H
#define ASTNODE_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;
namespace ASTNodes {
    /**
     * AST节点的类型
     */
    enum ASTNodeType {
        Program,            // 程序入口，根节点

        IntDeclaration,     // 整型变量声明
        ExpressionStmt,     // 表达式语句，即表达式后面跟个分号
        AssignmentStmt,     // 赋值语句

        Primary,            // 基础表达式
        Multiplicative,     // 乘法表达式
        Additive,           // 加法表达式

        Identifier,         // 标识符
        IntLiteral          // 整型字面量
    };

    /**
     * AST 的节点
     * 
     * 属性包括AST的类型，文本值，下级节点和父节点
     */
    class ASTNode
    {
        public:

            // 父节点
            virtual ASTNode* getParent() = 0;

            // 子节点
            virtual vector<ASTNode*> getChildren() = 0;

            // AST类型
            virtual ASTNodeType getType() = 0;

            // 文本值
            virtual string getText() = 0;
    };

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
};

#endif