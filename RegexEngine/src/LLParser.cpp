#include "LLParser.h"
#include "GrammarNode.h"
#include "FirstFollowSet.h"

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


    return nullptr;
}