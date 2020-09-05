#include "ASTEvaluator.h"
#include "FunctionObject.h"
#include <iostream>
/**
 * 栈帧入栈
 * 其中最重要的任务，是要保证栈帧的parentFrame设置正确，否则
 * 1. 随着栈的变深，查找变量的性能降低
 * 2. 甚至有可能找错栈帧，比如在递归(直接或间接)的场景下
 */
void ASTEvaluator::pushStack(StackFrame *frame)
{
    if (stacks.size() > 0) {
        //从栈顶到栈底依次查找
        for (int i = stacks.size() - 1; i > 0; i--) {
            StackFrame *f = stacks.back();

            FunctionObject *functionObject = dynamic_cast<FunctionObject*>(frame->object);
            /*
                如果新加入的栈桢，跟某个已有的栈桢的enclosingScope是一样的，那么这俩的parentFrame也一样。
                因为它们原本就是同一级的嘛。
                比如：
                void foo(){};
                void bar(foo());
                或者：
                void foo();
                if (...){
                    foo();
                }
            */
            if (f->scope->getEnclosingScope() == frame->scope->getEnclosingScope()) {
                frame->parentFrame = f->parentFrame;
                break;
            } else if (f->scope == frame->scope->getEnclosingScope()){
                /*
                    如果新加入的栈桢，是某个已有的栈桢的下一级，那么就把把这个父子关系建立起来。比如：
                    void foo(){
                        if (...){  //把这个块往栈桢里加的时候，就符合这个条件。
                        }
                    }
                    再比如,下面的例子:
                    class MyClass{
                        void foo();
                    }
                    MyClass c = MyClass();  //先加Class的栈桢，里面有类的属性，包括父类的
                    c.foo();                //再加foo()的栈桢
                */
                f->parentFrame = f;
                break;
            } else if (functionObject != NULL) {
                if (functionObject->getReceiver() != NULL && functionObject->getReceiver()->getEnclosingScope() == f->scope) {
                    frame->parentFrame = f;
                    break;
                }
            }
        }

        if (frame->parentFrame == NULL) {
            frame->parentFrame = stacks.top();
            stacks.pop();
        }
    }

    stacks.push(frame);

    if (traceStackFrame) {
        dumpStackFrame();
    }
}

void ASTEvaluator::dumpStackFrame()
{
    std::cout << "\nStack Frames ----------------" << std::endl;
    for (StackFrame *frame: stacks) {
        std::cout << frame->toString() << std::endl;;
    }
    std::cout << "-----------------------------\n" << std::endl;
}

/**
 * ExpressionContext 是 AST中表达式的节点
 *  也叫做Context,意思是你能从中取出这个节点所有上下文信息，包括父节点，子节点
 *  其中，每个子节点的名称跟语法中的名称是一致的，比如 加减法语法规则
 *      expression bop=('+'|'-') expression
 * 
 * ExpressionContext(ctx) 解释
 *  ctx->expression();  返回一个列表，里面有两个成员，分别是左右两边的子节点
 *  ctx->expression(0); 运算符左边的表达式，是另一个ExpressionContext对象
 *  ctx->expression(1); 运算符右边的表达式
 *  ctx->bop();         一个Token对象，其类型是PlayScriptParser::ADD或者SUB
 *  ctx::ADD;         访问ADD终结符，当做加法运算的时候，该方法返回非空值
 *  ctx::MINUS();       访问MINUS终结符
 */
antlrcpp::Any ASTEvaluator::visitExpression(PlayScriptParser::ExpressionContext *ctx)
{
    // 二元表达式
    if (ctx->bop && ctx->expression().size() >= 2) {
        int L = visitExpression(ctx->expression(0));
        int R = visitExpression(ctx->expression(1));

        int result = 0;
        if (ctx->bop->getType() == PlayScriptParser::ADD) {
            result = L + R;
        } else if (ctx->bop->getType() == PlayScriptParser::SUB) {
            result = L - R;
        } else if (ctx->bop->getType() == PlayScriptParser::MUL) {
            result = L * R;
        } else if (ctx->bop->getType() == PlayScriptParser::DIV) {
            result = L / R;
        }

        std::cout << "L: " << L << " ,R: " << R << " ,result: " << result << std::endl;
        return result;
    } else if (ctx->primary()) {
        return visitPrimary(ctx->primary());
    }

    return nullptr;
}

antlrcpp::Any ASTEvaluator::visitPrimary(PlayScriptParser::PrimaryContext *ctx)
{
    if (ctx->literal()) {
        return visitLiteral(ctx->literal());
    }
    return nullptr;
}

antlrcpp::Any ASTEvaluator::visitLiteral(PlayScriptParser::LiteralContext *ctx)
{
    if (ctx->integerLiteral()) {
        return visitIntegerLiteral(ctx->integerLiteral());
    }
    return nullptr;
}

antlrcpp::Any ASTEvaluator::visitIntegerLiteral(PlayScriptParser::IntegerLiteralContext *ctx)
{
    return std::stoi(ctx->getText());
}

antlrcpp::Any ASTEvaluator::visitFloatLiteral(PlayScriptParser::FloatLiteralContext *ctx)
{
    return std::stof(ctx->getText());
}