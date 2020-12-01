#ifndef SAMPLEGRAMMAR_H
#define SAMPLEGRAMMAR_H

class GrammarNode;
/**
 * 创建一些示例用的文法
 *  包括:
 *      1. 词法规则
 *      2. 消除了左递归的表达式的语法规则
 *      3. 带有左递归的表达式的语法规则
 *      4. 语句相关的语法规则
 */

class SampleGrammar
{
    public:
        static GrammarNode* statementGrammar();

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
        static GrammarNode* expressionGrammar();

        /**
         * 带有左递归的语法规则：
         *  expression	: add ;
         *  add	: mul | add (+ | -) mul ;
         *  mul	: pri | mul (* | /) pri ;
         *  pri	: ID | INT_LITERAL | LPAREN expression RPAREN ;
         */
        static GrammarNode* leftRecursiveExpressionGrammar();

        /**
         * 带有左递归的简化版的语法规则：
         *  add	: mul | add '+' mul ;
         *  mul	: pri | mul '*' pri ;
         *  pri	: INT_LITERAL | LPAREN add RPAREN ;
         */
        static GrammarNode* simpleLeftRecursiveExpressionGrammar();

        /**
         * 带有左递归的语法规则：
         *  expression	: assign ;
         *  assign	: equal | assign '=' equal ;
         *  equal	: rel | equal ('==' | '!=') rel ;
         *  rel		: add | rel ('>=' | '>' | '<=' | '<') add ;
         *  add		: mul | add ('+' | '-') mul ;
         *  mul		: pri | mul ('*' | '/') pri ;
         *  pri		: ID | INT_LITERAL | LPAREN expression RPAREN ;
         */
        static GrammarNode* fullLeftRecursiveExpressionGrammar();

        /**
         * 创建一个示例用词法规则，支持:
         *  关键字: int, if
         *  操作符: + - * / = == >= <= > <
         *  标识符
         */
        static GrammarNode* commonLexerGrammar();

        /**
         * Ebnf -> statements
         * statements -> statement | epsilon | statements
         * statement -> id ‘:’ exp ‘;’
         * Exp -> exp ‘|' and
         * and -> and pri (‘*’ | ‘?’ | ‘+’ | epsilon)
         * Pri ->  id | StringLiteral | brackLiteral | (exp)
         * brackLiteral-> ‘[’(^|epsion)brackElements’]’
         * brackElements -> char | charRange| escapedChar | brackElements | epsilon
         * charRange -> char ‘-‘ char
         * escapedChar -> ‘\n’ | ‘\\’
         */
        static GrammarNode* EBNFGrammar();

        static GrammarNode* simpleRepeat();
};

#endif