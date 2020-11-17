#ifndef GRAMMARNODE_H
#define GRAMMARNODE_H
#include <vector>
#include <string>
#include <set>

// #include "CharSet.h"
// #include "Token.h"
using namespace std;

// 语法节点的类型
enum GrammarNodeType
{
    And,    // 并运算
    Or,     // 或运算
    Char,   // 字符，用于表达词法规则
    Token,  // 一个Token，用于表达语法规则
    Epsilon // 空集
};

class Token;
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
        vector<GrammarNode*> children;

        // 节点类型
        GrammarNodeType type;

        // 用于词法规则，指该节点能匹配的字符集合。其中Charset可以是一个树状集合，由多个子结合构成。比如: [a-z][A-Z][0-9]等
        CharSet *charSet = nullptr;

        // 改节点可以重复的次数
        int minTimes = 1;
        int maxTimes = 1;

        // 节点名称，可以作为Token名称或非终结符名称
        string name;

        // 语法规则中的Token,即终结符
        Token *token = nullptr;

        // 是否被词法处理器忽略，比如空白字符
        bool neglect = false;

        static GrammarNode *EPSILON;
    
    public:
        GrammarNode(GrammarNodeType type)
            :type(type)
        {

        }

        GrammarNode(string name, GrammarNodeType type, GrammarNode *child, Token *token)
            :name(name), type(type)
        {
            children.push_back(child);
            token = token;
        }

        GrammarNode(string name, GrammarNodeType type, vector<GrammarNode> child, Token *token)
            :name(name), type(type), token(token)
        {
            children.push_back(child);
        }

        GrammarNode(Token *token)
            :token(token)
        {

        }

        GrammarNode(CharSet *charSet)
            :charSet(charSet);
        {
            type = GrammarNodeType::Char;
        }

        GrammarNode(string name, CharSet *charSet)
            :name(name), charSet(charSet);
        {
            type = GrammarNodeType::Char;
        }

        GrammarNode* createChild(CharSet *charSet);

        GrammarNode* createChild(string name, CharSet *charSet);

        GrammarNode* createChild(GrammarNodeType type);

        GrammarNode* createChild(string name, GrammarNodeType type);

        GrammarNode* createChild(Token *token);

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
        vector<GrammarNode*> chaildren();

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
         * 以某节点作为起始节点，判读是树还是图
         */
        static bool isGraph(GrammarNode *node, set<GrammarNode*> scannedNodes);

        
};

#endif