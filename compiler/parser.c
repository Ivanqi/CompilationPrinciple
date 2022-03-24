#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "lexer.h"
#include "ast.h"
#include "util.h"

extern char* cur;

struct Token* t = NULL;

typedef enum {
    VT_INT,
} VarType;

typedef struct {
    char* var_name;
    VarType var_type;
} Var;

LIST(Var)
LIST_APPEND(Var)

VarList symbol_table;

Node* if_stmt();
Node* while_stmt();
Node* declare_stmt();
Node* asn_stmt();
Node* print_stmt();
Node* stmts();
Node* condition();
Node* expr();
Node* term();
Node* factor();

int match(enum TokenType tt) {
    if (t->_type != tt) {
        printf("Parse Error, expected %d, but got %d\n", tt, t->_type);
        return 0;
    }

    t = next_token();

    return 1;
}

/**
 * @brief 解析Token
 * 
 * @return Node* 
 */
Node* stmts() {
    ListNode* list = create_list();
    while (t != NULL) {

        if (t->_type == TT_IF) {    // if 类型
            append(list, if_stmt());
        } else if (t->_type == TT_INTEGER) {
            append(list, expr());
            assert(t->_type == TT_SEMICON);
            t = next_token();
        } else if (t->_type == TT_KW_INT) { // int 类型
            Node* stmt = declare_stmt();

            /* declared with initial value. */
            if (stmt != NULL) {
                append(list, stmt);
            }

            assert(t->_type == TT_SEMICON);
            t = next_token();
        } else if (t->_type == TT_VAR) {
            append(list, asn_stmt());
            assert(t->_type == TT_SEMICON);
            t = next_token();
        } else if (t->_type == TT_KW_WHILE) {   // while 类型
            append(list, while_stmt());
        } else if (t->_type == TT_KW_PRINT) {   // print 类型
            append(list, print_stmt());
            assert(t->_type == TT_SEMICON);
            t = next_token();
        } else {
            break;
        }
    }

    return (Node *)list;
}

Node* asn_stmt() {
    Node *a = expr();

    if (t->_type == TT_ASSIGN) {
        t = next_token();
        a = create_assign(a, expr());
    }

    return a;
}

/**
 * @brief print 文法
 * 
 * @return ** Node* 
 */
Node* print_stmt() {
    assert (t->_type == TT_KW_PRINT);
    t = next_token();

    assert (t->_type == TT_LEFT_PAR);
    t = next_token();

    Node *a = expr();
    a = create_print(a);
    assert (t->_type == TT_RIGHT_PAR);
    t = next_token();
    
    return a;
}

/**
 * @brief if 语句处理
 * 
 * @return Node* 
 */
Node* if_stmt() {
    Node *then_clause, *else_clause;
    assert(t->_type == TT_IF);

    t = next_token();
    assert(t->_type == TT_LEFT_PAR);

    t = next_token();
    Node* cond = condition();

    assert(t->_type == TT_RIGHT_PAR);

    t = next_token();
    assert(t->_type == TT_LEFT_BRACKET);

    t = next_token();
    then_clause = stmts();
    assert(t->_type == TT_RIGHT_BRACKET);

    t = next_token();
    if (t->_type == TT_ELSE) {
        t = next_token();
        assert(t->_type == TT_LEFT_BRACKET);

        t = next_token();
        else_clause = stmts();
        assert(t->_type == TT_RIGHT_BRACKET);

        t = next_token();
    } else {
        return create_if(cond, then_clause, NULL);
    }

    return create_if(cond, then_clause, else_clause);
}

/**
 * @brief while 文法
 * 
 * @return Node* 
 */
Node* while_stmt() {
    assert(t->_type == TT_KW_WHILE);

    t = next_token();
    assert(t->_type == TT_LEFT_PAR);

    t = next_token();
    Node* cond = condition();

    assert(t->_type == TT_RIGHT_PAR);

    t = next_token();
    assert(t->_type == TT_LEFT_BRACKET);

    t = next_token();
    // 对代码块内的内容，再做文法分析
    Node* body = stmts();
    assert(t->_type == TT_RIGHT_BRACKET);
    t = next_token();

    return create_while(cond, body);
}

/**
 * @brief 声明文法
 *  用于声明变量和值
 * 
 * @return Node* 
 */
Node* declare_stmt() {
    assert(t->_type == TT_KW_INT);
    
    t = next_token();
    assert(t->_type == TT_VAR);

    /* add varialbe into symbol table. 把变量节点加入符号表中 */
    Node *var_name = create_var(t->_value._str);
    Var entry = {((VarNode*)var_name)->name, 0};
    append_Var(&symbol_table, entry);

    t = next_token();
    // 分配符号
    if (t->_type == TT_ASSIGN) {
        t = next_token();
        return create_assign(var_name, expr());
    }

    return NULL;
}

/**
 * @brief 表达式文法
 * 
 * @return Node* 
 */
Node* condition() {
    Node* a, *b;
    a = expr();
    
    // 小于号
    if (t->_type == TT_LT) {
        t = next_token();
        b = expr();
        return create_binop(TT_LT, a, b);
    }

    return a;
}

/**
 * @brief 顶层规则
 *  这条规则代表表达式的定义，一个表达式可以是多项式的一个项或者多个项的和或者差
 * 
 * @return Node* 
 */
Node* expr() {
    Node* a = NULL, *b = NULL;
    a = term();

    while (t->_type == TT_ADD || t->_type == TT_SUB) {
        if (t->_type == TT_ADD) {
            t = next_token();
            b = term();
            a = create_binop(TT_ADD, a, b);
        } else if (t->_type == TT_SUB) {
            t = next_token();
            b = term();
            a = create_binop(TT_SUB, a, b);
        }
    }

    return a;
}

/**
 * @brief 项的规则，一个项可以是一个因子，或者多个因子的积或商
 *  这条规则保证了乘除法的优先级高于加减法
 * 
 * @return Node* 
 */
Node* term() {
    Node* a = NULL, *b = NULL;
    a = factor();

    while (t->_type == TT_MUL || t->_type == TT_DIV) {
        if (t->_type == TT_MUL) {
            t = next_token();
            b = factor();
            a = create_binop(TT_MUL, a, b);
        } else if (t->_type == TT_DIV) {
            t = next_token();
            b = factor();
            a = create_binop(TT_DIV, a, b);
        }
    }
    return a;
}

/**
 * @brief 因子的规则
 *  它可以是一个整数，或者是用括号括起来的表达式
 *  这定义了括号的优先级是最高的
 * 
 * @return Node* 
 */
Node* factor() {
    if (t->_type == TT_INTEGER) {
        Node* a = create_int(t->_value._int);
        t = next_token();
        return a;
    } else if (t->_type == TT_VAR) {
        Node* a = create_var(t->_value._str);
        t = next_token();
        return a;
    } else if (t->_type == TT_LEFT_PAR) {
        t = next_token();
        Node* a = expr();
        if (!match(TT_RIGHT_PAR)) {
            return NULL;
        } else {
            return a;
        }
    } else {
        printf("Parse Error\n");
        return NULL;
    }
}

Node* eval(char* s) {
    symbol_table.size = 8;
    symbol_table.length = 0;
    symbol_table.array = (Var*)malloc(8 * sizeof(Var));

    cur = s;
    t = next_token();
    return stmts();
}