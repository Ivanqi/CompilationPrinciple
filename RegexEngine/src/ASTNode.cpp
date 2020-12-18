#include "ASTNode.h"

#include <iostream>
using std::cout;
using std::endl;

// 常量，Epsilon 节点。某些语法会返回空节点
ASTNode* ASTNode::EpsilonNode = new ASTNode("Epsilon");

ASTNode::ASTNode(string type): type_(type)
{
}

ASTNode::ASTNode(string type, string text): type_(type), text_(text)
{

}

string ASTNode::getType()
{
    return type_;
}

string ASTNode::getText()
{
    return text_;
}

vector<ASTNode*> ASTNode::children()
{
    return children_;
}

int ASTNode::getChildCount()
{
    return children_.size();
}

ASTNode* ASTNode::getChild(int index)
{
    return children_[index];
}

ASTNode* ASTNode::parent()
{
    return parent_;
}

bool ASTNode::isTerminal()
{
    return children_.size() == 0;
}

/**
 * 添加子节点的时候，如果子节点不是命名节点，直接把它的下级节点加进来。这样简化了AST
 */
void ASTNode::addChild(ASTNode *child)
{
    if (child->isNamedNode()) {
        children_.emplace_back(child);
        child->setParent(this); 
    } else {
        for (ASTNode *node : child->children()) {
            children_.emplace_back(node);
            node->setParent(this);
        }
    }
}

void ASTNode::setParent(ASTNode *node)
{
    parent_ = node;
}

void ASTNode::setText(string text)
{
    text_ = text;
}

/**
 * 是否是命名节点
 */
bool ASTNode::isNamedNode()
{
    if (type_.length() > 1 && type_[0] != '_') {
        return true;
    }
    return false;
}

/**
 * 树状结构打印自身以及下级节点
 */
void ASTNode::dump()
{
    dump(this, "");
}

/**
 * 树状结构打印AST
 */
void ASTNode::dump(ASTNode *node, string indent)
{
    string str = indent + node->getType();
    if (node->getText().size() > 0) {
        str += "(" + node->getText() + ")";
    }
    cout << str << endl;

    for (ASTNode *child : node->children()) {
        dump(child, indent + "\t");
    }
}