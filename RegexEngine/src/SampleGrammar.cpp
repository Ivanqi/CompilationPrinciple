#include "SampleGrammar.h"
#include "GrammarNode.h"
#include "Tokens.h"

GrammarNode* SampleGrammar::statementGrammar()
{
    GrammarNode *exp = expressionGrammar();
    
    GrammarNode *blockStatements = new GrammarNode("blockStatements", GrammarNodeType::Or);

    blockStatements->createChild(GrammarNodeType::Epsilon);

    GrammarNode *blockStatements1 = blockStatements->createChild(GrammarNodeType::And);
    GrammarNode *blockStatement = blockStatements1->createChild("blockStatement", GrammarNodeType::Or);
    blockStatements1->addChild(blockStatements);

    GrammarNode *variableDeclarator = blockStatement->createChild("variableDeclarator", GrammarNodeType::And);
    variableDeclarator->createChild(new Tokens("INT", "int"));
    variableDeclarator->createChild(new Tokens("ID"));
    GrammarNode *variableInitiator = variableDeclarator->createChild(GrammarNodeType::Or);

    GrammarNode *variableInitiator_1 = variableInitiator->createChild(GrammarNodeType::And);

    variableInitiator_1->createChild(new Tokens("ASSIGN", "="));
    variableInitiator_1->addChild(exp);
    variableInitiator_1->createChild(new Tokens("SEMI", ";"));

    variableInitiator->createChild(GrammarNodeType::Epsilon);

    GrammarNode *stmt = blockStatement->createChild("statement", GrammarNodeType::Or);

    // expression statement
    GrammarNode *expStmt = stmt->createChild("expressionStatement", GrammarNodeType::And);
    expStmt->addChild(exp);
    expStmt->createChild(new Tokens("SEMI", ";"));

    // if
    GrammarNode *ifStmt = stmt->createChild("ifStatement", GrammarNodeType::And);
    ifStmt->createChild(new Tokens("IF", "if"));
    ifStmt->createChild(new Tokens("LPAREN", "("));
    ifStmt->addChild(exp);
    ifStmt->createChild(new Tokens("RPAREN", ")"));
    ifStmt->addChild(stmt);
    ifStmt->createChild(new Tokens("SEMI", ";"));

    // block
    GrammarNode *block = stmt->createChild("block", GrammarNodeType::And);
    block->createChild(new Tokens("LBRACE", "{"));
    block->addChild(blockStatements);
    block->createChild(new Tokens("RBRACE", "}"));

    return blockStatements;
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
    GrammarNode *exp = new GrammarNode("expression", GrammarNodeType::Or);

    // assign
    GrammarNode *assign = exp->createChild("assign", GrammarNodeType::And);
    GrammarNode *equal = assign->createChild("equal", GrammarNodeType::And);
    GrammarNode *assign1 = assign->createChild("assign1", GrammarNodeType::Or);

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
    GrammarNode *equalOp = equal1_1->createChild(GrammarNodeType::Or);
    equalOp->createChild(new Tokens("EQUAL", "=="));
    equalOp->createChild(new Tokens("NOTEQUAL", "!="));

    equal1_1->addChild(rel);
    equal1_1->addChild(equal1);
    equal1->createChild(GrammarNodeType::Epsilon);

    // rel
    GrammarNode *add = rel->createChild("add", GrammarNodeType::And);
    GrammarNode *rel1 = rel->createChild("rel1", GrammarNodeType::Or);

    // rel1
    GrammarNode *rel1_1 = rel1->createChild(GrammarNodeType::And);
    GrammarNode *relOp = rel1_1->createChild(GrammarNodeType::Or);
    relOp->createChild(new Tokens("GE", ">="));
    relOp->createChild(new Tokens("GT", ">"));
    relOp->createChild(new Tokens("LE", "<="));
    relOp->createChild(new Tokens("LT", "<"));
    rel1_1->addChild(add);
    rel1_1->addChild(rel1);
    rel1->createChild(GrammarNodeType::Epsilon);

    // add
    GrammarNode *mul = add->createChild("mul", GrammarNodeType::And);
    GrammarNode *add1 = add->createChild("add1", GrammarNodeType::Or);


    // add1
    GrammarNode *add1_1 = add1->createChild(GrammarNodeType::And);
    GrammarNode *addOp = add1_1->createChild(GrammarNodeType::Or);
    addOp->createChild(new Tokens("ADD", "+"));
    addOp->createChild(new Tokens("SUB", "-"));

    add1_1->addChild(mul);
    add1_1->addChild(add1);
    add1->createChild(GrammarNodeType::Epsilon);

    // mul
    GrammarNode *pri = mul->createChild("pri", GrammarNodeType::Or);
    GrammarNode *mul1 = mul->createChild("mul1", GrammarNodeType::Or);

    // mul1
    GrammarNode *mul1_1 = mul1->createChild(GrammarNodeType::And);
    GrammarNode *mulOp = mul1_1->createChild(GrammarNodeType::Or);
    mulOp->createChild(new Tokens("MUL", "*"));
    mulOp->createChild(new Tokens("DIV", "/"));
    mul1_1->addChild(pri);
    mul1_1->addChild(mul1);
    mul1->createChild(GrammarNodeType::Epsilon);

    // pri
    pri->createChild(new Tokens("ID"));
    pri->createChild(new Tokens("INT_LITERAL"));
    GrammarNode *pri_3 = pri->createChild(GrammarNodeType::And);
    pri_3->createChild(new Tokens("LPAREN"));
    pri_3->addChild(exp);
    pri_3->createChild(new Tokens("RPAREN"));

    return exp;
}
