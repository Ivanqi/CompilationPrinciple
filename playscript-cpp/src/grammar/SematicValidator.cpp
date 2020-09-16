#include "SematicValidator.h"
#include "AnnotatedTree.h"
#include "VoidType.h"
#include "Function.h"



using namespace play;

void SematicValidator::exitPrimary(PlayScriptParser::PrimaryContext *ctx)
{

}

void SematicValidator::exitFunctionCall(PlayScriptParser::FunctionCallContext *ctx)
{

}

void SematicValidator::exitExpression(PlayScriptParser::ExpressionContext *ctx)
{

}

void SematicValidator::exitClassDeclaration(PlayScriptParser::ClassDeclarationContext *ctx)
{
    // 04 类的声明不能在函数里
    if (at_->enclosingFunctionOfNode((RuleContext*)ctx) != NULL) {
        at_->log("can not declare class inside function", ctx);
    }
}

void SematicValidator::exitFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx)
{
    // 02-01 函数定义了返回值，就一定要有相应的return语句。
    //TODO 更完善的是要进行控制流计算，不是仅仅有一个return语句就行了
    if (ctx->typeTypeOrVoid() != NULL) {
        if (!hasReturnStatement(ctx)) {
            Type *returnType = at_->typeOfNode[ctx->typeTypeOrVoid()];
            if (!(returnType == VoidType::GetInstance())) {
                at_->log("return statment expected in function", ctx);
            }
        }
    }
}

// 检查一个函数里有没有return语句
bool SematicValidator::hasReturnStatement(ParseTree *ctx)
{
    bool rtn = false;
    for (int i = 0; i < ctx->children.size(); i++) {
        ParseTree *child = ctx->children[i];
        PlayScriptParser::StatementContext *tmp = dynamic_cast<PlayScriptParser::StatementContext*>(child);
        PlayScriptParser::FunctionDeclarationContext *tmp2 = dynamic_cast<PlayScriptParser::FunctionDeclarationContext*>(child);
        PlayScriptParser::ClassDeclarationContext *tmp3 = dynamic_cast<PlayScriptParser::ClassDeclarationContext*>(child);

        if (tmp != NULL && tmp->RETURN() != NULL) {
            rtn = true;
            break;
        }  else if (!(tmp2 != NULL || tmp3 != NULL)) {
            rtn = hasReturnStatement(child);
            if (rtn) {
                break;
            }
        }
    }
    return rtn;
}

void SematicValidator::exitVariableDeclarators(PlayScriptParser::VariableDeclaratorsContext *ctx)
{

}

void SematicValidator::exitVariableDeclarator(PlayScriptParser::VariableDeclaratorContext *ctx)
{

}

void SematicValidator::exitVariableDeclaratorId(PlayScriptParser::VariableDeclaratorIdContext *ctx)
{

}

//对变量初始化部分也做一下类型推断
void SematicValidator::exitVariableInitializer(PlayScriptParser::VariableInitializerContext *ctx)
{

}

// 根据字面量来推断类型 
void SematicValidator::exitLiteral(PlayScriptParser::LiteralContext *ctx)
{

}

void SematicValidator::exitStatement(PlayScriptParser::StatementContext *ctx)
{
    //02 类的构造函数不能有返回值
    if (ctx->RETURN() != NULL) {
        //02 - 03
        Function *function = at_->enclosingFunctionOfNode(ctx);
        if (function != NULL) {
            at_->log("return statement not in fountion body", ctx);
        } else if (function->isConstructor() && ctx->expression() != NULL) {
            // 02-02 构造函数不能有return语句
            at_->log("can not return a value from constructor", ctx);
        }
    } else if (ctx->BREAK() != NULL) {  // 01 break语句
        if (checkBreak(ctx)) {
            at_->log("break statement not in loop or switch statements", ctx);
        }
    }
}


// break只能出现在循环语句或switch-case语句里
bool SematicValidator::checkBreak(RuleContext *ctx)
{
    PlayScriptParser::StatementContext *tmp = dynamic_cast<PlayScriptParser::StatementContext*>(ctx->parent);
    PlayScriptParser::SwitchBlockStatementGroupContext *tmp2 = dynamic_cast<PlayScriptParser::SwitchBlockStatementGroupContext*>(ctx->parent);

    PlayScriptParser::FunctionDeclarationContext *tmp3 = dynamic_cast<PlayScriptParser::FunctionDeclarationContext*>(ctx->parent);

    if ((tmp != NULL && ((tmp->FOR() != NULL) || (tmp->WHILE() != NULL))) || tmp2 != NULL) {
        return true;
    } else if (ctx->parent != NULL || tmp3 != NULL) {
        return false;
    } else {
        return checkBreak((RuleContext*)ctx->parent);
    }
}