#include <stdio.h>
#include "ast.h"
#include "lexer.h"
#include "bcgen.h"
#include "code.h"
#include "vm.h"

extern Node* eval(char* s);
extern Context context;
extern void code_object_emit_code(CodeObject* co, Node* root, Context* context);

int main() {
    char* s = "int a = 1; int b = 1; int i = 0; while (i < 10) { "
        " int t = a + b; "
        " print(a);"
        " b = a;"
        " a = t;"
        " i = i + 1;}"
        "print(a);";

    //char* t = "if(1<2) {print(1);} else {print(2);}";

    CodeObject* co = create_code_object();
    //emit_bytecode(eval(s), &context);
    code_object_emit_code(co, eval(s), &context);
    // 打印opcode
    code_object_dump(co);
    VirtualMachine* vm = create_vm();
    interpret(vm, co);
    return 0;
}