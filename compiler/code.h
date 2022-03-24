#ifndef CODE_H
#define CODE_H

#include "util.h"

typedef char byte;

enum LabelType {
    WHILE_HEAD,
    WHILE_END,
    IF_ELSE,
    IF_END
};

typedef struct Reloc {
    struct Reloc *next;
    struct Reloc *prev;
    int pos;
} Reloc;

typedef struct code_s {
    byteList *bytecodes;
    intList *constant_pool;
    stringList *var_table;

    int nested;

    int while_head;

    int reloc_if_else;
    int reloc_if_end;
    Reloc *reloc_while_end;
} CodeObject;

CodeObject* create_code_object();

void code_object_append_bytecode(CodeObject *co, byte op_code, byte parameter);
int code_object_find_constant_index(CodeObject *co, int t);
int code_object_find_variable_index(CodeObject *co, char *t);
void code_object_bind(CodeObject *co, enum LabelType lt);
void code_object_jump_false(CodeObject *co, enum LabelType lt);
void code_object_jump(CodeObject *co, enum LabelType lt);

void code_object_dump(CodeObject *co);

#endif