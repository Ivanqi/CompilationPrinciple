#ifndef SIMPLELEXER_H
#define SIMPLELEXER_H
#include <string>
#include <vector>
#include <algorithm>
#include "common.h"
using namespace std;

/**
 * Token 的一个简单实现，只有类型和文本值两个属性
 */
class SimpleToken : public Token
{
    public:
        // Token类型
        TokenType type;

        // 文本值
        string text;

        TokenType getType()
        {
            return type;
        }

        string getText()
        {
            return text;
        }
};

class SimpleTokenReader: public TokenReader
{
    public:
        vector<Token*> tokens;
        int pos = 0;

        SimpleTokenReader(vector<Token*>& tokens) : tokens(tokens)
        {
            
        }

        Token* read()
        {
            if (pos < tokens.size()) {
                return tokens[pos++];
            }
            return NULL;
        }

        Token* peek()
        {
            if (pos < tokens.size()) {
                return tokens[pos];
            }
            return NULL;
        }

        void unread()
        {
            if (pos > 0) {
                pos--;
            }
        }

        int getPosition()
        {
            return pos;
        }

        void setPosition(int position)
        {
            if (position >= 0 && position < tokens.size()) {
                pos = position;
            }
        }

};

class SimpleLexer
{
    private:
        string tokenText;      // 临时保存token
        vector<Token*> tokens;  // 保存解析出来的token
        SimpleToken *token;     // 当前正在解析的token

         /**
         * 有限状态机的各种状态
         */
        enum DfaState
        {
            Initial,

            If, Id_if1, Id_if2, Else, Id_else1, Id_else2, Id_else3, Id_else4, Int, Id_int1, Id_int2, Id_int3, Id, GT, GE,

            Assignment,

            Plus, Minus, Star, Slash,

            SemiColon,
            LeftParen,
            RightParen,

            IntLiteral
        };

    private:
        // 是否是字母
        bool isAlpha(int ch)
        {
            return ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122));
        }

        // 是否是数字
        bool isDigit(int ch)
        {
            return ch >= 48 && ch <= 57;
        }

        // 是否是空白字符
        bool isBlank(char ch)
        {
            return ch == ' ' || ch == '\t' || ch == '\n';
        }


        /**
         * 有限状态机进入初始状态。
         * 这个初始状态其实并不做停留，它马上进入其他状态。
         * 开始解析的时候，进入初始状态；某个Token解析完毕，也进入初始状态，在这里把Token记下来，然后建立一个新的Token。
         */
        DfaState initToken(char ch)
        {
            if (tokenText.length() > 0) {
                token->text = tokenText;
                tokens.push_back(token);

                tokenText.clear();
                token = new SimpleToken();
            }

            DfaState newState = DfaState::Initial;

            if (isAlpha(ch)) {  // 第一个字符是字母
                if (ch == 'i') {
                    newState = DfaState::Id_int1;
                } else {
                    newState = DfaState::Id;    // 进入Id 状态
                }

                token->type = TokenType::Identifier;
                tokenText.push_back(ch);

            } else if (isDigit(ch)) {   // 第一个字符是数字
                newState = DfaState::IntLiteral;
                token->type = TokenType::IntLiteral;
                tokenText.push_back(ch);

            } else if (ch == '>') { // 第一个字符是 >
                newState = DfaState::GT;
                token->type = TokenType::GT;
                tokenText.push_back(ch);

            } else if (ch == '+') {
                newState = DfaState::Plus;
                token->type = TokenType::Plus;
                tokenText.push_back(ch);

            } else if (ch == '-') {
                newState = DfaState::Minus;
                token->type = TokenType::Minus;
                tokenText.push_back(ch);

            } else if (ch == '*') {
                newState = DfaState::Star;
                token->type = TokenType::Star;
                tokenText.push_back(ch);

            } else if (ch == ';') {
                newState = DfaState::SemiColon;
                token->type = TokenType::SemiColon;
                tokenText.push_back(ch);

            } else if (ch == '/') {
                newState = DfaState::Slash;
                token->type = TokenType::Slash;
                tokenText.push_back(ch);

            } else if (ch == '(') {
                newState = DfaState::LeftParen;
                token->type = TokenType::LeftParen;
                tokenText.push_back(ch);
                
            } else if (ch == ')') {
                newState = DfaState::RightParen;
                token->type = TokenType::RightParen;
                tokenText.push_back(ch);
                
            } else if (ch == '=') {
                newState = DfaState::Assignment;
                token->type = TokenType::Assignment;
                tokenText.push_back(ch);
                
            } else {
                newState = DfaState::Initial;
            }

            return newState;
        }


    public:
        /**
         * 解析字符串，形成Token。
         * 这是一个有限状态自动机，在不同的状态中迁移。
         */
        SimpleTokenReader* tokensize(string code);

        /**
         * 打印所有的Token
         */
        void dump(SimpleTokenReader *tokenReader);
};



#endif