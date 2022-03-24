#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "code.h"
#include "opcode.h"

/**
 * @brief Create a code object object
 * 
 * @return CodeObject* 
 */
CodeObject* create_code_object() {
    CodeObject *co = (CodeObject *)malloc(sizeof(CodeObject));
    co->nested = 0;
    co->bytecodes = create_byte_list();     // opcode队列
    co->constant_pool = create_int_list();  // int队列
    co->var_table = create_string_list();   // 变量队列
    co->reloc_while_end = NULL;
}

void code_object_append(CodeObject *co, byte b) {
    append_byte(co->bytecodes, b);
}

/**
 * @brief 存储opcode，并存储对应变量
 * 
 * @param co 
 * @param op_code 
 * @param parameter 
 */
void code_object_append_bytecode(CodeObject *co, byte op_code, byte parameter) {
    code_object_append(co, op_code);
    if (op_code >= OP_CODE_PARAMETER) {
        code_object_append(co, parameter);
    }
}

/**
 * @brief 从int队列中找到int值，并返回下标
 *  如果找不到index下标就加入int队列中，返回下标
 * 
 * @param co 
 * @param t 
 * @return int 
 */
int code_object_find_constant_index(CodeObject *co, int t) {
    int index = list_find_index_int(co->constant_pool, t);
    if (index >= 0) {
        return index;
    }

    append_int(co->constant_pool, t);
    return co->constant_pool->length - 1;
}

/**
 * @brief 从变量队列中找到变量名，并返回下标
 *  如果找不到index下标就加入变量队列中，返回下标
 * 
 * @param co 
 * @param t 
 * @return int 
 */
int code_object_find_variable_index(CodeObject *co, char *t) {
    for (int i = 0; i < co->var_table->length; i++) {
        if (strcmp(co->var_table->array[i], t) == 0) {
            return i;
        }
    }
    append_string(co->var_table, t);
    return co->var_table->length - 1;
}

void code_object_bind(CodeObject *co, enum LabelType lt) {
    if (lt == WHILE_HEAD) {
        co->while_head = co->bytecodes->length;
    } else if (lt == WHILE_END) {
        Reloc *reloc = co->reloc_while_end;
        while (reloc) {
            co->bytecodes->array[reloc->pos + 1] = (byte)(co->bytecodes->length - reloc->pos - 2);
            Reloc *tmp = reloc;
            reloc = reloc->next;
            free(tmp);
        }
    } else if (lt == IF_ELSE) {
        co->bytecodes->array[co->reloc_if_else + 1] = co->bytecodes->length - co->reloc_if_else - 2;
    } else if (lt == IF_END) {
        co->bytecodes->array[co->reloc_if_end + 1] = co->bytecodes->length - co->reloc_if_end - 2;
    }
}

/**
 * @brief 创建 while end. 
 * 
 * @param co 
 * @param pos 
 */
static void code_object_record_reloc(CodeObject *co, int pos) {
    Reloc *reloc = (Reloc *)malloc(sizeof(Reloc));
    reloc->next = NULL;
    reloc->prev = NULL;
    reloc->pos = pos;

    if (co->reloc_while_end == NULL) {
        co->reloc_while_end = reloc;
    } else {
        reloc->next = co->reloc_while_end;
        co->reloc_while_end->prev = reloc;
        co->reloc_while_end = reloc;
    }
}

void code_object_jump_false(CodeObject *co, enum LabelType lt) {
    if (lt == IF_ELSE) {
        co->reloc_if_else = co->bytecodes->length;
        code_object_append_bytecode(co, JUMP_IF_FALSE, 0);
    } else if (lt == WHILE_END) {
        code_object_record_reloc(co, co->bytecodes->length);
        code_object_append_bytecode(co, JUMP_IF_FALSE, 0);
    }
}

void code_object_jump(CodeObject *co, enum LabelType lt) {
    if (lt == WHILE_END) {
        // jump to loop head, look forward
        code_object_append_bytecode(co, JUMP, (byte)(co->while_head - co->bytecodes->length - 2));
    } else if (lt == IF_END) {
        co->reloc_if_end = co->bytecodes->length;
        code_object_append_bytecode(co, JUMP, 0);
    }
}

void code_object_dump(CodeObject *co) {
    for (int i = 0; i < co->bytecodes->length; i++) {
        byte opcode = co->bytecodes->array[i];
        byte param = 0;

        if (opcode >= OP_CODE_PARAMETER) {
            param = co->bytecodes->array[++i];
        }

        printf("\t");

        if (opcode == LOAD_CONST) {
            printf("LOAD_CONST\t%d\n", co->constant_pool->array[param]);
        } else if (opcode == LOAD_NAME) {
            printf("LOAD_NAME\t%s\n", co->var_table->array[param]);
        } else if (opcode == STORE_NAME) {
            printf("STORE_NAME\t%s\n", co->var_table->array[param]);
        } else if (opcode == BINARY_ADD) {
            printf("BINARY_ADD\n");
        } else if (opcode == BINARY_SUB) {
            printf("BINARY_SUB\n");
        } else if (opcode == BINARY_MUL) {
            printf("BINARY_MUL\n");
        } else if (opcode == BINARY_DIV) {
            printf("BINARY_DIV\n");
        } else if (opcode == COMPARE) {
            printf("COMPARE\t");
            if (param == COMPARE_LT) {
                printf("<");
            }
            printf("\n");
        } else if (opcode == PRINT) {
            printf("PRINT\n");
        } else if (opcode == JUMP) {
            printf("JUMP\t%d\n", param);
        } else if (opcode == JUMP_IF_FALSE) {
            printf("JUMP_IF_FALSE\t%d\n", param);
        }
    }
}