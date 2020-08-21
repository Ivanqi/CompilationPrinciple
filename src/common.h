#ifndef COMMON_H
#define COMMON_H
#include <string>
#include <iostream>
using namespace std;

// Token类型
enum TokenType {
    Plus,   // +
    Minus,  // -
    Star,   // *
    Slash,  // /

    GE,     // >=
    GT,     // >
    LE,     // <=
    LT,     // <

    SemiColon,  // ;
    LeftParen,  // (
    RightParen, // )

    Assignment, // =

    If,
    Else,

    Int,

    Identifier,     // 标识符

    IntLiteral,     // 整型字面量
    StringLiteral,  // 字符串字面量
};


/**
 * 一个简单的Token
 * 只有类型和文本两个属性
 */
class Token
{
    public:
        // Token类型
        virtual TokenType getType() = 0;

        // Token 文本值
        virtual string getText() = 0;
};

/**
 * 一个Token流。由Lexer生成
 * Parser可以从中获取Token
 */
class TokenReader
{
    public:
        /**
         * 返回Token流中下一个Token，并从流中取出
         * 如果流已经为空，返回null
         */
        virtual Token* read() = 0;

        /**
         * 返回Token流中下一个Token， 但不从流中取出
         * 如果流已经为空，返回null
         */
        virtual Token* peek() = 0;

        /**
         * Token 流回退一步
         * 恢复原来的Token
         */
        virtual void unread() = 0;

        /**
         * 获取Token流当前的读取位置
         */
        virtual int getPosition() = 0;

        /**
         * 设置Token流当前的读取位置
         */
        virtual void setPosition(int position) = 0;
};

#endif