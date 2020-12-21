#include "GrammarNode.h"
#include "CharSet.h"
#include "Any.h"

unique_ptr<GrammarNode> GrammarNode::EPSILON_ = unique_ptr<GrammarNode>(new GrammarNode(GrammarNodeType::Epsilon));

GrammarNode* GrammarNode::createChild(CharSet *charSet)
{
    GrammarNode *grammarNode = new GrammarNode(charSet);
    addChild(grammarNode);
    return grammarNode;
}

GrammarNode* GrammarNode::createChild(string name, CharSet *charSet)
{
    GrammarNode *grammarNode = new GrammarNode(name, charSet);
    addChild(grammarNode);
    return grammarNode;
}

GrammarNode* GrammarNode::createChild(GrammarNodeType type)
{
    GrammarNode *grammarNode = new GrammarNode(type);
    addChild(grammarNode);
    return grammarNode;
}

GrammarNode* GrammarNode::createChild(string name, GrammarNodeType type)
{
    GrammarNode *grammarNode = new GrammarNode(name, type);
    addChild(grammarNode);
    return grammarNode;
}

GrammarNode* GrammarNode::createChild(Tokens *tokens)
{
    GrammarNode *grammarNode = new GrammarNode(tokens);
    grammarNode->type = GrammarNodeType::Token;
    addChild(grammarNode);
    return grammarNode;
}

// 添加子节点，并创建缺省名称
void GrammarNode::addChild(GrammarNode *child)
{
    children.emplace_back(unique_ptr<GrammarNode>(child));
    if (child->name.length() <= 0) {
        child->name = "_" + to_string(child->type) + to_string(children.size());
        if (name.size() > 0) {
            child->name = name + child->name;
        }

        if (child->name[0] != '_') {
            child->name = "_" + child->name;
        }
    }
}

/**
 * 是否显式命名的子节点
 * 词法规则中的Token，语法规则中的非终结符，都有名称
 */
bool GrammarNode::isNamedNode()
{
    if (name.length() >= 1 && name[0] != '_') {
        return true;
    }

    return false;
}

/**
 * 子节点列表，只读
 */
vector<shared_ptr<GrammarNode>>& GrammarNode::getChildren()
{
    return children;
}

int GrammarNode::getChildCount()
{
    return children.size();
}

GrammarNode* GrammarNode::getChild(int index)
{
    return children[index].get();
}

// 节点类型
GrammarNodeType GrammarNode::getType()
{
    return type;
}

string GrammarNode::getName()
{
    return name;
}

string GrammarNode::getGrammarName()
{
    Tokens *t = tokens_.get();
    if (t != nullptr) {
        return t->getType();
    } else if (isNamedNode()) {
        return name;
    }

    return "";
}

bool GrammarNode::equals(Any obj)
{
    if (obj.equals(this)) return true;

    GrammarNode *node = obj.as<GrammarNode*>();

    // 类型相同
    if (node->type != type) {
        return false;
    }

    // 名称相同
    if (node->name == "") {
        if (node->name.length() > 0) {
            return false;
        }
    } else {
        if (node->name.compare(name) != 0) {
            return false;
        }
    }

    // 比较Token
    if (type == GrammarNodeType::Token) {
        Tokens *t = tokens_.get();
        return t->equals(node->tokens_.get());
    } else if (type == GrammarNodeType::Epsilon) {  // Epsilon
       return true; 
    } else if (type == GrammarNodeType::Char) { // 比较字符集合
        return charSet->equals(node->charSet);
    }

    // 子节点相同
    if (children.size() != node->children.size()) {
        return false;
    }

    for (int i = 0; i < getChildren().size(); i++) {
        if (!children[i].get()->equals(node->children[i].get())) {
            return false;
        }
    }

    return true;
}

// 以比较易读的方式显式
string GrammarNode::toString()
{
    if (type == GrammarNodeType::Epsilon) return "ε";

    string rtn;
    Tokens *t = tokens_.get();

    if (charSet != nullptr) {
        rtn = charSet->toString();
    } else if (t != nullptr) {
        if (t->getText().length() > 0) {
            rtn = "'" + t->getText() + "'";
        } else {
            rtn = t->getType();
        }
    } else if (name.length() > 0) {
        rtn = name;
    } else if (type >= 0) {
        rtn = to_string(type);
    } else {
        rtn = "GrammarNode";
    }

    if (minTimes_ != 1 || maxTimes_ != 1) {
        if (minTimes_ == 0 && maxTimes_ == -1) {
            rtn = rtn + "*";
        } else if (minTimes_ == 0 && maxTimes_ == 1) {
            rtn = rtn + "?";
        } else if (minTimes_ == 1 && maxTimes_ == -1) {
            rtn = rtn + "+";
        } else {
            rtn = rtn + "(" + to_string(minTimes_) + "," + to_string(maxTimes_) + ")";
        }
    }

    return rtn;
}

void GrammarNode::setRepeatTimes(int minTimes, int maxTimes)
{
    minTimes_ = minTimes;
    maxTimes_ = maxTimes;
}

/**
 * 以文本方式显示Node. 显示结果的格式与Antrl的文法格式相同
 * 对于命名的节点，要把它的子节点都显示出来
 * 比如: primary节点: primary:ID | INT_LITERAL | add
 */
string GrammarNode::getText()
{
    string delim;

    if (type == GrammarNodeType::And) {
        delim = " & ";
    } else if (type == GrammarNodeType::Or) {
        delim = " | ";
    }

    string sb;
    if (children.size() > 0) {
        for (int i = 0; i < children.size(); i++) {
            if (i > 0) {
                sb.append(delim);
            }

            GrammarNode *child = children[i].get();

            if (child->isNamedNode()) {
                sb.append(child->toString());
            } else {
                sb.append(child->getText());
            }
        }
    } else {
        sb.append(this->toString());
    }

    string rtn = sb;

    if (isNamedNode()) {
        rtn = wrapNamedNode(rtn);
    } else {
        if (type == GrammarNodeType::Or) {
            rtn = "(" + rtn + ")";
        }
    }

    return rtn;
}

string GrammarNode::wrapNamedNode(string str)
{
    if (name.size() > 0) {
        string header = name;
        if (name.length() <= 3) {
            header += "\t";
        }
        header += "\t: ";
        return header + str + " ;";
    }
    return str;
}

// 把当前节点及下级以树状结构打印出来
void GrammarNode::dump()
{
    set<GrammarNode*> dumpedNodes;
    bool isGraphs = isGraph(this, dumpedNodes);
    if (isGraphs) {
        dumpGraph(this, dumpedNodes);
    } else {
        dumpTree(this, "");
    }
}

/**
 * 打印正则表达式的树状结构
 * @param node
 * @param indent 缩进。每一级增加一个tab
 */
void GrammarNode::dumpTree(GrammarNode *node, string indent)
{
    if (node->isNamedNode()) {
        cout << indent << node->getText() << endl;
    } else {
        cout << indent << node->toString() << endl;
    }

    for (size_t i = 0; i < node->children.size(); i++) {
        GrammarNode *child = node->children[i].get();
        dumpTree(child, indent + "\t");
    }
}

/**
 * 打印图。因为存在循环引用，所有不能以树状的方式打印
 */
void GrammarNode::dumpGraph(GrammarNode *node, set<GrammarNode*> &dumpedNodes)
{
    if (node->isNamedNode()) {
        cout << node->getText() << endl;
    }

    dumpedNodes.insert(node);

    for (size_t i = 0; i < node->children.size(); i++) {
        GrammarNode *child = node->children[i].get();
        if (dumpedNodes.find(child) == dumpedNodes.end()) {
            dumpGraph(child, dumpedNodes);
        }
    }
}

/**
 * 以某节点作为起始节点，判读是树还是图
 */
bool GrammarNode::isGraph(GrammarNode *node, set<GrammarNode*> &scannedNodes)
{
    scannedNodes.insert(node);
    for (size_t i = 0; i < node->children.size(); i++) {
        GrammarNode *child = node->children[i].get();
        if (scannedNodes.find(child) != scannedNodes.end()) {
            return true;
        }
    }

    for (size_t i = 0; i < node->children.size(); i++) {
        GrammarNode *child = node->children[i].get();
        bool rtn = isGraph(child, scannedNodes);
        if (rtn) {
            return true;
        }
    }

    return false;
}

/**
 * 该节点是否是可空的，也就是能否返回Epsilon
 * 算法：
 *  1. 如果是Epsilon节点，或者是 * 或 ?,可空
 *  2. And节点：所有子节点都可空
 *  3. Or节点: 任意子节点可空
 *  4. 其他，不为空
 */
bool GrammarNode::isNullable()
{
    bool rtn = false;

    if (minTimes_ == 0 || type == GrammarNodeType::Epsilon) {
        return true;
    } else if (type == GrammarNodeType::And) {
        bool allNullable = true;
        for (size_t i = 0; i < children.size(); i++) {
            GrammarNode *child = children[i].get();
            // And 一个不为空，全部不为空
            if (!child->isNullable()) {
                allNullable = false;
                break;
            }
        }
        rtn = allNullable;
    } else if (type == GrammarNodeType::Or) {
        bool anyNullable = false;
        for (size_t i = 0; i < children.size(); i++) {
            GrammarNode *child = children[i].get();
            // Or 一个为空，全部为空
            if (child->isNullable()) {
                anyNullable = true;
                break;
            }
        }
        rtn = anyNullable;
    }
    return rtn;
}

/**
 * 获得以本节点为起始节点，能到达的所有语法节点
 */
shared_ptr<vector<GrammarNode*>> GrammarNode::getAllNodes()
{
    shared_ptr<vector<GrammarNode*>> allNodesPtr = make_shared<vector<GrammarNode*>>();
    getAllNodes(this, allNodesPtr.get());

    return allNodesPtr;
}

void GrammarNode::getAllNodes(GrammarNode *node, vector<GrammarNode*>* allNodes)
{
    allNodes->push_back(node);
    for (size_t i = 0; i < node->children.size(); i++) {
        GrammarNode *child = node->children[i].get();
        if (find(allNodes->begin(), allNodes->end(), child) == allNodes->end()) {
            getAllNodes(child, allNodes);
        }
    }
}

/**
 * 是否是叶子节点
 */
bool GrammarNode::isLeaf()
{
    return children.size() == 0;
}

/**
 * 是否代表一个Token
 */
bool GrammarNode::isToken()
{
    return tokens_.get() != nullptr;
}

CharSet* GrammarNode::getCharSet()
{
    return charSet;
}

int GrammarNode::getMinTimes()
{
    return minTimes_;
}

int GrammarNode::getMaxTimes()
{
    return maxTimes_;
}

unique_ptr<Tokens>& GrammarNode::getToken()
{
    return tokens_;
}

bool GrammarNode::isNeglect()
{
    return neglect;
}

void GrammarNode::setNeglect(bool neglect)
{
    neglect = neglect;
}