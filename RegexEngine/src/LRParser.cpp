#include "LRParser.h"
#include "ASTNode.h"
#include "GrammarNode.h"
#include "GrammarNFAState.h"
#include "Lexer.h"
#include "Tokens.h"
#include "TokenReader.h"
#include "Item.h"
#include "GrammarTransition.h"
#include "DFAState.h"

#include <iostream>
#include <assert.h>


/**
 * 解析代码，生成AST
 */
ASTNode* LRParser::parse(string script, GrammarNode *grammar)
{
    std::cout << "Grammar: " << std::endl;
    grammar->dump();

    // 转换成NFA
    vector<GrammarNode*> allNodes;
    GrammarNFAState *startNFAState = grammarToNFA(grammar, allNodes);
    std::cout << "\nNFA:" << std::endl;
    State::showState(startNFAState, false);

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
    map<State*, set<State*>*> closures = calcClosure(startNFAState);

    // 把NFA转换成DFA
    vector<shared_ptr<DFAState>> dfaStates = NFA2DFA(startNFAState, grammarNames, closures);
    // std::cout << "\nDFA:" << std::endl;
    // DFAState::showDFAState(dfaStates);

    // TODO: 在这里可以检查语法是否合法，比如是否存在reduce/reduce或shift/reduce冲突

    // 词法分析
    vector<Tokens> tokens = Lexer::tokenize(script);
    cout << "dump Tokens:" << endl;
    for (Tokens token : tokens){
        cout << '\t' << token.toString() << endl;
    }
    TokenReader *tokenReader = new TokenReader(tokens);

    Stack<ASTNode*> s1;
    // 语法分析
    ASTNode *rootNode = shiftReduce(s1, tokenReader, dfaStates[0].get());
    // std::cout << "\nAST:" << std::endl;
    // rootNode->dump();
    return rootNode;
}

/**
 * 通过移进，规约算法，做语法解析
 */
ASTNode* LRParser::shiftReduce(Stack<ASTNode*> stack, TokenReader *tokenReader, DFAState *startState)
{
    Tokens token = tokenReader->peek();
    while (token.getType() != "nullptr") {
        bool reduced = false;

        // 尝试做移进操作，可能会做多次
        if (stack.size() > 0) {
            reduced = reduce(stack, token, startState);
        }

        // 尝试做移进操作
        token = tokenReader->read();
        if (token.getType() != Tokens::eof.getType()) {
            stack.push(new ASTNode(token.getType(), token.getText()));
        }

        if (!reduced && token.getType() == Tokens::eof.getType()) {
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
bool LRParser::reduce(Stack<ASTNode*>& stack, Tokens nextToken, DFAState *startState)
{
    bool reduced = false;

    // 在DFA中找到当前状态
    DFAState *currentState = startState;
    Stack<ASTNode*>::iterator it;

    for (it = stack.begin(); it != stack.end(); it++) {
        ASTNode *node = *it;
        string grammarName = node->getType();
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
    if (nextToken.getType() != Tokens::eof.getType()) {
        for (State *state: currentState->getStatesSet()) {
            Item *item = ((GrammarNFAState*) state)->item;
            string grammarName = item->getNextGrammarName();
            if (grammarName.size() > 0) {
                if (nextToken.getType() == grammarName) {
                    return false;
                }
            }
        }
    }

    // 2. 接下来，要找到一个Item来做Reduce
    // 条件: 找到.符号是在结尾的
    // for (State *state: currentState->getStates()) {
    //     Item *item = ((GrammarNFAState*)state)->item;
    //     if (item->atEnd()) {
    //         // Reduce到Item的左侧代表的语法节点
    //         string grammarName = item->production->lhs;
    //         ASTNode *node = new ASTNode(grammarName);
    //         reduced = true;

    //         // 添加子节点
    //         int delta = stack.size() - item->production->rhs.size();
    //         // @TODO，要更换Stack数据结构
    //         for (int i = delta; i < stack.size(); i++) {
    //             // 产生式应该跟栈的元素一致
    //             if (stack[i]->getType == item->production->rhs[i - delta]) {
    //                 node->addChild(stack[i]);
    //             } else {
    //                 std::cout << "error reducing for : " << item << std::endl;
    //             }
    //         }

    //         // 弹出这些子节点
    //         for (int i = 0; i < item->production->rhs.size(); i++) {
    //             stack.pop();
    //         }

    //         // 添加父节点
    //         stack.push(node);

    //         // 基于新的栈，继续做reduce
    //         reduce(stack, nextToken, startState);
    //     }
    // }

    return reduced;
}

/**
 * 把语法翻译成NFA
 */
GrammarNFAState* LRParser::grammarToNFA(GrammarNode *grammar, vector<GrammarNode*>& allNodes)
{
    // 1. 做一个起始节点，这样会有一个唯一的入口
    GrammarNode *start = new GrammarNode("start", GrammarNodeType::And);
    start->addChild(grammar);

    // 2. 把GrammarNode转换成用产生式表达的方式，这样处理起来逻辑更简单

    // 2.1 获得所有的终结符和非终结符
    vector<GrammarNode*> tmpStart = start->getAllNodes();
    allNodes.insert(allNodes.end(), tmpStart.begin(), tmpStart.end());

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
        std::cout << production->toString() << std::endl;
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
void LRParser::generateProduction(map<string, GrammarNode*> nodes, set<Production*>& productions)
{
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        GrammarNode *node = it->second;
        if (node->isNamedNode()) {  // 只遍历各个父节点
            if (node->getType() == GrammarNodeType::Or) {
                for (int i = 0; i < node->getChildCount(); i++) {
                    GrammarNode *child = node->getChild(i);
                    Production *produ = new Production();
                    produ->lhs = node->getName();
                    produ->rhs.emplace_back(child->getName());
                    productions.insert(produ);
                }
            } else if (node->getType() == GrammarNodeType::And) {
                Production *produ = new Production();
                produ->lhs = node->getName();
                for (int i = 0; i < node->getChildCount(); i++) {
                    GrammarNode *child = node->getChild(i);
                    produ->rhs.emplace_back(child->getName());
                }
                productions.insert(produ);
            }
        }
    }
}

/**
 * 把产生式右边的Or节点都展开，变成最简单的产生式
 * 比如 add -> add (+ | -) mul. 其中的 (+ | -) 还需要进一步拆解，变成两条
 *  add -> add + mul
 *  以及 add -> add - mul
 */
void LRParser::simplifyProductions(map<string, GrammarNode*> nodes, set<Production*>& productions)
{
    bool modified = true;

    int round = 1;
    set<Production*> toRemove;
    set<Production*> newProductions;
    while (modified) {
        toRemove.clear();
        newProductions.clear();

        for (Production *produ: productions) {
            for (int i = 0; i < produ->rhs.size(); i++) {
                string name = produ->rhs[i];
                GrammarNode *node = nodes[name];
                if (node != nullptr && !node->isNamedNode()) {  // 只遍历子节点
                    if (node->getType() == GrammarNodeType::Or) {
                        toRemove.insert(produ);
                        for (int j = 0; j < node->getChildCount(); j++) {
                            // 创建一个新的产生式
                            Production *newProdu = new Production();
                            newProdu->lhs = produ->lhs;

                            // 拷贝or左边部分
                            for (int k = 0; k < i; k++) {
                                newProdu->rhs.emplace_back(produ->rhs[k]);
                            }

                            // 把 or 的子节点替换上来
                            if (node->getChild(i)->isToken()) {
                                newProdu->rhs.emplace_back(node->getChild(j)->getToken()->getType());
                            } else {
                                newProdu->rhs.emplace_back(node->getChild(j)->getName());
                            }

                            // 拷贝or右边的部分
                            for (int k = i + 1; k < produ->rhs.size(); k++) {
                                newProdu->rhs.emplace_back(produ->rhs[k]);
                            }

                            newProductions.insert(newProdu);
                        }

                        break;  // 每次只替换右边的一个节点就行
                    } else if (node->getType() == GrammarNodeType::And) {
                        toRemove.insert(produ);
                        Production *newProdu = new Production();
                        newProdu->lhs = produ->lhs;

                        // 拷贝add左边的部分
                        for (int k = 0; k < i; k++) {
                            newProdu->rhs.emplace_back(produ->rhs[k]);
                        }

                        // 把add的子节点替换上来
                        for (int j = 0; j < node->getChildCount(); j++) {
                            if (node->getChild(j)->isToken()) {
                                newProdu->rhs.emplace_back(node->getChild(j)->getToken()->getType());
                            } else {
                                newProdu->rhs.emplace_back(node->getChild(j)->getName());
                            }
                        }

                        // 拷贝add右边的部分
                        for (int k = i + 1; k < produ->rhs.size(); k++) {
                            newProdu->rhs.emplace_back(produ->rhs[k]);
                        }
                        newProductions.insert(newProdu);
                        break;  // 每次只替换右边的一个节点就行
                    } else if (node->getType() == GrammarNodeType::Token) {
                        toRemove.insert(produ);
                        Production *newProdu = new Production();
                        newProdu->lhs = produ->lhs;

                        // 拷贝Token左边的部分
                        for (int k = 0; k < i; k++) {
                            newProdu->rhs.emplace_back(produ->rhs[k]);
                        }
                        // 把Token的子节点替换上来
                        newProdu->rhs.emplace_back(node->getToken()->getType());

                        // 拷贝add右边的部分
                        for (int k = i + 1; k < produ->rhs.size(); k++) {
                            newProdu->rhs.emplace_back(produ->rhs[k]);
                        }
                        newProductions.insert(newProdu);
                    } else if (node->getType() == GrammarNodeType::Epsilon) {
                        toRemove.insert(produ);
                        Production *newProdu = new Production();
                        newProdu->lhs = produ->lhs;

                        // 拷贝Token左边的部分
                        for (int k = 0; k < i; k++) {
                            newProdu->rhs.emplace_back(produ->rhs[k]);
                        }
                        // 拷贝Token的子节点替换上来
                        newProdu->rhs.emplace_back(to_string(node->getType()));

                        // 拷贝add右边的部分
                        for (int k = i + 1; k < produ->rhs.size(); k++) {
                            newProdu->rhs.emplace_back(produ->rhs[k]);
                        }
                        newProductions.insert(newProdu);
                    }
                }
            }
        }

        // 去掉旧的，替换成新的
        modified = toRemove.size() > 0;
        if (modified) {
            // 求差集
            set<Production*> diff;
            set_difference(productions.begin(), productions.end(), toRemove.begin(), toRemove.end(), inserter(diff, diff.begin()));
            productions.swap(diff);
        }
        productions.insert(newProductions.begin(), newProductions.end());
    }
}

/**
 * 为每个production产生一个子图
 * 子图中每个状态的Item的"."的位置依次后移
 * 比如:
 *  add -> .add + mul
 *  add -> add. + mul
 *  add -> add + .mul
 *  add -> add + mul.
 */
void LRParser::calcSubGraphs(set<Production*> productions, map<Production*, GrammarNFAState*>& subGraphs, vector<GrammarNFAState*>& states)
{
    for (Production *produ: productions) {
        Item *item = new Item(produ, 0);
        GrammarNFAState *state = new GrammarNFAState(item);
        subGraphs[produ] = state;
        states.emplace_back(state);

        GrammarNFAState *lastState = state;

        /**
         * 例子
         * calcSubGraphs: add->mul  | rhsNum: 1
         * calcSubGraphs: mul->pri  | rhsNum: 1
         * calcSubGraphs: start->add  | crhsNum:1
         * calcSubGraphs: add->add ADD mul  | rhsNum:3
         * calcSubGraphs: mul->mul MUL pri  | rhsNum:3
         * calcSubGraphs: pri->INT_LITERAL  | rhsNum:1
         * calcSubGraphs: pri->LPAREN add RPAREN  | rhsNum:3
         * --- 
         * 通过transitions把state连接起来，形成一个链表
         */
        for (int i = 0; i < produ->rhs.size(); i++) {
            item = new Item(produ, i + 1);
            state = new GrammarNFAState(item);
            states.emplace_back(state);

            if (produ->rhs[i] == "Epsilon") {
                lastState->addTransition(new GrammarTransition(), state);
            } else {
                // 通过lastState的transitions可以查询到state
                lastState->addTransition(new GrammarTransition(produ->rhs[i]), state);
            }
            lastState = state;
        }
    }
}

/**
 * 把各个子图通过Epsilon转换连接在一起
 * 比如:
 *  add -> add + .mul 可以建立两条连接，分别是
 *      mul -> .mul * pri
 *      以及 mul -> .pri
 */
void LRParser::linkSubGraphs(map<Production*, GrammarNFAState*>& subGraphs, vector<GrammarNFAState*>& states)
{   
    // O(n ^ 2)
    for (GrammarNFAState *state : states) {
        // 查看position的大小是否超出rhs.size
        if (state->item->position < state->item->production->rhs.size()) {
            string grammarName = state->item->production->rhs[state->item->position];

            for (auto it = subGraphs.begin(); it != subGraphs.end(); it++) {
                Production *produ = it->first;
                // 在subGraphs[produ]选择与grammarName相同的进行关联
                if (produ->lhs == grammarName) {
                    GrammarNFAState *state1 = it->second;
                    state->addTransition(new GrammarTransition(), state1);
                }
            }
        }
    }
}

/**
 * 把NFA转换成DFA
 * 
 * @param startState 起始的NFA状态
 * @param grammarNames 所有符号的集合，包括终结符和非终结符
 */
vector<shared_ptr<DFAState>> LRParser::NFA2DFA(State *startState, vector<string> grammarNames, map<State*, set<State*>*> closures)
{
    vector<shared_ptr<DFAState>> dfaStates;
    vector<DFAState*> newStates;

    set<State*> *stateSet = closures[startState];
    DFAState *dfaState = new DFAState(*stateSet);
    dfaStates.emplace_back(shared_ptr<DFAState>(dfaState));
    newStates.emplace_back(dfaState);

    // 每次循环，都会计算出一些新的StateSet来
    // 如果没有新的了，计算结束
    while (newStates.size() > 0) {
        vector<DFAState*> calculating = newStates;
        newStates.clear();

        for (DFAState *dfaState2: calculating) {
            // 为每个grammarName循环
            for (string grammarName : grammarNames) {
                // 下一个集合
                set<State*> nextStateSet = move(dfaState2->getStatesSet(), grammarName);
                if (nextStateSet.size() == 0) {
                    continue;
                }

                // 把nextStateSet中每个状态的闭包也加入进来
                addClosure(nextStateSet, closures);

                // 看看是不是一个新的状态，如果已经有这个状态集，把它找出来，否则待处理栈
                dfaState = findDFAState(dfaStates, nextStateSet);
                Transition *transition = nullptr;
                if (dfaState == nullptr) {
                    dfaState = new DFAState(nextStateSet);
                    dfaStates.emplace_back(shared_ptr<DFAState>(dfaState));
                    newStates.emplace_back(dfaState);
                }

                transition = new GrammarTransition(grammarName);
                // 建立 dfaState2 与 dfaState的关联
                dfaState2->addTransition(transition, dfaState);
            }
        }
    }

    return dfaStates;
}

/**
 * 根据NFA State 集合，查找是否已经存在一个DFAState ，包含同样的NFA状态集合
 */
DFAState* LRParser::findDFAState(vector<shared_ptr<DFAState>> dfaStates, set<State*> states)
{
    DFAState *dfaState = nullptr;
    for (size_t i = 0; i < dfaStates.size(); i++) {
        DFAState *dfaState1 = dfaStates[i].get();
        if (sameStateSet(dfaState1->getStatesSet(), states)) {
            dfaState = dfaState1;
            break;
        }
    }
    return dfaState;
}

/**
 * 比较两个NFA state 的集合是否相等
 */
bool LRParser::sameStateSet(set<State*> stateSet1, set<State*> stateSet2)
{
    if (stateSet1.size() != stateSet2.size()) {
        return false;
    } else {
        // O(n^2), 待优化
        for (auto it = stateSet2.begin(); it != stateSet2.end(); it++) {
            State *state2 = *it;
            if (stateSet1.find(state2) == stateSet1.end()){
                return false;
            } 
        }
    }
    return true;
}

/**
 * 计算所有的节点的Closure
 */
map<State*, set<State*>*> LRParser::calcClosure(State *state)
{
    map<State*, set<State*>*> closures;

    int i = 1;
    std::cout << "calcClosure round: " << i++ << std::endl;

    set<State*> calculated;
    bool stable = calcClosure(state, closures, calculated);

    if (!stable) {
        std::cout << "calcClosure round: " << i++ << std::endl;
        set<State*> calculated1;
        stable = calcClosure(state, closures, calculated1);
    }

    return closures;
}

bool LRParser::calcClosure(State *state, map<State*, set<State*>*>& closures, set<State*>& calculated)
{
    calculated.insert(state);
    set<State*> *closure;

    if (closures.find(state) != closures.end()) {
        closure = closures[state];
    } else {
        closure = new set<State*>();
        closures[state] = closure;
    }

    bool stable = true;

    if (closure->find(state) == closure->end()) {
        closure->insert(state);
        stable = false;
    }

    vector<State*> toAdd;
    int transLen = state->getTransitions().size();
    std::cout << "calcClosure / " << state->getName() << " ";
    for (size_t i = 0; i < transLen; i++) {
        Transition *transition = state->getTransitions()[i].get();
        State *nextState = state->getState(transition);
        // 如果是Epsilon就往toAdd里增加
        if (transition->isEpsilon()) {
            std::cout << ": " << transition->toString() << " nextState: " << nextState->getName() << " ";
            toAdd.emplace_back(nextState);
        }

        // 把所有下级节点都计算一下
        bool childStable = true;
        if (calculated.find(nextState) == calculated.end()) {
            childStable = calcClosure(nextState, closures, calculated);
            if (!childStable) {
                stable = false;
            }
        }
    }
    std::cout << std::endl;
    set<State*> *closure1;

    for (State *state1: toAdd) {
        closure1 = closures[state1];
        if (closure1 == nullptr) continue;
        bool containsAll = true;
        for (auto it = closure1->begin(); it != closure1->end(); it++) {
            State *closureState2 = *it;
            if (closure->find(closureState2) == closure->end()) {
                containsAll = false;
                break;
            }
        }

        if (!containsAll) {
            closure->insert(closure1->begin(), closure1->end());
            stable = false;
        }
    }

    return stable;
}

/**
 * 计算一个状态集合的闭包，包括这些状态以及可以通过epsilon到达的状态
 */
void LRParser::addClosure(set<State*>& states, map<State*, set<State*>*> calculatedClosures)
{
    set<State*> newStates;
    for (auto it = states.begin(); it != states.end(); it++) {
        State *state = *it;
        set<State*> *closure = calculatedClosures[state];
        if (closure == nullptr) {
            std::cout << "warning : closure is null" << std::endl;
            continue;
        }
        if (closure->size() == 0) {
            std::cout << "warning : closure is null" << std::endl;
        }
        newStates.insert(closure->begin(), closure->end());
    }
    
    states.insert(newStates.begin(), newStates.end());
}

/**
 * 计算从某个状态集合，在接受某个字符以后，会迁移到哪些新的集合
 */
set<State*> LRParser::move(set<State*> states, string grammarName)
{
    set<State*> rtn;
    for (auto it = states.begin(); it != states.end(); it++) {
        State *state = *it;
        for (size_t i = 0; i < state->getTransitions().size(); i++) {
            Transition *transition = state->getTransitions()[i].get();
            // 如果匹配成功，形成新的迁移集合
            if (transition->match(grammarName)) {
                State *nextState = state->getState(transition);
                rtn.insert(nextState);
            }
        }
    }
    return rtn;
}