#include <stdio.h>
#include <stdlib.h>

#include "code.h"
#include "opcode.h"
#include "vm.h"
#include "util.h"

/**
 * @brief 创建栈(先入后出)
 * 
 * @return Stack* 
 */
Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = 0;
    stack->size = 8;
    stack->array = (int*)malloc(sizeof(int) * 8);

    return stack;
}

void stack_push(Stack* stack, int x) {
    stack->array[stack->top++] = x;
}

int stack_pop(Stack* stack) {
    return stack->array[--stack->top];
}

/**
 * @brief 创建虚拟机
 * 
 * @return VirtualMachine* 
 */
VirtualMachine* create_vm() {
    VirtualMachine* vm = (VirtualMachine*)malloc(sizeof(VirtualMachine));
    vm->stack = create_stack();
    vm->var_table = create_int_list();
    return vm;
}

void interpret(VirtualMachine* vm, CodeObject* co) {
    for (int i = 0; i < co->bytecodes->length; i++) {
        byte opcode = co->bytecodes->array[i];
        byte param = 0;
        int u, v;

        if (opcode >= OP_CODE_PARAMETER) {
            param = co->bytecodes->array[++i];
        }

        switch(opcode) {
            case LOAD_CONST:
                PUSH(co->constant_pool->array[param]);
            break;

            case STORE_NAME:
                u = POP();
                vm->var_table->array[param] = u;
            break;

            case LOAD_NAME:
                PUSH(vm->var_table->array[param]);
            break;

            case BINARY_ADD:
                u = POP();
                v = POP();
                PUSH(u + v);
            break;

            case PRINT:
                u = POP();
                printf("%d\n", u);
            break;

            case COMPARE:
                u = POP();
                v = POP();
                if (param == COMPARE_LT) {
                    if (v < u) {
                        PUSH(1);
                    }
                    else {
                        PUSH(0);
                    }
                }
            break;

            case JUMP_IF_FALSE:
                u = POP();
                if (!u) {
                    i += param;
                }
            break;

            case JUMP:
                i += param;
            break;

            default:
                printf("Error, unrecognized bytecode: %d\n", opcode);
        }
    }
}