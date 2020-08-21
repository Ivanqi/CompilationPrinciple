#include <iostream>
#include <string>
#include <vector>
#include <exception>

#include "SimpleLexer.h"
using namespace std;

SimpleTokenReader* SimpleLexer::tokensize(string code)
{
    token = new SimpleToken();
    char ch;

    int codeLen = code.length();

    DfaState state = DfaState::Initial;

    try {
        for (int i = 0; i < codeLen; i++) {
            ch = (char) code[i];

            switch (state) {
                case Initial:
                    state = initToken(ch);  //  重新确定状态
                    break;
                
                case Id:
                    if (isAlpha(ch) || isDigit(ch)) {
                        tokenText.push_back(ch);    // 保持标识符状态
                    } else {
                        state = initToken(ch);      // 退出标识符状态，并保存Token
                    }
                    break;
                
                case GT:
                    if (ch == '=') {
                        token->type = TokenType::GE;  // 状态成GE
                        state = DfaState::GE;
                        tokenText.push_back(ch);
                    } else {
                        state = initToken(ch);        // 推出GT状态，并保存Token
                    }
                    break;
                
                case GE:
                case Assignment:
                case Plus:
                case Minus:
                case Star:
                case Slash:
                case SemiColon:
                case LeftParen:
                case RightParen:
                    state = initToken(ch);         // 退出当前状态，并保存Token
                    break;
                
                case IntLiteral:
                    if (isDigit(ch)) {
                        tokenText.push_back(ch);   // 继续保持在数字字面量状态
                    } else {
                        state = initToken(ch);      // 退出当前状态，并保存Token
                    }
                    break;
                
                case Id_int1:
                    if (ch == 'n') {
                        state = DfaState::Id_int2;
                        tokenText.push_back(ch);

                    } else if (isDigit(ch) || isAlpha(ch)) {
                        state = DfaState::Id;    // 切换回ID状态
                        tokenText.push_back(ch);
                    } else {
                        state = initToken(ch);
                    }
                    break;
                
                case Id_int2:
                    if (ch == 't') {
                        state = DfaState::Id_int3;
                        tokenText.push_back(ch);
                    } else if (isDigit(ch) || isAlpha(ch)) {
                        state = DfaState::Id;   // 切换回id状态
                        tokenText.push_back(ch);
                    } else {
                        state = initToken(ch);
                    }
                    break;
                
                case Id_int3:
                    if (isBlank(ch)) {
                        token->type = TokenType::Int;
                        state = initToken(ch);
                    } else {
                        state = DfaState::Id;   // 切换回Id状态
                        tokenText.push_back(ch);
                    }
                    break;
                default:
                    break;
            }
        }

        // 把最后一个token送进去
        if (tokenText.length() > 0) {
            initToken(ch);
        }

    } catch (exception& e) {
        cout << "exception: " << e.what() << endl;
    }

    return new SimpleTokenReader(tokens);
}

void SimpleLexer::dump(SimpleTokenReader *tokenReader)
{
    cout << "\ntext \t\t type" << endl;
    Token *token = NULL;

    while ((token = tokenReader->read()) != NULL) {
        cout << token->getText() << "\t\t" << token->getType() << endl;
    }
}