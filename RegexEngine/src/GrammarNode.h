#ifndef GRAMMARNODE_H
#define GRAMMARNODE_H
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <memory>

#include "Tokens.h"

using std::set;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;

// 语法节点的类型
enum GrammarNodeType
{
    And,    // 并运算
    Or,     // 或运算
    Char,   // 字符，用于表达词法规则
    Token,  // 一个Token，用于表达语法规则
    Epsilon // 空集
};

class CharSet;
class Any;

/**
 * 能够表达EBNF的对象
 * 
 * 1. 每个 GrammarNode 可以有多个子节点
 * 2. 子节点之间可以是And关系，或Or关系，由type属性确定
 * 3. minTimes和maxTimes属性规定了该节点的重复次数。比如对于+号，minTimes = 1, maxTimes = -1, -1代表很多个
 * 4. 该节点可以有名称，也就是词法规则和语法规则中左边的部分，如果没有名称，系统会根据它的父节点的名称生成自己的缺省名称，并且以下划线开头。如_add_or_1
 */
class GrammarNode
{
    private:
        // 子节点
        vector<shared_ptr<GrammarNode>> children;

        // 节点类型
        GrammarNodeType type;

        // 用于词法规则，指该节点能匹配的字符集合。其中Charset可以是一个树状集合，由多个子结合构成。比如: [a-z][A-Z][0-9]等
        CharSet *charSet{nullptr};

        // 改节点可以重复的次数
        int minTimes_{1};
        int maxTimes_{1};

        // 节点名称，可以作为Token名称或非终结符名称
        string name;

        // 语法规则中的Token,即终结符
        unique_ptr<Tokens> tokens_;

        // 是否被词法处理器忽略，比如空白字符
        bool neglect{nullptr};

        static unique_ptr<GrammarNode> EPSILON_;
    
    public:
        GrammarNode(GrammarNodeType type)
            :type(type)
        {

        }

        GrammarNode(string name, GrammarNodeType type)
            :name(name), type(type)
        {

        }


        GrammarNode(string name, GrammarNodeType type, GrammarNode *child, Tokens *tokens)
            :name(name), type(type)
        {
            children.push_back(unique_ptr<GrammarNode>(child));
            tokens_.reset(tokens);
        }

        GrammarNode(string name, GrammarNodeType type, vector<shared_ptr<GrammarNode>>& child, Tokens *tokens)
            :name(name), type(type)
        {
            children.insert(children.end(), child.begin(), child.end());
            tokens_.reset(tokens);
        }

        GrammarNode(Tokens *tokens)
        {
            tokens_.reset(tokens);
        }

        GrammarNode(CharSet *charSet)
            :charSet(charSet)
        {
            type = GrammarNodeType::Char;
        }

        GrammarNode(string name, CharSet *charSet)
            :name(name), charSet(charSet)
        {
            type = GrammarNodeType::Char;
        }

        GrammarNode* createChild(CharSet *charSet);

        GrammarNode* createChild(string name, CharSet *charSet);

        GrammarNode* createChild(GrammarNodeType type);

        GrammarNode* createChild(string name, GrammarNodeType type);

        GrammarNode* createChild(Tokens *tokens);

        // 添加子节点，并创建缺省名称
        void addChild(GrammarNode *child);

        /**
         * 是否显式命名的子节点
         * 词法规则中的Token，语法规则中的非终结符，都有名称
         */
        bool isNamedNode();

        /**
         * 子节点列表，只读
         */
        vector<shared_ptr<GrammarNode>>& getChildren();

        int getChildCount();

        GrammarNode* getChild(int index);

        // 节点类型
        GrammarNodeType getType();

        string getName();

        string getGrammarName();

        bool equals(Any obj);

        // 以比较易读的方式显式
        string toString();

        void setRepeatTimes(int minTimes, int maxTimes);

        /**
         * 以文本方式显示Node. 显示结果的格式与Antrl的文法格式相同
         * 对于命名的节点，要把它的子节点都显示出来
         * 比如: primary节点: primary:ID | INT_LITERAL | add
         */
        string getText();

        string wrapNamedNode(string str);

        // 把当前节点及下级以树状结构打印出来
        void dump();

        /**
         * 打印正则表达式的树状结构
         * @param node
         * @param indent 缩进。每一级增加一个tab
         */
        static void dumpTree(GrammarNode *node, string indent);

        /**
         * 打印图。因为存在循环引用，所有不能以树状的方式打印
         */
        static void dumpGraph(GrammarNode *node, set<GrammarNode*> &dumpedNodes);

        /**
         * 以某节点作为起始节点，判读是树还是图
         */
        static bool isGraph(GrammarNode *node, set<GrammarNode*> &scannedNodes);

        /**
         * 该节点是否是可空的，也就是能否返回Epsilon
         * 算法：
         *  1. 如果是Epsilon节点，或者是 * 或 ?,可空
         *  2. And节点：所有子节点都可空
         *  3. Or节点: 任意子节点可空
         *  4. 其他，不为空
         */
        bool isNullable();

        /**
         * 获得以本节点为起始节点，能到达的所有语法节点
         */
        vector<GrammarNode*>  getAllNodes();

        static void getAllNodes(GrammarNode *node, vector<GrammarNode*> allNodes);

        /**
         * 是否是叶子节点
         */
        bool isLeaf();

        /**
         * 是否代表一个Token
         */
        bool isToken();

        CharSet* getCharSet();

        int getMinTimes();

        int getMaxTimes();

        unique_ptr<Tokens>& getToken();

        bool isNeglect();

        void setNeglect(bool neglect);
};

#endif