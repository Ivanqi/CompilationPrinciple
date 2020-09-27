#include "TypeChecker.h"
#include "AnnotatedTree.h"
#include "Variable.h"
#include "Type.h"
#include "PrimitiveType.h"
#include "Class.h"
#include "Function.h"
#include <stdio.h>

using namespace play;

void TypeChecker::exitVariableDeclarator(PlayScriptParser::VariableDeclaratorContext *ctx)
{
    if (ctx->variableInitializer() != nullptr) {
        Variable *variable = (Variable *)at_->symbolOfNode[ctx->variableDeclaratorId()];
        Type *type1 = variable->getType();
        Type *type2 = at_->typeOfNode[ctx->variableInitializer()];
        if (checkAssign(type1, type2, ctx, ctx->variableDeclaratorId(), ctx->variableInitializer())) {
            // at_->symbolOfNode[ctx] = at_->symbolOfNode[ctx->variableInitializer()];
            // at_->symbolOfNode[ctx->variableDeclaratorId()] = at_->symbolOfNode[ctx->variableInitializer()];
        } else {
            // printf("不需要赋值\n");
        }
    }
}

void TypeChecker::exitExpression(PlayScriptParser::ExpressionContext *ctx)
{
    // 二元表达式
    if (ctx->bop != nullptr && ctx->expression().size() >= 2) {
    
        // 左右两个子节点的类型
        Type *type1 = at_->typeOfNode[ctx->expression(0)];
        Type *type2 = at_->typeOfNode[ctx->expression(1)];

        switch (ctx->bop->getType()) {
            case PlayScriptParser::ADD:
                // 字符串能够跟任何对象做 + 运算
                if (type1 != PrimitiveType::String && type2 != PrimitiveType::String) {
                    checkNumericOperand(type1, ctx, ctx->expression(0));
                    checkNumericOperand(type2, ctx, ctx->expression(1));
                }
                break;

            case PlayScriptParser::SUB:
            case PlayScriptParser::MUL:
            case PlayScriptParser::DIV:
            case PlayScriptParser::LE:
            case PlayScriptParser::LT:
            case PlayScriptParser::GE:
            case PlayScriptParser::GT:
                checkNumericOperand(type1, ctx, ctx->expression(0));
                checkNumericOperand(type2, ctx, ctx->expression(1));
                break;
            case PlayScriptParser::EQUAL:
            case PlayScriptParser::NOTEQUAL:
                break;

            
            case PlayScriptParser::AND:
            case PlayScriptParser::OR:
                checkBooleanOperand(type1, ctx, ctx->expression(0));
                checkBooleanOperand(type2, ctx, ctx->expression(1));
                break;
            
            case PlayScriptParser::ASSIGN:
                checkAssign(type1, type2, ctx, ctx->expression(0), ctx->expression(1));
                break;
            
            case PlayScriptParser::ADD_ASSIGN:
            case PlayScriptParser::SUB_ASSIGN:
            case PlayScriptParser::MUL_ASSIGN:
            case PlayScriptParser::DIV_ASSIGN:
            case PlayScriptParser::AND_ASSIGN:
            case PlayScriptParser::OR_ASSIGN:
            case PlayScriptParser::XOR_ASSIGN:
            case PlayScriptParser::MOD_ASSIGN:
            case PlayScriptParser::LSHIFT_ASSIGN:
            case PlayScriptParser::RSHIFT_ASSIGN:
            case PlayScriptParser::URSHIFT_ASSIGN:
                if (PrimitiveType::isNumeric(type2)) {
                    if (!checkNumericAssign(type2, type1)) {
                        at_->log("can not assign " + ctx->expression(1)->getText() + " of type " + type2->getName() + " to " + ctx->expression(0)->getText() + " of type " + type1->getName(), ctx);
                    }
                }
                else{
                    at_->log("operand + " + ctx->expression(1)->getText() + " should be numeric。", ctx );
                }

                break;

        }
    }

    //TODO 对各种一元运算做类型检查，比如NOT操作
}

//对变量初始化部分也做一下类型推断
void TypeChecker::exitVariableInitializer(PlayScriptParser::VariableInitializerContext *ctx)
{
    // if (ctx->expression() != nullptr) {
    //     // 推断类型
    //     at_->typeOfNode[ctx] = at_->typeOfNode[ctx->expression()];

    //     Scope *scope = at_->enclosingScopeOfNode(ctx);
    //     // 设置variable
    //     if (scope != nullptr) {
    //         Variable *variable = at_->lookupVariable(scope, ctx->getText());
    //         if (variable == nullptr) {
    //             variable = new Variable(ctx->getText(), scope, ctx);
    //         }
    //         variable->setType(at_->typeOfNode[ctx]);
    //         at_->symbolOfNode[ctx] = variable; 
    //     }
    // }
}

/**
 * 检查类型是不是数值型
 */
void TypeChecker::checkNumericOperand(Type *type, PlayScriptParser::ExpressionContext *exp, PlayScriptParser::ExpressionContext *operand)
{
    if (!PrimitiveType::isNumeric(type)) {
        at_->log("operand for arithmetic operation should be numeric: " + operand->getText(), exp);
    }
}

/**
 * 检查是不是Boolean型
 */
void TypeChecker::checkBooleanOperand(Type *type, PlayScriptParser::ExpressionContext *exp, PlayScriptParser::ExpressionContext *operand)
{
    if (PrimitiveType::Boolean != type) {
        at_->log("operand for logical operation should be boolean: " + operand->getText(), exp);
    }
}


/**
 * 检查是否能做赋值操作
 * 看一个类型能否赋值成另一个类型，比如：
 *  1. 整型可以转成浮点型
 *  2. 子类的对象可以赋给父类
 *  3. 函数赋值，要求签名是一致的
 */
bool TypeChecker::checkAssign(Type *type1, Type *type2, ParserRuleContext *ctx, ParserRuleContext *operand1, ParserRuleContext *operand2)
{
    if (PrimitiveType::isNumeric(type2)) {
        if (!checkNumericAssign(type2, type1)) {
            at_->log("can not assign " + operand2->getText() 
                + " of type " + type2->getName() + " to " + operand1->getText() + " of type" + type1->getName(), ctx);
        } else {
            return true;
        }
    } else if (dynamic_cast<Class*>(type2) != nullptr) {
        //TODO 检查类的兼容性
    } else if (dynamic_cast<Function*>(type2) != nullptr) {
        //TODO 检查函数的兼容性
    }
    return false;
}

/**
 * 看一个类型能否赋值成另一个类型，比如：
 *  1. 整型可以转成浮点型
 *  2. 子类的对象可以赋给父类
 *  3. 函数赋值，要求签名是一致的
 */
bool TypeChecker::checkNumericAssign(Type *from, Type *to)
{
    bool canAssign = false;
    if (to == PrimitiveType::Double) {
        canAssign = (PrimitiveType::isNumeric(from));

    } else if (to == PrimitiveType::Float) {
        canAssign = (from == PrimitiveType::Byte || from == PrimitiveType::Short || 
            from == PrimitiveType::Long || from == PrimitiveType::Float);

    } else if (to == PrimitiveType::Long) {
        canAssign = (from == PrimitiveType::Byte || from == PrimitiveType::Short || 
            from == PrimitiveType::Integer || from == PrimitiveType::Long);
        
    } else if (to == PrimitiveType::Integer) {
        canAssign = (from == PrimitiveType::Byte || from == PrimitiveType::Byte ||
            from == PrimitiveType::Integer);

    } else if (to == PrimitiveType::Short) {
        canAssign = (from == PrimitiveType::Byte ||
            from == PrimitiveType::Short);
    } else if (to == PrimitiveType::Byte) {
        canAssign = (from == PrimitiveType::Byte);
    }

    return canAssign;
}
