#include "Lexer.h"
#include "DFAState.h"
#include "GrammarNode.h"
#include "SampleGrammar.h"
#include "State.h"
#include "Regex.h"
#include "CharSet.h"
#include <assert.h>
#include <iostream>

/**
 * 把字符串解析成Token列表
 */
vector<Tokens> Lexer::tokenize(string str)
{
    GrammarNode *lexerGrammar = SampleGrammar::commonLexerGrammar();
    vector<State*> nfaStates = Regex::regexToNFA(lexerGrammar);
    vector<shared_ptr<DFAState>> dfaStates = Regex::NFA2DFA(nfaStates[0], CharSet::ascii);
    vector<Tokens> tokens = tokenize(str, dfaStates[0].get(), lexerGrammar);

    // 销毁内存
    for (int i = 0; i < nfaStates.size(); i++) {
        State::deleteState(nfaStates[i]);
    }

    delete lexerGrammar;

    // 加上结束符号
    tokens.push_back(Tokens::eof);
    return tokens;
}

/**
 * 逻辑
 *  1. 知道能消化接下来的字符的NFA
 *  2. 针对这个DFA一直给它发字符，直到不能接受
 *  3. 查看是否处于结束状态
 */
vector<Tokens> Lexer::tokenize(string str, DFAState *startState, GrammarNode *root)
{
    vector<Tokens> tokens;
    DFAState *currentState = startState;
    DFAState *nextState = nullptr;

    string tokenText;

    int strLen = str.length();
    int pos = 0;

    string ich;
    string nodeName;
    char ch;



    while (pos < strLen || tokenText.length() > 0) {    // 第二个条件，是为了生成最后一个Token
        ich = str[pos];
        ch = ich.c_str()[0];

        bool consumed = false;
        while (!consumed) {
            nextState = currentState->getNextState(ch);
            
            if (nextState == nullptr) {
                if (currentState == startState) {
                    // 不认识的字符
                    consumed = true;
                } else if (currentState->isAcceptable()) {
                    // 查找对应的词法规则
                    GrammarNode *grammar = getGrammar(currentState, root);
                    assert(grammar != nullptr);

                    // 创建Token
                    if (!grammar->isNeglect()) {    // 空白字符会被忽略
                        nodeName = grammar->getName();
                        Tokens token(nodeName, tokenText);
                        tokens.push_back(token);
                    }

                    tokenText.clear();

                    // 回到初始状态，重新匹配
                    currentState = startState;
                } else {
                    // 遇到不认识的字符，没有到达结束态，但也无法迁移
                    consumed = true;
                }
            } else {
                // 做状态迁移
                currentState = nextState;
                // 累积token的文本值
                tokenText.append(ich);
                consumed = true;
            }
        }

        pos++;
    }

    return tokens;
}

/**
 * 检查DFAState中的各个NFAstate，看是否是某个词法规则的结束节点
 * 注意: 如果有符合两个词法规则，那么宣布顺序的先后算。比如关键字和标识符就会重叠
 */
GrammarNode* Lexer::getGrammar(DFAState *state, GrammarNode *root)
{
    // 找出state符合的所有词法
    set<GrammarNode*> validGrammars;
    for (State *child : state->getStatesSet()) {
        if (child->getGrammarNode() != nullptr) {
            validGrammars.insert(child->getGrammarNode());
        }
    }

    // 按顺序遍历词法规则，声明在前的优先级更高
    GrammarNode *rtn = nullptr;
    for (int i = 0; i < root->getChildCount(); i++) {
        GrammarNode *grammar = root->getChild(i);
        if (grammar->getName().length() > 0) {
            if (validGrammars.find(grammar) != validGrammars.end()) {
                rtn = grammar;
                break;
            }
        }
    }
    return rtn;
}