#ifndef ASTNODE_H
#define ASTNODE_H

#include <string>
#include <vector>
using std::string;
using std::vector;


class ASTNode
{
    private:
        // AST类型，也就是非终结符名称或Token的类型
        string type_;

        // 文本值
        string text_;

        // 子节点
        vector<ASTNode*> children_;

        // 父节点
        ASTNode* parent_{nullptr};
    
    public:
        // 常量，Epsilon 节点。某些语法会返回空节点
        static ASTNode* EpsilonNode;

        ASTNode(string type);

        ASTNode(string type, string text);

        string getType();

        string getText();

        vector<ASTNode*> children();

        int getChildCount();

        ASTNode* getChild(int index);

        ASTNode* parent();

        void setParent(ASTNode *node);

        bool isTerminal();

        /**
         * 添加子节点的时候，如果子节点不是命名节点，直接把它的下级节点加进来。这样简化了AST
         */
        void addChild(ASTNode *child);

        void setText(string text);

        /**
         * 是否是命名节点
         */
        bool isNamedNode();

        /**
         * 树状结构打印自身以及下级节点
         */
        void dump();

        /**
         * 树状结构打印AST
         */
        static void dump(ASTNode *node, string indent);
};

#endif