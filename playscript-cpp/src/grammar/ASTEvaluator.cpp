#include "ASTEvaluator.h"

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