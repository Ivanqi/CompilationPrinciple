#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include <string>
#include <set>
using std::vector;
using std::string;
using std::set;

class DFAState;
class GrammarNode;
class Tokens;
/**
 * 一个词法分析器。可以根据正则表达式做词法分析
 * 原理
 *  1. 把正则表达式转换成NFA, 再转成DFA
 *  2. 要在NFA的State上标记管理的GrammarNode,以便区分被DFA识别出来的是那种感觉Token。这在Regex的regexToNFA中已经做了
 */
class Lexer
{
    public:
        /**
         * 把字符串解析成Token列表
         */
        static vector<Tokens*> tokenize(string str);

        /**
         * 逻辑
         *  1. 知道能消化接下来的字符的NFA
         *  2. 针对这个DFA一直给它发字符，直到不能接受
         *  3. 查看是否处于结束状态
         */
        static vector<Tokens*> tokenize(string str, DFAState *startState, GrammarNode *root);

        /**
         * 检查DFAState中的各个NFAstate，看是否是某个词法规则的结束节点
         * 注意: 如果有符合两个词法规则，那么宣布顺序的先后算。比如关键字和标识符就会重叠
         */
        static GrammarNode* getGrammar(DFAState *state, GrammarNode *root);
};
#endif