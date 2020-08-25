#include "SimpleParser.h"
#include "SimpleLexer.h"

ASTNode* SimpleParser::parse(string script)
{
    SimpleLexer *lexer = new SimpleLexer();
    TokenReader *tokens = lexer->tokensize(script);
    ASTNode *rootNode = prog(tokens);
    return rootNode;
}

SimpleASTNode* SimpleParser::prog(TokenReader *tokens)
{
    SimpleASTNode *node = new SimpleASTNode(ASTNodeType::Program, "pwc");

    while (tokens->peek() != NULL) {
        SimpleASTNode *child = intDeclare(tokens);

        if (child == NULL) {
            child = expressionStatement(tokens);
        }

        if (child == NULL) {
            child = assignmentStatement(tokens);
        }

        if (child != NULL) {
            node->addChild(child);
        } else {
            throw "unknown statement";
        }
    }

    return node;
}

SimpleASTNode* SimpleParser::assignmentStatement(TokenReader *tokens)
{
    SimpleASTNode *node = NULL;
    Token *token = tokens->peek();  // 预读，看看下面是不是标识符

    if (token != NULL && token->getType() == TokenType::Identifier) {
        token = tokens->read();     // 读入标识符
        node = new SimpleASTNode(ASTNodeType::AssignmentStmt, token->getText());
        
        token = tokens->peek(); // 预读，看看下面是不是等号
        if (token != NULL && token->getType() == TokenType::Assignment) {
            tokens->read();
            SimpleASTNode *child = additive(tokens);
            if (child == NULL) {    // 出错，等号右边没有一个合法的表达式
                throw "invalide assigment statement, expecting an expression";
            } else {
                node->addChild(child);  // 添加子节点
                token = tokens->peek(); // 预读，看看后面是不是分号
                if (token != NULL && token->getType() == TokenType::SemiColon) {
                    tokens->read();     // 消耗掉这个分号
                } else {
                    // 报错，缺少分号
                    throw "invalid statement, expecting semicolon";
                }
            }
        } else {
            tokens->unread();   // 回溯，吐出之前消化掉的标识符
            node = NULL;
        }
    }

    return node;
}

// 表达式语句，即表达式后面跟个分号。
SimpleASTNode* SimpleParser::expressionStatement(TokenReader *tokens)
{
    int pos = tokens->getPosition();
    SimpleASTNode *node = additive(tokens);

    if (node != NULL) {
        Token *token = tokens->peek();
        if (token != NULL && token->getType() == TokenType::SemiColon) {    // ;符号
            tokens->read();
        } else {
            node = NULL;
            tokens->setPosition(pos);   // 回溯
        }
    }

    return node;    // 直接返回子节点，简化了AST
}

/**
 * 整型变量声明，如
 *  int a;
 *  int b = 2 * 3;
 */
SimpleASTNode* SimpleParser::intDeclare(TokenReader *tokens)
{
    SimpleASTNode *node = NULL;
    Token *token = tokens->peek();

    if (token != NULL && token->getType() == TokenType::Int) {   // 匹配Int
        token = tokens->read(); // 消耗掉int

        if (tokens->peek()->getType() == TokenType::Identifier) {   // 匹配标识符
            token = tokens->read(); // 消耗掉标识符号
            
            node = new SimpleASTNode(ASTNodeType::IntDeclaration, token->getText());
            token = tokens->peek();

            if (token != NULL && token->getType() == TokenType::Assignment) {   // 匹配表达式
                token = tokens->read(); // 消耗掉等号
                SimpleASTNode *child = additive(tokens);
                if (child == NULL) {
                    throw "invalide variable initalization, expecting an expression";
                } else {
                    node->addChild(child);
                }
            }
        } else {
            throw "variable name expected";
        }

        if (node != NULL) {
            token = tokens->peek();
            if (token != NULL && token->getType() == TokenType::SemiColon) {    // 判断是否是;符号
                tokens->read();
            } else {
                throw "invaild statement, expecting semicolon";
            }
        }
    }
}

// 加法表达式
SimpleASTNode* SimpleParser::additive(TokenReader *tokens)
{
    SimpleASTNode *child1 = multiplicative(tokens); // 应用add规则
    SimpleASTNode *node = child1;

    if (child1 != NULL) {
        while (true) {                              // 循环应用add' 规则
            Token *token = tokens->peek();
            if (token != NULL && (token->getType() == TokenType::Plus || TokenType::Minus)) {
                token = tokens->read();             // 读出加号
                SimpleASTNode *child2 = multiplicative(tokens); // 计算下级节点
                if (child2 != NULL) {
                    node = new SimpleASTNode(ASTNodeType::Additive, token->getText());
                    node->addChild(child1);         // 注意，新节点在顶层，保证正确的结合性
                    node->addChild(child2);
                    child1 = node;
                } else {
                    throw "invalid additive expression, expecting the right part.";
                }
            } else {
                break;
            }
        }
    }

    return node;
}

// 乘法表达式
SimpleASTNode* SimpleParser::multiplicative(TokenReader *tokens)
{
    SimpleASTNode *child1 = primary(tokens);
    SimpleASTNode *node = child1;

    while (true) {
        Token *token = tokens->peek();
        if (token != NULL && (token->getType() == TokenType::Star || token->getType() == TokenType::Slash)) {
            token = tokens->read();
            SimpleASTNode *child2 = primary(tokens);
            if (child2 != NULL) {
                node = new SimpleASTNode(ASTNodeType::Multiplicative, token->getText());
                node->addChild(child1);
                node->addChild(child2);
                child1 = node;
            } else {
                throw "invalid multiplicative expression, expecting the right part.";
            }
        } else {
            break;
        }
    }

    return node;
}

// 基础表达式
SimpleASTNode* SimpleParser::primary(TokenReader *tokens)
{
    Token *token = tokens->peek();
    SimpleASTNode *node = NULL;

    if (token != NULL) {
        if (token->getType() == TokenType::IntLiteral) {    // 整型字面量
            token = tokens->read();
            node = new SimpleASTNode(ASTNodeType::IntLiteral, token->getText());
        } else if (token->getType() == TokenType::Identifier) { // 标识符
            token = tokens->read();
            node = new SimpleASTNode(ASTNodeType::Identifier, token->getText());
        } else if (token->getType() == TokenType::LeftParen) { // 存在左括号(, 必须查看右括号)是否存在
            token = tokens->read();
            node = additive(tokens);

            if (node != NULL) {
                token = tokens->peek();
                if (token != NULL && token->getType() == TokenType::RightParen) {
                    tokens->read();
                } else {
                    throw "expecting right parenthesis";
                }
            } else {
                throw "expecting an additive expression inside parenthesis";
            }
        }
    }

    return node;    // 这个方法也做了AST的简化，就是不用构造一个primary节点，直接返回子节点。因为它只有一个子节点。
}

void SimpleParser::dumpAST(ASTNode *node, string indent)
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
