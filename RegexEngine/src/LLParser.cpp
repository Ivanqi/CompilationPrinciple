#include "LLParser.h"
#include "GrammarNode.h"

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
    map<GrammarNode*, set<string>> firstSets = caclFirstSets(grammar);
    std::cout << "\nnFIRST:" << endl;
    dumpFirstFollowSets(firstSets);

    return nullptr;
}

/**
 * 计算First集合
 * 采用了不动点法
 */
map<GrammarNode*, set<string>> LLParser::caclFirstSets(GrammarNode* grammar)
{
    map<GrammarNode*, set<string>> firstSets;

    set<GrammarNode*> calculated;
    bool stable = caclFirstSets(grammar, firstSets, calculated);

    int i = 1;

    std::cout << "fcaclFirstSets round: " << i++ << std::endl;

    while (!stable) {
        std::cout << "caclFirstSets round: " << i++ << std::endl;
        set<GrammarNode*> calculated1;
        stable = caclFirstSets(grammar, firstSets, calculated1);
    }
    return firstSets;
}

/**
 * 对First集合做一次计算
 * @param grammar
 * @param firstSets
 * @return 如果这次计算，First集合的成员都没有变动，则返回true
 */
bool LLParser::caclFirstSets(GrammarNode* grammar, map<GrammarNode*, set<string>> firstSets, set<GrammarNode*> calculated)
{
    // 标记正在计算该节点，避免重复调用
    calculated.insert(grammar);

    // 获取或创建First集合
    set<string> firstSet;
    if (firstSets.find(grammar) != firstSets.end()) {
        firstSet = firstSets[grammar];
    } else {
        firstSets[grammar] = firstSet;
    }

    bool stable = true;

    if (!grammar->isLeaf()) {
        // 先把所有的子节点都计算一遍
        for (size_t i = 0; i < grammar->getChildren().size(); i++) {
            GrammarNode *child = grammar->getChildren()[i].get();
            if (!child->isLeaf() && calculated.find(child) == calculated.end()) {
                caclFirstSets(child, firstSets, calculated);    // todo 是否需要记录Stable
            }
        }

        vector<GrammarNode*> childToAdd;

        if (grammar->getType() == GrammarNodeType::And) {
            childToAdd.emplace_back(grammar->getChild(0));

            // 要一直找到一个不产生Epsilong的符号
            for (size_t i = 0; i < grammar->getChildren().size(); i++) {
                GrammarNode *child = grammar->getChildren()[i].get();
                childToAdd.emplace_back(child);
                if (!child->isNullable()) {
                    break;
                }
            }
        } else if (grammar->getType() == GrammarNodeType::Or) {
            for (size_t i = 0; i < grammar->getChildren().size(); i++) {
                GrammarNode *child = grammar->getChildren()[i].get();
                childToAdd.emplace_back(child);

            }
        }

        set<string> v_intersection;
        for (GrammarNode *child : childToAdd) {
            if (!child->isLeaf()) {
                set<string> childSet = firstSets[child];
                v_intersection.clear();   
                // 求交集
                std::set_intersection(std::begin(firstSet), std::end(firstSet), std::begin(childSet), std::end(childSet), std::inserter(v_intersection, std::begin(v_intersection)));
                if (v_intersection.size() != childSet.size()) {
                    firstSet.insert(childSet.begin(), childSet.end());
                    stable = false;
                }
            } else if (child->isToken()) {
                if (firstSet.find(child->getToken()->getType()) == firstSet.end()) {
                    stable = false;
                    firstSet.insert(child->getToken()->getType());
                }
            }

            if (child->isNullable()) {
                if (firstSet.find("EPSILON") == firstSet.end()) {
                    firstSet.insert("EPSILON");
                }
            }
        }
    }

    return stable;
}

// 打印输出First或Follow集合
void LLParser::dumpFirstFollowSets(map<GrammarNode*, set<string>> sets)
{
    auto it = sets.begin();
    string str;

    while (it != sets.end()) {
        str.clear();
        set<string> set = it->second;
        GrammarNode *node = it->first;

        str = node->toString() + ":";
        for (auto setIt = set.begin(); setIt != set.end(); ++setIt) {
            str += " " + *setIt;
        }
        std::cout << str << std::endl;
    }
}