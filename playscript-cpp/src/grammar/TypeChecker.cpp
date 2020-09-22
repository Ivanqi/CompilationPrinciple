#include "TypeChecker.h"
#include "AnnotatedTree.h"
#include "Variable.h"
#include "Type.h"
#include "PrimitiveType.h"
#include "Class.h"
#include "Function.h"

using namespace play;

void TypeChecker::exitVariableDeclarator(PlayScriptParser::VariableDeclaratorContext *ctx)
{
    if (ctx->variableInitializer() != nullptr) {
        Variable *variable = (Variable *)at_->symbolOfNode[ctx->variableDeclaratorId()];
        Type *type1 = variable->getType();
        Type *type2 = at_->typeOfNode[ctx->variableInitializer()];
        checkAssign(type1, type2, ctx, ctx->variableDeclaratorId(), ctx->variableInitializer());
    }
}

// 检查是否能做赋值操作
void TypeChecker::checkAssign(Type *type1, Type *type2, ParserRuleContext *ctx, ParserRuleContext *operand1, ParserRuleContext *operand2)
{
    if (PrimitiveType::isNumeric(type2)) {
        if (!checkNumericAssign(type2, type1)) {
            at_->log("can not assign " + operand2->getText() 
                + " of type " + type2->getName() + " to " + operand1->getText() + " of type" + type1->getName(), ctx);
        }
    } else if (dynamic_cast<Class*>(type2) != nullptr) {
        //TODO 检查类的兼容性
    } else if (dynamic_cast<Function*>(type2) != nullptr) {
        //TODO 检查函数的兼容性
    }
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
