#include "SimpleCalculator.h"
#include "SimpleLexer.h"
#include <exception>
#include <assert.h>

void SimpleCalculator::evaluate(string script)
{
    try {
        ASTNode *tree = parse(script);

        dumpAST(tree, "");
        evaluate(tree, "");

    } catch (exception &e) {
        cout << e.what() << endl;
    }
}

ASTNode* SimpleCalculator::parse(string code)
{
    SimpleLexer *lexer = new SimpleLexer();
    TokenReader *tokens = lexer->tokensize(code);

    ASTNode *rootNode = prog(tokens);

    return rootNode;
};

int SimpleCalculator::evaluate(ASTNode *node, string indent)
{
    int result = 0;
    ASTNodeType type = node->getType();
    std::cout << indent <<  "Calculating: " << type << std::endl;
    ASTNode *child1;
    ASTNode *child2;
    int value1 = 0;
    int value2 = 0;

    switch (type) {
        case ASTNodeType::Program:
            for (ASTNode *child : node->getChildren()) {
                result = evaluate(child, indent + "\t");
            }
            break;

        case ASTNodeType::Additive:
            child1 = node->getChildren()[0];
            value1 = evaluate(child1, indent + "\t");
            child2 = node->getChildren()[1];

            value2 = evaluate(child2, indent + "\t");
            if (node->getText() == "+") {
                result = value1 + value2;
            } else {
                result = value1 - value2;
            }
            break;

        case ASTNodeType::Multiplicative:
            child1 = node->getChildren()[0];
            value1 = evaluate(child1, indent + "\t");

            child2 = node->getChildren()[1];
            value2 = evaluate(child2, indent + "\t");

            if (node->getText() == "*") {
                result = value1 * value2;
            } else {
                result = value1 / value2;
            }
            break;
        
        case ASTNodeType::IntLiteral:
            result = atoi(node->getText().c_str());
            break;
        
        default:
            break;
    }

    std::cout << indent << " Result: " << result << std::endl;
    return result;
}

SimpleASTNode* SimpleCalculator::prog(TokenReader *tokens)
{
    SimpleASTNode *node = new SimpleASTNode(ASTNodeType::Program, "Calculator");

    SimpleASTNode *child = additive(tokens);

    if (child != NULL) {
        node->addChild(child);
    }

    return node;
}

SimpleASTNode* SimpleCalculator::intDeclare(TokenReader *tokens)
{
    SimpleASTNode *node = NULL;
    Token *token = tokens->peek();    // 预读

    if (token != NULL && token->getType() == TokenType::Int) {   // 匹配Int
        token = tokens->read();      // 消耗掉int
        
        if (tokens->peek()->getType() == TokenType::Identifier) { // 匹配标识符
            token = tokens->read();  // 消耗掉标识符号

            // 创建当前节点，并把变量名记到AST节点的文本值中，这里新建一个变量子节点也是可以的
            node = new SimpleASTNode(ASTNodeType::IntDeclaration, token->getText());
            token = tokens->peek(); // 预读

            if (token != NULL && token->getType() == TokenType::Assignment) {
                tokens->read();      // 消耗掉等号
                SimpleASTNode *child = additive(tokens); // 匹配一个表达式
                if (child == NULL) {
                    throw "invalide variable initialization, expecting an expression";
                } else {
                    node->addChild(child);
                }
            }
        } else {
            throw "variable name expected";
        }

        if (node != NULL) {
            token = tokens->peek();

            if (token != NULL && token->getType() == TokenType::SemiColon) {
                tokens->read();
            } else {
                throw "invalid statement, expecting semicolon";
            }
        }
    }
    return node;
}

SimpleASTNode* SimpleCalculator::additive(TokenReader *tokens)
{
    SimpleASTNode *child1 = multiplicative(tokens);
    SimpleASTNode *node = child1;

    Token *token = tokens->peek();
    if (child1 != NULL && token != NULL) {
        if (token->getType() == TokenType::Plus || token->getType() == TokenType::Minus) {
            token = tokens->read();
            SimpleASTNode *child2 = additive(tokens);

            if (child2 != NULL) {
                node = new SimpleASTNode(ASTNodeType::Additive, token->getText());
                node->addChild(child1);
                node->addChild(child2);
            } else {
                throw "invalid additive expression, expecting the right part.";
            }
        }
    }

    return node;
}
 
SimpleASTNode* SimpleCalculator::multiplicative(TokenReader *tokens)
{
    SimpleASTNode *child1 = primary(tokens);
    SimpleASTNode *node = child1;

    Token *token = tokens->peek();
    if (child1 != NULL && token != NULL) {
        if (token->getType() == TokenType::Star || token->getType() == TokenType::Slash) {
            token = tokens->read();
            SimpleASTNode *child2 = multiplicative(tokens);

            if (child2 != NULL) {
                node = new SimpleASTNode(ASTNodeType::Multiplicative, token->getText());
                node->addChild(child1);
                node->addChild(child2);
            } else {
                throw "invalid mutiplicative expression, expecting the right part.";
            }
        }
    }
    return node;
}

SimpleASTNode* SimpleCalculator::primary(TokenReader *tokens)
{
    SimpleASTNode *node = NULL;
    Token *token = tokens->peek();

    if (token != NULL) {
        if (token->getType() == TokenType::IntLiteral) {
            token = tokens->read();
            node = new SimpleASTNode(ASTNodeType::IntLiteral, token->getText());
        } else if (token->getType() == TokenType::Identifier) {
            token = tokens->read();
            node = new SimpleASTNode(ASTNodeType::Identifier, token->getText());
        } else if (token->getType() == TokenType::LeftParen) {
            tokens->read();
            node = additive(tokens);

            if (node != NULL) {
                token = tokens->peek();
                if (token != NULL && token->getType() == TokenType::RightParen) {
                    tokens->read();
                } else {
                    throw "expecting right parenthesis";
                }
            } else {
                throw  "expecting an additive expression inside parenthesis";
            }
        }
    }

    return node;    // 这个方法也做了AST简化，就是不用构造一个primary节点，直接返回子节点。因为它只有一个节点
}

void SimpleCalculator::dumpAST(ASTNode *node, string indent)
{
    if (node != NULL) {
        ASTNodeType type = node->getType();
        string text = node->getText();
        cout << indent <<  type << " " << text << endl;

        for (ASTNode *child: node->getChildren()) {
            dumpAST(child, indent + "\t");
        }
    }
}