#include "AsmGen.h"
#include "AnnotatedTree.h"

using namespace play;

// 主控程序
string AsmGen::generate()
{
    string sb;
    // 1. 代码段的头
    sb.append("\t.section	__TEXT,__text,regular,pure_instructions\n");

    // 2. 生成函数的代码
    for (Type *type: at_->types) {
        Function *func = dynamic_cast<Function>(type);
        if (func != nullptr) {
            PlayScriptParser::FunctionDeclarationContext *fdc = dynamic_cast<PlayScriptParser::FunctionDeclarationContext*>(func->ctx);
            visitFieldDeclaration(fdc); // 遍历，代码生成到bodyAsm中了
            generateProcedure(func->getName(), sb);
        }
    }

    // 3. 对主程序生成_main函数
    visitProg((PlayScriptParser::ProgContext*)at_->ast) ;
    generateProcedure("main", sb);

    // 4. 文本字面量
    sb.append("\n# 字符串字面量\n");
    sb.append("\t.section	__TEXT,__cstring,cstring_literals\n");
    for (int i = 0; i < stringLiterals.size(); i++) {
        sb.append("L.str." + i + ":\n");
        sb.append("\t.asciz\t\"").append(stringLiterals[i]).append("\"\n");
    }

    // 5. 重置一些临时变量
    stringLiterals.clear();
    
    return sb;
}

// 生成过程体
void AsmGen::generateProcedure(string name, string sb)
{
    // 1. 函数标签
    sb.append("\n## 过程: ").append(name).append("\n");
    sb.append("\t.global _").append(name).append("\n");
    sb.append("_").append(name).append(":\n");

    // 2. 序曲
    sb.append("\n\t# 序曲\n")
    sb.append("\tpushq\t%rbp\n");
    sb.append("\tmovq\t%rsp, %rbp\n");

    // 3. 设置栈顶
    // 16字节对齐
    if ((rspOffset % 16) != 0) {
        rspOffset = (rspOffset / 16 + 1) * 16;
    }

    sb.append("\n\t# 设置栈顶\n");
    sb.append("\tsubq\t$").append(std::to_string(rspOffset)).append(", %rsp\n");

    // 4. 保存用到的寄存器的值
    saveRegisters();

    // 5. 函数体
    sb.append("\n\t# 过程体\n");
    sb.append(bodyAsm);

    // 6. 恢复受保护的寄存器的值
    restoreRegisters();

    // 7. 恢复栈顶
    sb.append("\n\t# 恢复栈顶\n");
    sb.append("\taddq\t$").append(std::to_string(rspOffset)).append(", %rsp\n");

    // 8. 如果是mian函数，设置返回值为0
    if (name == "main") {
        sb.append("\n\t# 返回值\n");
        sb.append("\txorl\t%eax, %eax\n");
    }

    // 尾声
    sb.append("\n\t# 尾声\n");
    sb.append("\tpopq\t%rbp\n");
    sb.append("\tretq");

    // 10. 重置临时变量
    rspOffset = 0;
    localVars.clear();
    tempVars.clear();
    bodyAsm.clear();
}

string allocForExpression(PlayScriptParser::ExpressionContext *ctx);

// 获取下一个可以的寄存器的索引
int getAvailableRegister();

string getStringLiteralAddress(string str);

/**
 * 保存调用者需要保护的寄存器
 * 前提，某个寄存器被用过
 */
void saveRegisters();

// 恢复被保护的寄存器
void restoreRegisters();