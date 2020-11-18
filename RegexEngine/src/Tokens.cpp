#include "Tokens.h"

Tokens* Tokens::eof = new Tokens("$");

// Token类型
string Tokens::getType()
{
    return type;
}

void Tokens::setType(string type)
{
    type = type;
}

string Tokens::getText()
{
    return text;
}

void Tokens::setText(string text)
{
    text = text;
}

int Tokens::getStartPos()
{
    return startPos;
}

void Tokens::setStartPos(int startPos)
{
    startPos = startPos;
}

int Tokens::getEndPos()
{
    return endPos;
}

void Tokens::setEndPos(int endPos)
{
    endPos = endPos;
}

int Tokens::getLineNumber()
{
    return lineNumber;
}

void Tokens::setLineNumber(int lineNumber)
{
    lineNumber = lineNumber;
}

int Tokens::getStartColumn()
{
    return startColumn;
}

void Tokens::setStartColumn(int startColumn)
{
    startColumn = startColumn;
}

int Tokens::getEndColumn()
{
    return endColumn;
}

void Tokens::setEndColumn(int endColumn)
{
    endColumn = endColumn;
}

bool Tokens::equals(Any obj)
{
    // if (this == obj) return true;

    Tokens *token = obj.as<Tokens*>();

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

string Tokens::toString()
{
    string rtn = type;

    rtn + ":";

    if (text.size() > 0) {
        rtn += text;
    }

    return rtn;
}