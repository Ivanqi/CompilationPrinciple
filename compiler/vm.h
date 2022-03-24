#ifndef VM_H
#define VM_H

typedef struct {
    int top;
    int size;
    int *array;
} Stack;

Stack *create_stack();
void stack_push(Stack *stack, int x);
int stack_pop(Stack *stack);

typedef struct intList_s intList;

typedef struct {
    Stack *stack;
    intList *var_table;
} VirtualMachine;

typedef struct code_s CodeObject;

VirtualMachine *create_vm();
void interpret(VirtualMachine *vm, CodeObject *co);

#define PUSH(x) stack_push(vm->stack, (x))
#define POP() stack_pop(vm->stack)

#endif