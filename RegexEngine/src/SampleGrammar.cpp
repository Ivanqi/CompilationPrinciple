#include "SampleGrammar.h"
#include "GrammarNode.h"
#include "Tokens.h"

GrammarNode* SampleGrammar::statementGrammar()
{
    GrammarNode *exp = expressionGrammar();

    shared_ptr<GrammarNode> blockStatementsPtr = shared_ptr<GrammarNode>(new GrammarNode("blockStatements", GrammarNodeType::Or));
    GrammarNode *blockStatements = blockStatementsPtr.get();

   blockStatements->createChild(GrammarNodeType::Epsilon);

   GrammarNode *blockStatements1 = blockStatements->createChild(GrammarNodeType::And);
   GrammarNode *blockStatement = blockStatements1->createChild("blockStatement", GrammarNodeType::Or);
   blockStatements1->addChild(blockStatements);

   GrammarNode *variableDeclarator = blockStatement->createChild("variableDeclarator", GrammarNodeType::And);
   variableDeclarator->createChild(new Token("INT", "int"));
   variableDeclarator->createChild(new Token("ID"));
   GrammarNode *variableInitiator = variableDeclarator->createChild(GrammarNodeType::Or);

   GrammarNode *variableInitiator_1 = variableDeclarator->createChild(GrammarNodeType::And);

   variableInitiator_1->createChild(new Token("ASSIGN", "="));
   variableInitiator_1->addChild(exp);
   variableInitiator_1->createChild(new Token("SEMI", ";"));

   variableInitiator->createChild(GrammarNodeType::Epsilon);

   GrammarNode *stmt = blockStatement->createChild("statement", GrammarNodeType::Or);

   // expression statement
   GrammarNode *expStmt = stmt->createChild("expressionStatement", GrammarNodeType::And);
   expStmt->addChild(exp);
   expStmt->createChild(new Token("SEMI", ";"));

   // if
   GrammarNode *ifStmt = stmt->createChild("ifStatement", GrammarNodeType::And);
   ifStmt->createChild(new Token("IF", "if"));
   ifStmt->createChild(new Token("LPAREN", "("));
   ifStmt->addChild(exp);
   ifStmt->createChild(new Token("RPAREN", ")"));
   ifStmt->addChild(stmt);
   ifStmt->createChild(new Token("SEMI", ";"));

   // block
   GrammarNode *block = stmt->createChild("block", GrammarNodeType::And);
   block->createChild(new Token("LBRACE", "{"));
   block->addChild(blockStatements);
   block->createChild(new Token("RBRACE", "}"));

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
    shared_ptr<GrammarNode> expPtr = shared_ptr<GrammarNode>(new GrammarNode("expression", GrammarNodeType::Or));
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
    relOp->createChild(new Token("GE", ">="));
    relOp->createChild(new Token("GT", ">"));
    relOp->createChild(new Token("LE", "<="));
    relOp->createChild(new Token("LT", "<"));
    rel1_1->addChild(add);
    rel1_1->addChild(rel1);
    rel1->createChild(GrammarNodeType::Epsilon);

    // add
    GrammarNode *mul = add->createChild("mul", GrammarNodeType::And);
    GrammarNode *add1 = add->createChild("add1", GrammarNodeType::Or);


    // add1
    GrammarNode *add1_1 = add1->createChild(GrammarNodeType::And);
    GrammarNode *addOp = add1_1->createChild(GrammarNodeType::Or);
    addOp->createChild(new Token("ADD", "+"));
    addOp->createChild(new Token("SUB", "-"));

    add1_1->addChild(mul);
    add1_1->addChild(add1);
    add1->createChild(GrammarNodeType::Epsilon);

    // mul
    GrammarNode *pri = mul->createChild("pri", GrammarNodeType::And);
    GrammarNode *mul1 = mul->createChild("mul1", GrammarNodeType::Or);

    // mul1
    GrammarNode *mul1_1 = mul1->createChild(GrammarNodeType::And);
    GrammarNode *mulOp = mul1_1->createChild(GrammarNodeType::Or);
    mulOp->createChild(new Token("MUL", "*"));
    mulOP->createChild(new Token("DIV", "/"));
    mul1->addChild(pri);
    mul1->addChild(mul1);
    mul1->createChild(GrammarNodeType::Epsilon);

    // pri
    pri->createChild(new Token("ID"));
    pri->createChild(new Token("INT_LITERAL"));
    GrammarNode *pri_3 = pri->createChild(GrammarNodeType::And);
    pri_3->createChild(new Token("LPAREN"));
    pri_3->addChild(exp);
    pri_3->createChild(new Token("RPAREN"));

    return exp;
}
