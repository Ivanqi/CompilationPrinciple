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

    // 语法分析
    ASTNode *rootNode = match(grammar, tokenReader, firstSets, followSets);

    if (rootNode != nullptr && rootNode != ASTNode::EpsilonNode) {
        rootNode->dump();
        return rootNode;
    }

    return nullptr;
}

ASTNode* LLParser::match(GrammarNode* grammar, 
                        TokenReader *tokenReader, 
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
                if (grammar->isNullable()) {
                    set<string>* followSet = followSets[grammar];
                    // assert(followSet->size() > 0);

                    if (followSet->find(t.getType()) != followSet->end()) {
                        node = ASTNode::EpsilonNode;
                        epsilon = true;
                    }
                }

                if (!epsilon) {
                    std::cout << "unable to find a selection for: " << grammar << " | " << grammar->getName() << std::endl;
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