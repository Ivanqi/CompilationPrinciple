#include "Token.h"

Token* Token::EOF = new Token("$");

// Token类型
string Token::getType()
{
    return type;
}

void Token::setType(string type)
{
    type = type;
}

string Token::getText()
{
    return text;
}

void Token::setText(string text)
{
    text = text;
}

int Token::getStartPos()
{
    return startPos;
}

void Token::setStartPos(int startPos)
{
    startPos = startPos;
}

int Token::getEndPos()
{
    return endPos;
}

void Token::setEndPos(int endPos)
{
    endPos = endPos;
}

int Token::getLineNumber()
{
    return lineNumber;
}

void Token::setLineNumber(int lineNumber)
{
    lineNumber = lineNumber;
}

int Token::getStartColumn()
{
    return startColumn;
}

void Token::setStartColumn(int startColumn)
{
    startColumn = startColumn;
}

int Token::getEndColumn()
{
    return endColumn;
}

void Token::setEndColumn(int endColumn)
{
    endColumn = endColumn;
}

bool Token::equals(Any obj)
{
    if (this == obj) return true;

    Token *token = obj.as<Token*>();

    if (!token->equals(token->type)) {
        return false;
    }

    if (text.size() == 0) {
        if (token->text.size() > 0) {
            return false;
        }
    } else {
        if (text.compare(token->text) != 0) {
            return false;
        }
    }

    return true;
}

string Token::toString()
{
    string rtn = type;

    rtn + ":";

    if (text.size() > 0) {
        rtn += text;
    }

    return rtn;
}