#include <stdio.h>

#include "ast.h"
#include "bcgen.h"
#include "code.h"
#include "opcode.h"

Context context = {Load, };

void code_object_emit_code(CodeObject *co, Node *root, Context *context) {
    if (root->ntype == NT_INT) {
        byte param = (byte)code_object_find_constant_index(co, ((IntNode*)root)->value);
        code_object_append_bytecode(co, LOAD_CONST, param);
    } else if (root->ntype == NT_ASN) {
        AssignNode *node = (AssignNode *)root;
        code_object_emit_code(co, node->value, context);
        context->is_store = Store;
        code_object_emit_code(co, node->var, context);
        context->is_store = Load;
    } else if (root->ntype == NT_VAR) {
        VarNode *node = (VarNode *)root;
        if (context->is_store == Store) {
            byte param = (byte)code_object_find_variable_index(co, node->name);
            code_object_append_bytecode(co, STORE_NAME, param);
        } else {
            byte param = (byte)code_object_find_variable_index(co, node->name);
            code_object_append_bytecode(co, LOAD_NAME, param);
        }
    } else if (root->ntype == NT_IF) {
        IfNode *node = (IfNode *)root;
        code_object_emit_code(co, node->cond, context);
        code_object_jump_false(co, IF_ELSE);
        code_object_emit_code(co, node->then_clause, context);

        code_object_jump(co, IF_END);
        code_object_bind(co, IF_ELSE);
        code_object_emit_code(co, node->else_clause, context);
        code_object_bind(co, IF_END);
    } else if (root->ntype == NT_WHILE) {   // while 类型
        code_object_bind(co, WHILE_HEAD);   // while 头

        WhileNode *node = (WhileNode *)root;
        code_object_emit_code(co, node->cond, context);

        code_object_jump_false(co, WHILE_END);

        code_object_emit_code(co, node->body, context);

        code_object_jump(co, WHILE_HEAD);
        code_object_bind(co, WHILE_END);

    } else if (root->ntype == NT_LIST) {    // 列表
        ListNode *node = (ListNode *)root;
        for (int i = 0; i < node->length; i++) {
            code_object_emit_code(co, node->array[i], context);
        }
    } else if (root->ntype == NT_PRINT) {   // print 类型
        code_object_emit_code(co, ((PrintNode*)root)->expr, context);
        code_object_append_bytecode(co, PRINT, 0);
    } else {
        BinOpNode* binop = (BinOpNode*)root;
        code_object_emit_code(co, binop->left, context);
        code_object_emit_code(co, binop->right, context);

        enum NodeType tt = root->ntype;
        byte param = 0;
        if (tt == NT_ADD) {
            code_object_append_bytecode(co, BINARY_ADD, param);
        } else if (tt == NT_SUB) {
            code_object_append_bytecode(co, BINARY_SUB, param);
        } else if (tt == NT_DIV) {
            code_object_append_bytecode(co, BINARY_DIV, param);
        } else if (tt == NT_MUL) {
            code_object_append_bytecode(co, BINARY_MUL, param);
        } else if (tt == NT_LT) {   // 小于号
            code_object_append_bytecode(co, COMPARE, COMPARE_LT);
        }
    }
}