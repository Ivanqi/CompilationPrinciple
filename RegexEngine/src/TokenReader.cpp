#include "TokenReader.h"
#include "Tokens.h"

TokenReader::TokenReader(std::vector<Tokens> tokens):tokens_(tokens)
{
}

/**
 * 读取一个Token，并移动指针
 * @return 如果已经读完，则返回null
 */
Tokens* TokenReader::read()
{
    if (pos < tokens_.size()) {
        return tokens_[pos++];
    }
    return nullptr;
}

/**
 * 预读一个Token
 * @return 如果已经读完，则返回null
 */
Tokens* TokenReader::peek()
{
    if (pos < tokens_.size()) {
        return tokens_[pos];
    }
    return nullptr;
}

/**
 * 回溯一个Token
 */
void TokenReader::unread()
{
    if (pos > 0) {
        pos--;
    }
}

/**
 * 获取当前指针位置
 */
int TokenReader::getPosition()
{
    return pos;
}

/**
 * 设置指针位置,用于回溯
 */
void TokenReader::setPosition(int position)
{
    if (position >= 0 && position < tokens_.size()) {
        pos = position;
    }
}