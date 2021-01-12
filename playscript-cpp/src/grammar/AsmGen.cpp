#include "AsmGen.h"
#include "AnnotatedTree.h"
#include "Function.h"
#include "Variable.h"
#include <algorithm>
#include <iterator>

using namespace play;

// 主控程序
string AsmGen::generate()
{
    string sb;
    // 1. 代码段的头
    sb.append("\t.section	__TEXT,__text,regular,pure_instructions\n");

    // 2. 生成函数的代码
    for (Type *type: at_->types) {
        Function *func = dynamic_cast<Function*>(type);
        if (func != nullptr) {
            PlayScriptParser::FunctionDeclarationContext *fdc = dynamic_cast<PlayScriptParser::FunctionDeclarationContext*>(func->ctx);
            visitFunctionDeclaration(fdc); // 遍历，代码生成到bodyAsm中了
            generateProcedure(func->getName(), sb);
        }
    }

    // 3. 对主程序生成_main函数
    AsmGen::visitProg((PlayScriptParser::ProgContext*)at_->ast) ;
    generateProcedure("main", sb);

    // 4. 文本字面量
    sb.append("\n# 字符串字面量\n");
    sb.append("\t.section	__TEXT,__cstring,cstring_literals\n");
    for (int i = 0; i < stringLiterals.size(); i++) {
        sb.append("L.str." + std::to_string(i) + ":\n");
        sb.append("\t.asciz\t\"").append(stringLiterals[i]).append("\"\n");
    }

    // 5. 重置一些临时变量
    stringLiterals.clear();
    
    return sb;
}

// 生成过程体
void AsmGen::generateProcedure(string name, string& sb)
{
    // 1. 函数标签
    sb.append("\n## 过程: ").append(name).append("\n");
    sb.append("\t.global _").append(name).append("\n");
    sb.append("_").append(name).append(":\n");

    // 2. 序曲
    sb.append("\n\t# 序曲\n");
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

string AsmGen::allocForExpression(PlayScriptParser::ExpressionContext *ctx)
{
    string rtn;

    // 复用前序表达式的存储位置
    if (ctx->bop != nullptr && ctx->expression().size() >= 2) {
        PlayScriptParser::ExpressionContext *left = ctx->expression(0);
        string leftAddress = tempVars[left];
        if (leftAddress.length() > 0) {
            tempVars[ctx] = leftAddress;
        }
    }

    int availableRegister = getAvailableRegister();
    if (availableRegister != -1) {
        rtn = registersl[availableRegister];
    } else {
        rspOffset += 4;
        rtn = "-" + std::to_string(rspOffset) + "%rbp";
    }
    tempVars[ctx] = rtn;
    return rtn;
}

// 获取下一个可以的寄存器的索引
int AsmGen::getAvailableRegister()
{
    int rtn = -1;
    map<string, ParserRuleContext*> reverseTempVars;
    for (auto it = tempVars.begin(); it != tempVars.end(); it++) {
        reverseTempVars[it->second] = it->first;
    }

    for (int i = 0; i < registersl.size(); i++) {
        string r = registersl[i];
        if (!reverseTempVars.count(r)) {
            rtn = i;
            break;
        }
    }
    return rtn;
}

string AsmGen::getStringLiteralAddress(string str)
{
    auto ret = std::find(stringLiterals.begin(), stringLiterals.end(), str);
    int index = (ret == stringLiterals.end() ? -1: std::distance(stringLiterals.end(), ret));
    if (index == -1) {
        stringLiterals.emplace_back(str);
        index = stringLiterals.size() - 1;
    }
    return "ref:L.str." + std::to_string(index) + "(%rip)";
}

/**
 * 保存调用者需要保护的寄存器
 * 前提，某个寄存器被用过
 */
void AsmGen::saveRegisters()
{

}

// 恢复被保护的寄存器
void AsmGen::restoreRegisters()
{

}


antlrcpp::Any AsmGen::visitProg(PlayScriptParser::ProgContext *ctx)
{
    return visitBlockStatements(ctx->blockStatements());
}

antlrcpp::Any AsmGen::visitBlockStatements(PlayScriptParser::BlockStatementsContext *ctx)
{
    string sb;
    antlrcpp::Any tmp;
    for (PlayScriptParser::BlockStatementContext *child: ctx->blockStatement()) {
        tmp = visitBlockStatement(child);
        if (tmp.is<string>()) {
            std::cout << "AsmGen::visitBlockStatements : " << tmp.as<string>() << std::endl;
            sb.append(tmp.as<string>());
        }
    }
    return sb;
}

antlrcpp::Any AsmGen::visitBlockStatement(PlayScriptParser::BlockStatementContext *ctx)
{
    string sb;
    antlrcpp::Any tmp;
    if (ctx->variableDeclarators() != nullptr) {
        tmp = visitVariableDeclarators(ctx->variableDeclarators());
    } else if (ctx->statement() != nullptr) {
        tmp = visitStatement(ctx->statement());
    }

    if (tmp.is<string>()) {
        std::cout << "AsmGen::visitBlockStatement: " <<  tmp.as<string>() << std::endl;
        sb.append(tmp.as<string>());
    }
    return sb;
}

antlrcpp::Any AsmGen::visitVariableDeclarators(PlayScriptParser::VariableDeclaratorsContext *ctx)
{
    string sb;
    antlrcpp::Any tmp;
    for (PlayScriptParser::VariableDeclaratorContext *child: ctx->variableDeclarator()) {
        tmp = visitVariableDeclarator(child);
        if (tmp.is<string>()) {
            sb.append(tmp.as<string>());
        }
    }
    return sb;
}

antlrcpp::Any AsmGen::visitVariableDeclarator(PlayScriptParser::VariableDeclaratorContext *ctx)
{
    antlrcpp::Any tmp = visitVariableDeclaratorId(ctx->variableDeclaratorId());
    string varAddress = tmp.is<string>() ? tmp.as<string>() : "";
    if (tmp.is<string>() && ctx->variableInitializer() != nullptr) {
       string value = visitVariableInitializer(ctx->variableInitializer());
       bodyAsm.append("\tmovl\t").append(value).append(", ").append(varAddress).append("\n");
    }
    return varAddress;
}

antlrcpp::Any AsmGen::visitVariableDeclaratorId(PlayScriptParser::VariableDeclaratorIdContext *ctx)
{
    rspOffset += 4; // 本地整型变量占4字节
    string rtn = "-" + std::to_string(rspOffset) + "(%rbp)";

    Symbol *symbol = at_->symbolOfNode[ctx];
    localVars[(Variable*)symbol] = rtn;

    return rtn;
}

antlrcpp::Any AsmGen::visitVariableInitializer(PlayScriptParser::VariableInitializerContext *ctx)
{
    string rtn = "";
    if (ctx->expression() != nullptr) {
        antlrcpp::Any tmp = visitExpression(ctx->expression());
        if (tmp.is<string>()) {
            rtn = tmp.as<string>();
        }
    }
    return rtn;
}

antlrcpp::Any AsmGen::visitExpression(PlayScriptParser::ExpressionContext *ctx)
{
    string address = "";
    antlrcpp::Any tmp;
    // 二元运算
    if (ctx->bop != nullptr && ctx->expression().size() >= 2) {
        string left = visitExpression(ctx->expression(0));
        string right = visitExpression(ctx->expression(1));

        // std::cout << "AsmGen::visitExpression/ left: " << left  << " / " << ctx->expression(0)->getText() << " | right: " << right << "/" << ctx->expression(1)->getText() << " | getType: " << ctx->bop->getType() << std::endl;

        switch (ctx->bop->getType()) {
            case PlayScriptParser::ADD:
                // 为加法运算申请一个临时变量，可以是寄存器和栈
                address = allocForExpression(ctx);
                if (address != left) {
                    bodyAsm.append("\tmov\t").append(left).append(", ").append(address).append("\n");
                }
                bodyAsm.append("\taddl\t").append(right).append(", ").append(address).append("\n");
                break;
            
            case PlayScriptParser::SUB:
                address = allocForExpression(ctx);
                bodyAsm.append("\tmovl\t").append(left).append(", ").append(address).append("\n");
                bodyAsm.append("\tsubl\t").append(right).append(", ").append(address).append("\n");
                break;
            
            case PlayScriptParser::ASSIGN:
                bodyAsm.append("\tmovl\t").append(right).append(", ").append(left).append("\n");
                break;
        }
    } else if (ctx->primary() != nullptr) {
        tmp = visitPrimary(ctx->primary());
    } else if (ctx->functionCall() != nullptr) {    // functionCall
        tmp = visitFunctionCall(ctx->functionCall());
    }

    if (tmp.is<string>()) {
        address = tmp.as<string>();
    }

    return address;
}

antlrcpp::Any AsmGen::visitPrimary(PlayScriptParser::PrimaryContext *ctx)
{
    string rtn = "";
    if (ctx->literal() != nullptr) {
        antlrcpp::Any tmp = visitLiteral(ctx->literal()); // 直接操作数
        if (tmp.is<string>()) {
            rtn = tmp.as<string>();
        }
    } else if (ctx->IDENTIFIER() != nullptr) {
        Symbol *symbol = at_->symbolOfNode[ctx];
        Variable *tmp = dynamic_cast<Variable*>(symbol);
        if (ctx->getText() == "c") {
            std::cout << "c here" << std::endl;
        }
        if (tmp != nullptr) {
            rtn = localVars[tmp];
        }
    }
    return rtn;
}

antlrcpp::Any AsmGen::visitLiteral(PlayScriptParser::LiteralContext *ctx)
{
    string rtn = "";
    if (ctx->integerLiteral() != nullptr) {
        antlrcpp::Any tmp = visitIntegerLiteral(ctx->integerLiteral());
        if (tmp.is<string>()) {
            rtn = tmp.as<string>();
        }
    } else if (ctx->STRING_LITERAL() != nullptr) {
        string withQuotationMark = ctx->STRING_LITERAL()->getText();
        withQuotationMark = withQuotationMark.substr(1, withQuotationMark.length() - 1);
        rtn = getStringLiteralAddress(withQuotationMark);
    }

    return rtn;
}

antlrcpp::Any AsmGen::visitIntegerLiteral(PlayScriptParser::IntegerLiteralContext *ctx)
{
    string rtn = "";
    if (ctx->DECIMAL_LITERAL() != nullptr) {
        rtn = "$" + ctx->DECIMAL_LITERAL()->getText();
    }
    return rtn;
}

antlrcpp::Any AsmGen::visitStatement(PlayScriptParser::StatementContext *ctx)
{
    string value = "";
    if (ctx->statementExpression != nullptr) {
        antlrcpp::Any tmp = visitExpression(ctx->statementExpression);
        if (tmp.is<string>()) {
            value = tmp.as<string>();
        }
    } else if (ctx->RETURN() != nullptr) {
        if (ctx->expression() != nullptr) {
            antlrcpp::Any tmp = visitExpression(ctx->expression());
            if (!tmp.is<string>()) {
                return value;
            }
            value = tmp.as<string>();
            // 在 %eax中设置返回值
            bodyAsm.append("\n\t# 返回值\n");
            if (value == "%eax") {
                bodyAsm.append("\t# 返回值在之前的计算中，已经存入%eax\n");
            } else {
                bodyAsm.append("\tmovl\t" + value + ", %eax\n");
            }
        }
    }
    return value;
}

antlrcpp::Any AsmGen::visitFunctionCall(PlayScriptParser::FunctionCallContext *ctx)
{
    string address = "%eax";    // 缺省获得返回值的地方

    string functionName;

    Symbol *symbol = at_->symbolOfNode[ctx];

    Function *func = dynamic_cast<Function*>(symbol);
    if (func != nullptr) {
        functionName = func->getName();
    } else {
        // TODO 临时代码，用于打印输出
        if (ctx->IDENTIFIER()->getText() == "println") {
            functionName = "printf";
        } else {
            at_->log("unable to find function" + ctx->IDENTIFIER()->getText(), ctx);
        }
    }

    // 设置参数
    if (ctx->expressionList() != nullptr) {
        int paramOffset = 0;
        int numParams = ctx->expressionList()->expression().size();

        // 1. 先计算所有参数的值，这个时候可能会引起栈的变化，用来存放临时变量
        int oldOffset = rspOffset;
        vector<string> values;
        antlrcpp::Any tmp;
        for (int i = 0; i < numParams; i++) {
            tmp = visitExpression(ctx->expressionList()->expression(i));
            if (tmp.is<string>()) {
                values.emplace_back(tmp.as<string>());
            }
        }

        int offset1 = rspOffset - oldOffset;

        // 2. 扩展栈
        if (numParams > 6) {
            paramOffset = 8 * (numParams - 6) + offset1;
            bodyAsm.append("\n\t # 为参数而扩展栈\n");
            bodyAsm.append("\tsubq\t$").append(std::to_string(paramOffset)).append(", %rsp\n");
        }

        // 3. 设置参数
        if (numParams > 0) {
            bodyAsm.append("\n\t# 设置参数\n");
        }

        string searchStr = "ref:";

        for (int i = 0; i < numParams; i++) {
            string value = values[i];
            string paramAddress = "";
            string prefix = value.substr(0, searchStr.length() - 1);

            if (i < 6) {
               
                if (searchStr == prefix) {
                    paramAddress = paramRegisterq[i];
                } else {
                    paramAddress = paramRegisterl[i];
                }
            } else {
                if (i == 6) {
                    paramAddress = "(%rsp)";
                } else {
                    paramAddress = "" + std::to_string((i - 6) * 8) + "(%rsp)";
                }
            }

            if (searchStr == prefix) {
                // 传地址
                bodyAsm.append("\tleaq\t").append(value.substr(0, 4)).append(",").append(paramAddress).append("\n");
            } else {
                bodyAsm.append("\tmovl\t").append(value).append(", ").append(paramAddress).append("\n");
            }
        }

        // 4. 调用函数
        bodyAsm.append("\n\t# 调用函数\n");
        bodyAsm.append("\tcallq\t_").append(functionName).append("\n");

        // 5. 恢复栈
        if (numParams > 6) {
            paramOffset = 8 * (numParams - 6);
            bodyAsm.append("\n\t# 收回参数的栈空间\n");
            bodyAsm.append("\taddq\t$").append(std::to_string(paramOffset)).append(", %rsp\n");
        }
    }

    return address;
}

antlrcpp::Any AsmGen::visitFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx)
{
    // 给所有参数确定地址
    Function *func = (Function*)at_->node2Scope[ctx];
    int len = func->parameters.size();
    for (int i = 0; i < len; i++) {
        if (i < 6) {
            // 少于6个参数，使用寄存器
            localVars[func->parameters[i]] = paramRegisterl[i];
        } else {
            int paramOffset = (i - 6) * 8 + 16; // 参数在栈中相对于%rbp的偏移量
            string paramAddress = "" + std::to_string(paramOffset) + "(%rbp)";
            localVars[func->parameters[i]] = paramAddress;
        }
    }

    return visitFunctionBody(ctx->functionBody());
}

antlrcpp::Any AsmGen::visitFunctionBody(PlayScriptParser::FunctionBodyContext *ctx)
{
    string value = "";
    if (ctx->block() != nullptr) {
        antlrcpp::Any tmp = visitBlock(ctx->block());
        if (tmp.is<string>()) {
            value = tmp.as<string>();
        }
    }
    return value;
}

antlrcpp::Any AsmGen::visitBlock(PlayScriptParser::BlockContext *ctx)
{
    return visitBlockStatements(ctx->blockStatements());
}

antlrcpp::Any AsmGen::visitExpressionList(PlayScriptParser::ExpressionListContext *ctx)
{
    return PlayScriptBaseVisitor::visitExpressionList(ctx);
}

antlrcpp::Any AsmGen::visitFormalParameter(PlayScriptParser::FormalParameterContext *ctx)
{
    return PlayScriptBaseVisitor::visitFormalParameter(ctx);
}

antlrcpp::Any AsmGen::visitFormalParameterList(PlayScriptParser::FormalParameterListContext *ctx)
{
    return PlayScriptBaseVisitor::visitFormalParameterList(ctx);
}

antlrcpp::Any AsmGen::visitFormalParameters(PlayScriptParser::FormalParametersContext *ctx)
{
    return PlayScriptBaseVisitor::visitFormalParameters(ctx);
}

antlrcpp::Any AsmGen::visitPrimitiveType(PlayScriptParser::PrimitiveTypeContext *ctx)
{
    return PlayScriptBaseVisitor::visitPrimitiveType(ctx);
}

antlrcpp::Any AsmGen::visitTypeType(PlayScriptParser::TypeTypeContext *ctx)
{
    return PlayScriptBaseVisitor::visitTypeType(ctx);
}