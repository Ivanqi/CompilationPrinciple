#include "LRParser.h"
#include "ASTNode.h"
#include "GrammarNode.h"
#include "GrammarNFAState.h"
#include "Lexer.h"
#include "Tokens.h"
#include "TokenReader.h"
#include "Item.h"

#include <iostream>
#include <assert.h>

/**
 * 解析代码，生成AST
 */
ASTNode* ASTNode::parse(string script, GrammarNode *grammar)
{
    std::cout << "Grammar: " << std::endl;
    grammar->dump();

    // 转换成NFA
    vector<GrammarNode*> allNodes;
    GrammarNFAState *startNFAState = grammarToNFA(grammar, allNodes);
    std::cout << "\nNFA:" << std::endl;
    startNFAState->dump();

    // 取下所有的命名元素的名称，包括非终结符名称和终结符名称
    vector<string> grammarNames;
    vector<string> tokenNames;

    for (GrammarNode *node : allNodes) {
        string name = node->getGrammarName();
        if (name.length() > 0) {
            grammarNames.emplace_back(name);
            if (node->isToken()) {
                tokenNames.emplace_back(name);
            }
        }
    }

    // 计算所有NFA状态闭包
    map<State*, set<State*>> closures = calcClosure(startNFAState);

    // 把NFA转换成DFA
    vector<DFAState*> dfaStates = NFA2DFA(startNFAState, grammarNames, closures);
    std::cout << "\nDFA:" << std::endl;
    dfaStates[0]->dump();

    // TODO: 在这里可以检查语法是否合法，比如是否存在reduce/reduce或shift/reduce冲突

    // 词法分析
    vector<Tokens> tokens = Lexer::tokenize(script);
    TokenReader *tokenReader = new TokenReader(tokens);

    stack<ASTNode*> s1;
    // 语法分析
    ASTNode *rootNode = shiftReduce(s1, tokenReader, dfaStates[0]);
    std::cout << "\nAST:" << std::endl;
    rootNode->dump();

    return rootNode;
}

/**
 * 通过移进，规约算法，做语法解析
 */
ASTNode* ASTNode::shiftReduce(stack<ASTNode*> stack, TokenReader *tokenReader, DFAState *startState)
{
    Tokens token = tokenReader->peek();
    while (token.getType() != "nullptr") {
        bool reduced = false;

        // 尝试做移进操作，可能会做多次
        if (stack.size() > 0) {
            reduce = reduce(stack, token, startState);
        }

        // 尝试做移进操作
        token = tokenReader->read();
        if (token.getType() != Tokens::eof.getType()) {
            stack.push(new ASTNode(token.getType(), token.getText()));
        }

        if (!reduce && token.getType() == Tokens::eof.getType()) {
            std::cout << "expecting reduce action before EOF" << std::endl;
            break;
        }

        // 刷新token的值
        token = tokenReader->peek();
    }

    /**
     * 找到栈中剩下的元素，作为AST的根节点
     * 如果解析成功，栈里只会剩下一个节点，就是start节点
     */
    ASTNode *rootNode = nullptr;
    if (stack.size() == 1) {
        if (stack.top()->getType() == "start") {
            rootNode = stack.top();
        } else {
            std::cout << "error, expecting the start node as root node" << std::endl;
        }
    } else {
        std::cout << "error, expecting 1 node in stack" << std::endl;
    }

    return rootNode;
}

/**
 * 基于栈和左边第一个Token,判断正确的句柄，并做规约操作
 * 成功的情况
 *  1. 可能做了多次reduce, 最后nextToken匹配了当前句柄
 *  2. 遇到了结尾$
 */
bool ASTNode::reduce(stack<ASTNode*> stack, Token *nextToken, DFAState *startState)
{
    bool reduced = false;

    stack<ASTNode*> stackTmp = stack;

    // 在DFA中找到当前状态
    DFAState *currentState = startState;
    while (stackTmp.size() > 0) {
        string grammarName = stackTmp.top()->getType():
        currentState = currentState->getNextState(grammarName);
        assert(currentState != nullptr);
    }

    // 如果找不到下一个状态，那当前应该是start了
    if (currentState == nullptr) {
        return false;
    }

    /**
     * 在当前DFA的多个Item中，找到合适的句柄
     * 1. 首先看，哪个能支持继续Shift，而不是reduce
     * 比如: add -> add. + mul
     */
    if (nextToken != Tokens::eof) {
        for (State *state: currentState->getStates()) {
            Item *item = ((GrammarNFAState*) state)->item;
            string grammarName = item->getNextGrammarName();
            if (grammarName.size() > 0) {
                if (nextToken->getType() == grammarName) {
                    return false;
                }
            }
        }
    }

    // 2. 接下来，要找到一个Item来做Reduce
    // 条件: 找到.符号是在结尾的
    for (State *state: currentState->getStates()) {
        Item *item = ((GrammarNFAState*)state)->item;
        if (item->atEnd()) {
            // Reduce到Item的左侧代表的语法节点
            string grammarName = item->production->lhs;
            ASTNode *node = new ASTNode(grammarName);
            reduce = true;

            // 添加子节点
            int delta = stack.size() - item->production->rhs.size();
            // @TODO，要更换Stack数据结构
            for (int i = delta; i < stack.size(); i++) {
                // 产生式应该跟栈的元素一致
                if (stack[i]->getType == item->production->rhs[i - delta]) {
                    node->addChild(stack[i]);
                } else {
                    std::cout << "error reducing for : " << item << std::endl;
                }
            }

            // 弹出这些子节点
            for (int i = 0; i < item->production->rhs.size(); i++) {
                stack.pop();
            }

            // 添加父节点
            stack.push(node);

            // 基于新的栈，继续做reduce
            reduce(stack, nextToken, startState);
        }
    }

    return reduced;
}

/**
 * 把语法翻译成NFA
 */
GrammarNFAState* ASTNode::grammarToNFA(GrammarNode *grammar, vector<GrammarNode*> allNodes)
{
    // 1. 做一个起始节点，这样会有一个唯一的入口
    GrammarNode *start = new GrammarNode("start", GrammarNodeType::And);
    start->addChild(grammar);

    // 2. 把GrammarNode转换成用产生式表达的方式，这样处理起来逻辑更简单

    // 2.1 获得所有的终结符和非终结符
    allNodes.emplace_back(start):

    // 2.2 从名称查找GrammarNode的一个表
    map<string, GrammarNode*> nodes;
    for (GrammarNode *node : allNodes) {
        nodes[node->getName()] = node;
    }

    /**
     * 2.3 为每个GrammarNode中的命名节点生成一个或多个产生式
     * 比如, add -> add + mul | mul 会被拆成两个产生式: add -> add + mul 以及 add -> mul
     * 但右边存在未被充分拆解，比如: add -> add (+ | -) mul. 其中的(+ | -) 还需要进一步拆解
     * */
    set<Production*> productions;
    generateProduction(nodes, productions); 

    /**
     * 2.4 把产生式右边的Or节点都展开，变成最简单的产生式
     * 比如 add -> add (+ | -) mul。 其中的(+ | -) 还需要进一步拆解，变成两条
     * add -> add + mul，以及 add -> add - mul
     */
    simplifyProductions(nodes, productions);

    // 打印所有产生式看看
    std::cout << "\nProductions" << std::endl;
    for (Production *production: productions) {
        std::cout << production->toString() std::endl;
    }

    /**
     * 3. 基于产生式生成NFA
     * 3.1 先把每个产生式，都生成一个子图，子图中每个状态的Item的"."的位置依次后移
     * 比如: add -> .add + mul add -> add. + mul add->add + .mul add->add + mul.
     */
    map<Production*, GrammarNFAState*> subGraphs;
    vector<GrammarNFAState*> states;
    calcSubGraphs(productions, subGraphs, states);

    // 3.2 把各个子图通过Epsilon转换连接在一起.比如: add -> add + .mul 可以建立两条连接，分别是 mul -> .mul * pri, 以及 mul -> .pri
    linkSubGraphs(subGraphs, states);

    // 4. 找到起始结点对应的State
    GrammarNFAState *rootState = nullptr;
    for (Production *production : productions) {
        if (production->lhs == "start") {
            rootState = subGraphs[production];
        }
    }

    return rootState;
}

/**
 * 为每个GrammarNode中的命名节点生成一个或多个产生式
 * 比如, add -> add + mul | mul 会被拆成两个产生式：add->add + mul，以及 add->mul
 * 
 * 但右边存在未被充分拆解，比如: add -> add (+ | -) mul。其中的（+|-）还需要进一步拆解
 */
void ASTNode::generateProduction(map<string, GrammarNode*> nodes, set<Production*> productions);

/**
 * 把产生式右边的Or节点都展开，变成最简单的产生式
 * 比如 add -> add (+ | -) mul. 其中的 (+ | -) 还需要进一步拆解，变成两条
 *  add -> add + mul
 *  以及 add -> add - mul
 */
void ASTNode::simplifyProductions(map<string, GrammarNode*> nodes, set<Production*> productions);

/**
 * 为每个production产生一个子图
 * 子图中每个状态的Item的"."的位置依次后移
 * 比如:
 *  add -> .add + mul
 *  add -> add. + mul
 *  add -> add + .mul
 *  add -> add + mul.
 */
void ASTNode::calcSubGraphs(set<Production*> productions, map<Production*, GrammarNFAState*> subGraphs, vector<GrammarNFAState*> states);

/**
 * 把各个子图通过Epsilon转换连接在一起
 * 比如:
 *  add -> add + .mul 可以建立两条连接，分别是
 *      mul -> .mul * pri
 *      以及 mul -> .pri
 *  
 */
void ASTNode::linkSubGraphs(map<Production*, GrammarNFAState*> subGraphs, vector<GrammarNFAState*> states);

/**
 * 把NFA转换成DFA
 * 
 * @param startState 起始的NFA状态
 * @param grammarNames 所有符号的集合，包括终结符和非终结符
 */
vector<DFAState*> ASTNode::NFA2DFA(State *startState, vector<string> grammarNames, map<State*, set<State*>> closures);

/**
 * 根据NFA State 集合，查找是否已经存在一个DFAState ，包含同样的NFA状态集合
 */
DFAState* ASTNode::findDFAState(vector<DFAState*> dfaStates, set<State*> states);

/**
 * 比较两个NFA state 的集合是否相等
 */
bool ASTNode::sameStateSet(set<State*> stateSet1, set<State*> stateSet2);

/**
 * 计算所有的节点的Closure
 */
map<State*, set<State*>> ASTNode::calcClosure(State *state);

bool ASTNode::calcClosure(State *state, map<State*, set<State*>> closures, set<State*> calculated);

/**
 * 计算一个状态集合的闭包，包括这些状态以及可以通过epsilon到达的状态
 */
void ASTNode::addClosure(set<State*> states, map<State*, set<State*>> calculatedClosures);

/**
 * 计算从某个状态集合，在接受某个字符以后，会迁移到哪些新的集合
 */
set<State*> ASTNode::move(set<State*> states, string grammarName);