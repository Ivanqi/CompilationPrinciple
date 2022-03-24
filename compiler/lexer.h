#ifndef LEXER_H
#define LEXER_H

// 自动机状态
enum State {
    STATE_INIT, // 初始状态
    STATE_VAR,  // 接受字符的状态
    STATE_EQU,  // 接受等号的状态
    STATE_NUM,  // 接受数字的状态
};

// Token状态
enum TokenType {
    TT_VAR,     // 变量类型
    TT_INTEGER, // 整数类型
    TT_STRING,  // 字符串类型
    TT_ASSIGN,  // 分配符类型

    TT_SEMICON,     // 分隔符
    TT_LEFT_PAR,
    TT_RIGHT_PAR,

    TT_ADD,     // + 类型
    TT_SUB,     // - 类型
    TT_MUL,     // * 类型
    TT_DIV,     // / 类型

    TT_IF,                  // if 类型 
    TT_ELSE,                // else 类型
    TT_KW_INT,              // int 类型
    TT_KW_WHILE,            // while 类型
    TT_KW_PRINT,            // print 类型
    TT_LEFT_BRACKET,        // 左括号类型
    TT_RIGHT_BRACKET,       // 右括号类型

    TT_LT,                  // 小于符号
};

// Token Value 联合体
union TokenValue {
    char *_str;
    int _int;
};

// Token 结构体
struct Token {
    enum TokenType _type;
    union TokenValue _value;
};

void log_token(struct Token* t);
void destroy_token(struct Token* t);
struct Token* create_token(enum TokenType tt, char* begin, char* cur);
struct Token* next_token();


#endif