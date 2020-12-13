#ifndef TOKENREADER_H
#define TOKENREADER_H
#include <vector>

class Tokens;
/**
 * Token 流
 * 可以read或 peekToken
 * 可以通过unread, setPosition()回溯
 */
class TokenReader
{
    private:
        std::vector<Tokens> tokens_;

        int pos{0}; // 当前指针位置

    public:
        TokenReader(std::vector<Tokens> tokens);

        /**
         * 读取一个Token，并移动指针
         * @return 如果已经读完，则返回null
         */
        Tokens read();

        /**
         * 预读一个Token
         * @return 如果已经读完，则返回null
         */
        Tokens peek();

        /**
         * 回溯一个Token
         */
        void unread();

        /**
         * 获取当前指针位置
         */
        int getPosition();

        /**
         * 设置指针位置,用于回溯
         */
        void setPosition(int position);
};

#endif