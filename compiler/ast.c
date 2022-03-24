#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ast.h"
#include "lexer.h"

Node* create_int(int v) {
    IntNode *in = (IntNode *)malloc(sizeof(IntNode));
    in->value = v;
    in->parent.ntype = NT_INT;
    return (Node *)in;
}

/**
 * @brief 创建变量节点
 * 
 * @param name 
 * @return Node* 
 */
Node* create_var(char *name) {
    VarNode *in = (VarNode *)malloc(sizeof(VarNode));
    int len = strlen(name);
    in->name = (char *)malloc(len);
    strncpy(in->name, name, len);
    in->parent.ntype = NT_VAR;
    return (Node *)in;
}

/**
 * @brief 创建print节点
 * 
 * @param v 
 * @return Node* 
 */
Node* create_print(Node *v) {
    PrintNode *in = (PrintNode *)malloc(sizeof(PrintNode));
    in->expr = v;
    in->parent.ntype = NT_PRINT;
    return (Node *)in;
}

/**
 * @brief 创建赋值节点
 * 
 * @param var 
 * @param value 
 * @return Node* 
 */
Node* create_assign(Node *var, Node *value) {
    AssignNode *in = (AssignNode*) malloc(sizeof(AssignNode));
    in->var = var;
    in->value = value;
    in->parent.ntype = NT_ASN;
    return (Node *)in;
}

/**
 * @brief 创建表达式节点
 * 
 * @param tt 
 * @param left 
 * @param right 
 * @return Node* 
 */
Node* create_binop(enum TokenType tt, Node *left, Node *right) {
    BinOpNode *node = (BinOpNode *)malloc(sizeof(BinOpNode));
    node->left = left;
    node->right = right;

    if (tt == TT_ADD) {
        node->parent.ntype = NT_ADD;
    } else if (tt == TT_SUB ) {
        node->parent.ntype = NT_SUB;
    }else if (tt == TT_DIV) {
        node->parent.ntype = NT_DIV;
    } else if (tt == TT_MUL) {
        node->parent.ntype = NT_MUL;
    } else if (tt == TT_LT) {
        node->parent.ntype = NT_LT;
    }

    return (Node *)node;
}

Node* create_if(Node *cond, Node *then_clause, Node *else_clause) {
    IfNode *node = (IfNode *)malloc(sizeof(IfNode));
    node->parent.ntype = NT_IF;
    node->cond = cond;
    node->then_clause = then_clause;
    node->else_clause = else_clause;

    return (Node *)node;
}

/**
 * @brief 创建while 节点
 * 
 * @param cond while 的条件节点
 * @param body while 代码块节点
 * @return Node* 
 */
Node* create_while (Node *cond, Node *body) {
    WhileNode *node = (WhileNode *)malloc(sizeof(WhileNode));
    node->parent.ntype = NT_WHILE;
    node->cond = cond;
    node->body = body;

    return (Node *)node;
}

ListNode* create_list() {
    ListNode *list = (ListNode *)malloc(sizeof(ListNode));
    list->parent.ntype = NT_LIST;
    list->size = 8;
    list->length = 0;
    list->array = (Node **)malloc(8 * sizeof(Node *));

    return list;
}

void post_order(Node *root) {
    if (root->ntype == NT_INT) {
        printf("%d ", ((IntNode*)root)->value);
    } else if (root->ntype == NT_ASN) {
        AssignNode* node = (AssignNode*)root;
        post_order(node->var);
        printf(" = ");
        post_order(node->value);
        printf("\n");
    } else if (root->ntype == NT_VAR) {
        VarNode* node = (VarNode*)root;
        printf("%s ", node->name);
    } else if (root->ntype == NT_IF) {
        printf("IF(");
        IfNode* node = (IfNode*)root;
        post_order(node->cond);
        printf(", ");
        post_order(node->then_clause);
        printf(", ");
        post_order(node->else_clause);
        printf(") ");
        printf("\n");
    } else if (root->ntype == NT_WHILE) {
        printf("WHILE(");
        WhileNode* node = (WhileNode*)root;
        post_order(node->cond);
        printf(", ");
        post_order(node->body);
        printf(") ");
        printf("\n");
    } else if (root->ntype == NT_LIST) {
        ListNode* node = (ListNode*)root;
        for (int i = 0; i < node->length; i++) {
            post_order(node->array[i]);
        }
    } else {
        BinOpNode* binop = (BinOpNode*)root;
        post_order(binop->left);
        post_order(binop->right);

        enum NodeType tt = root->ntype;
        if (tt == NT_ADD) {
            printf("+ ");
        } else if (tt == NT_SUB) {
            printf("- ");
        } else if (tt == NT_DIV) {
            printf("/ ");
        } else if (tt == NT_MUL) {
            printf("* ");
        } else if (tt == NT_LT) {
            printf("< ");
        }
    }
}

// 把 ast节点加入到ast链表中
void append(ListNode* list, Node* n) {
    if (list->length < list->size) {
        list->array[list->length++] = n;
    } else {
        Node** new_arr = (Node**)malloc(list->size * 2 * sizeof(Node*));
        for (int i = 0; i < list->size; i++) {
            new_arr[i] = list->array[i];
        }
        free(list->array);
        list->array = new_arr;
    }
}