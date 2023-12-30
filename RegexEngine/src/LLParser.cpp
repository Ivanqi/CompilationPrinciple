#include "LLParser.h"
#include "GrammarNode.h"
#include "FirstFollowSet.h"
#include "ASTNode.h"
#include "Lexer.h"
#include "Tokens.h"
#include "TokenReader.h"

#include <assert.h>
#include <algorithm>
#include <iostream>
/**
 * 解析代码, 生成AST
 * @param script
 * @grammar 所使用的语法的入口结点
 */
ASTNode* LLParser::parse(string script, GrammarNode* grammar)
{
    grammar->dump();

    // 计算First集合
    map<GrammarNode*, set<string>*> firstSets = FirstFollowSet::caclFirstSets(grammar);
    std::cout << "\nFIRST:" << endl;
    FirstFollowSet::dumpFirstFollowSets(firstSets);

    // 计算Follow集合
    map<GrammarNode*, set<string>*> followSets = FirstFollowSet::caclFollowSets(grammar, firstSets);
    std::cout << "\nFOLLOW:" << std::endl;
    FirstFollowSet::dumpFirstFollowSets(followSets);

    // 词法分析
    vector<Tokens> tokens = Lexer::tokenize(script);
    TokenReader *tokenReader = new TokenReader(tokens);

    cout << "\ndump Tokens:" << endl;
    for (Tokens token : tokens){
        cout << '\t' << token.toString() << endl;
    }

    // 语法分析
    ASTNode *rootNode = match(grammar, tokenReader, firstSets, followSets);

    if (rootNode != nullptr && rootNode != ASTNode::EpsilonNode) {
        rootNode->dump();
        return rootNode;
    }

    return nullptr;
}

/**
 * @brief LL(1)算法匹配
 *  1. 对于And类型的，要每个子节点依次全部匹配
 *      1. 遍历And类型的的子节点，并进行递归下降分析
 *  2. 对于Or类型的，通过预测，知道采用那个产生式
 *      1. 预先预测一个token as t,并遍历该Or类型的子节点
 *      2. 如果子节点是一个token，并于t做类型判断。如果相同就匹配成功
 *      3. 如果该子节点下还有子节点，那么first集合中找出该子节点对应first集合，并于t进行类型判断，如果相同就匹配成功
 *      4. 如果该子节点2，3步骤都匹配成功，那么该子节点的子节点进行递归下降分析
 *      5. 如果最终没有匹配成功，那么就是产生了ε，就该查找该Or类型的follow集合
 *  3. 如果是ε类型就是给节点设置成ε类型
 *  4. 如果是字符串类型，预读一个Token。看看自身的类型跟语法要求的是否一致。并设置到当前节点中
 *  5. 如果全部子节点返回的都是Epsilon, 自身也置为Epsilon
 * 
 * @param grammar 消除了左递归的语法树
 * @param tokenReader token串
 * @param firstSets first集合
 * @param followSets follow集合
 * @return ASTNode* 
 */
ASTNode* LLParser::match(GrammarNode* grammar,  TokenReader *tokenReader, 
                        map<GrammarNode*, set<string>*> firstSets, 
                        map<GrammarNode*, set<string>*> followSets)
{
    ASTNode *node = new ASTNode(grammar->getName());
    bool success = true;

    if (grammar->getChildCount() > 0) {
        assert(grammar->getType() == GrammarNodeType::And || grammar->getType() == GrammarNodeType::Or);
        
        // 对于And类型的，要每个子节点依次全部匹配
        if (grammar->getType() == GrammarNodeType::And) {
            for (int i = 0; i < grammar->getChildCount(); i++) {
                GrammarNode *child = grammar->getChild(i);
                ASTNode *childNode = match(child, tokenReader, firstSets, followSets);
                // 子节点匹配成功
                if (childNode != nullptr) {
                    if (childNode != ASTNode::EpsilonNode) {
                        node->addChild(childNode);
                    }
                } else {    // 子节点匹配失败，回溯，报错
                    std::cout << "failed to match " << child->toString() << std::endl;
                    break; 
                }
            }
        } else if (grammar->getType() == GrammarNodeType::Or) {
            // 对于Or类型的，通过预测，知道采用那个产生式
            bool matched = false;
            Tokens t = tokenReader->peek();
            for (int i = 0; i < grammar->getChildCount(); i++) {
                GrammarNode *child = grammar->getChild(i);
                if (child->isToken()) {
                    if (t.getType() == child->getToken().get()->getType()) {
                        matched = true;
                    }
                } else if (child->getChildCount() > 0) {
                    set<string>* firstSet = firstSets[child];
                    assert(firstSet->size() > 0);

                    if (firstSet->find(t.getType()) != firstSet->end()) {
                        matched = true;
                    }
                }

                // 符合token 的node，进行判断child节点
                if (matched) {
                    ASTNode *childNode = match(child, tokenReader, firstSets, followSets);
                    if (childNode != nullptr) {
                        if (childNode != ASTNode::EpsilonNode) {
                            node->addChild(childNode);
                        }
                    } else {
                        std::cout << "failed to match: " << child->getName() << std::endl;
                    }
                    break;
                }
            }

            if (!matched) {
                // 看看是否要产生Epsilon。这个时候要查看Follow集合
                bool epsilon = false;
                set<string>* followSet;
                if (grammar->isNullable()) {
                    followSet = followSets[grammar];
                    // assert(followSet->size() > 0);

                    if (followSet->find(t.getType()) != followSet->end()) {
                        node = ASTNode::EpsilonNode;
                        epsilon = true;
                    }
                }

                if (!epsilon) {
                    std::cout << "unable to find a selection for: " << grammar << " | " << grammar->toString() << " | followSet size: "<< followSet->size() << std::endl;
                }
            }
        }
    } else if (grammar->getType() == GrammarNodeType::Epsilon) {
        node = ASTNode::EpsilonNode;
    } else if (grammar->isToken()) {
        // 叶子节点. 看看自身的类型跟语法要求的是否一致
        Tokens t = tokenReader->peek();
        if (t.getType() != "nullptr") {
            assert(grammar->getToken().get() != nullptr);
            if (t.getType() == grammar->getToken().get()->getType()) {
                tokenReader->read();
                node = new ASTNode(t.getType());
                node->setText(t.getText());
            } else {
                // 匹配失败
                success = false;
            }
        } else {
            // 已经读完了所有的token
            success = false;
        }
    } else {
        std::cout << "unsupported grammarNode: " << grammar << std::endl;
    }

    // 如果全部子节点返回的都是Epsilon, 自身也置为Epsilon
    if (grammar->getChildCount() > 0 && node->getChildCount() == 0) {
        node = ASTNode::EpsilonNode;
    }

    return node;
}