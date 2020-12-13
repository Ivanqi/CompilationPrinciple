#include "Tokens.h"

Tokens Tokens::eof("$");

// Token类型
string Tokens::getType()
{
    return type_;
}

void Tokens::setType(string type)
{
    type_ = type;
}

string Tokens::getText()
{
    return text_;
}

void Tokens::setText(string text)
{
    text_ = text;
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

    if (!token->equals(token->getType())) {
        return false;
    }

    if (text_.size() == 0) {
        if (token->getText().size() > 0) {
            return false;
        }
    } else {
        if (text_.compare(token->getText()) != 0) {
            return false;
        }
    }

    return true;
}

string Tokens::toString()
{
    string rtn = type_;

    rtn + ":";

    if (text_.size() > 0) {
        rtn += " " + text_;
    }

    return rtn;
}