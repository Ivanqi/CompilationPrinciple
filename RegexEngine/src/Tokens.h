#ifndef TOKENS_H
#define TOKENS_H

#include <string>
#include <Any.h>
using namespace std;

/**
 * 一个简单的Token
 * 具体文本值，类型，在字符串中的位置等属性
 */
class Tokens
{
    private:
        // token 类型
        string type;

        // token的文本值
        string text;

        // token在整个字符流中的起止位置
        int startPos{0};
        int endPos{0};

        // token所在的行列位置
        int lineNumber{0};
        int startColumn{0};
        int endColumn{0};

        // 程序结束符号
        static Tokens* eof;

    public:
        Tokens(string type)
            :type(type)
        {
            
        }

        Tokens(string type, string text)
            :type(type), text(text)
        {

        }

        // Token类型
        string getType();

        void setType(string type);

        string getText();

        void setText(string text);

        int getStartPos();

        void setStartPos(int startPos);

        int getEndPos();

        void setEndPos(int endPos);

        int getLineNumber();

        void setLineNumber(int lineNumber);

        int getStartColumn();

        void setStartColumn(int startColumn);

        int getEndColumn();

        void setEndColumn(int endColumn);

        bool equals(Any obj);

        string toString();
};

#endif