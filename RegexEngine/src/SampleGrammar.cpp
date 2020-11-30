#include "SampleGrammar.h"
#include "GrammarNode.h"

GrammarNode* SampleGrammar::statementGrammar()
{

}

/**
 * 消除了左递归的表达式语法规则
 *  expression    : assign ;
 *  assign	: equal assgn1 ;
 *  assgn1	: '=' equal assgn1 | ε ;
 *  equal: rel equal1 ;
 *  equal1	: (== | !=) rel equal1 | ε ;
 *  rel	: add rel1 ;
 *  rel1	: (>= | > | <= | <) add rel1 | ε ;
 *  add	: mul add1 ;
 *  add1	: (+ | -) mul add1 | ε ;
 *  mul	: pri mul1 ;
 *  mul1	: (* | /) pri mul1 | ε ;
 *  pri	: ID | INT_LITERAL | LPAREN add RPAREN ;
 */
GrammarNode* SampleGrammar::expressionGrammar()
{
    // expression
    unique_ptr<GrammarNode> expPtr = unique_ptr<GrammarNode>(new GrammarNode("expression", GrammarNodeType::Or));
    GrammarNode *exp = expPtr.get();

    // assign
    GrammarNode *assign = exp->createChild("assign", GrammarNodeType::And);
    GrammarNode *equal = exp->createChild("equal", GrammarNodeType::And);
    GrammarNode *assign1 = exp->createChild("assign1", GrammarNodeType::Or);

    // assign1
    GrammarNode *assign1_1 = assign1->createChild(GrammarNodeType::And);
    assign1_1->createChild(new Tokens("ASSIGN", "="));
    assign1_1->addChild(equal);
    assign1_1->addChild(assign1);

    assign1->createChild(GrammarNodeType::Epsilon);

    // equal
    GrammarNode *rel = equal->createChild("rel", GrammarNodeType::And);
    GrammarNode *equal1 = equal->createChild("equal1", GrammarNodeType::Or);

    // equal1
    GrammarNode *equal1_1 = equal1->createChild(GrammarNodeType::And);
    GrammarNode *equal1Op = equal1_1->createChild(GrammarNodeType::Or);
    equal1Op->createChild(new Token("EQUAL", "=="));
    equal1Op->createChild(new Token("NOTEQUAL", "!="));

    equal1->addChild(rel);
    equal1->addChild(equal1);
    equal1->createChild(GrammarNodeType::Epsilon);

    // rel
    GrammarNode *add = rel->createChild("add", GrammarNodeType::And);
    GrammarNode *rel1 = rel->createChild("rel1", GrammarNodeType::Or);

    // rel1
    GrammarNode *rel1_1 = rel1->createChild(GrammarNodeType::And);
    GrammarNode *relOp = rel1_1->createChild(GrammarNodeType::Or);
}
