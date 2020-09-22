#include "RefResolver.h"
#include "AnnotatedTree.h"
#include "Variable.h"
#include "Class.h"
#include "BlockScope.h"
#include "Function.h"
#include "Type.h"
#include "PrimitiveType.h"

using namespace play;

// 把本地变量加到符号表。本地变量必须边添加，边解析，不然先添加后解析，否则会引起消解的错误
void RefResolver::enterVariableDeclarators(PlayScriptParser::VariableDeclaratorsContext *ctx)
{
    Scope *scope = at_->enclosingScopeOfNode(ctx);
    if (dynamic_cast<BlockScope*> (scope) != nullptr) {
        typeResolverWalker.walk(localVariableEnter_, ctx);
    }
}

// 类型推断。S属性
void RefResolver::exitPrimary(PlayScriptParser::PrimaryContext *ctx)
{
    Scope *scope = at_->enclosingScopeOfNode(ctx);
    Type *type;

    // 标识符
    if (ctx->IDENTIFIER() != nullptr) {
        std::string idName = ctx->IDENTIFIER()->getText();

        Variable *variable = at_->lookupVariable(scope, idName);
        if (variable == nullptr) {
            /**
             * 看看是不是函数，因为函数可以作为值来传递。这个时候，函数重名没法区分。
             * 因为普通Scope中的函数是不可以重名的，所以这应该是没有问题的。  //TODO 但如果允许重名，那就不行了。
             * TODO 注意，查找function的时候，可能会把类的方法包含进去
             */
            Function *function = at_->lookupFunction(scope, idName);
            if (function != nullptr) {
                at_->symbolOfNode[ctx] = function;
                type = function; 
            } else {
                at_->log("unknown variable or function: " + idName, ctx);
            }
        } else {
            at_->symbolOfNode[ctx] = variable;
            type = variable->getType();
        }

    } else if (ctx->literal() != nullptr) {    // 字面量
        type = at_->typeOfNode[ctx->literal()];

    } else if (ctx->expression() != nullptr) { // 括号里的表达式
        type = at_->typeOfNode[ctx->expression()];

    } else if (ctx->THIS() != nullptr) {       // this 关键字
        // 找到Class类型的上级Scope
        Class *theClass = at_->enclosingClassOfNode(ctx);
        if (theClass != nullptr) {
            This *variable = theClass->getThis();
            at_->symbolOfNode[ctx] = (Symbol*)variable;

            type = theClass;
        } else {
            at_->log("keyword \"this\" can only be used inside a class", ctx);
        }
    }
    // } else if (ctx->SUPER() != nullptr) {  // super关键字。看上去跟This关键字的用法完全一样？
    //     // 找到Class类型的上级Scope
    //     Class *theClass = at_->enclosingClassOfNode(ctx);
    //     if (theClass != nullptr) {
    //         Super *variable = theClass->getSuper();
    //         at_->symbolOfNode[ctx] = variable;

    //         type = theClass;
    //     } else {
    //         at_->log("keyword \"super\" can only be used inside a class", ctx);
    //     }
    // }

    // 类型推断，冒泡. 
    at_->typeOfNode[ctx] = type;
}


void RefResolver::exitFunctionCall(PlayScriptParser::FunctionCallContext *ctx)
{
    // this
    if (ctx->THIS() != nullptr) {
        thisConstructorList.push_back(ctx);
        return;
    } else if (ctx->SUPER() != nullptr) {  // super
        superConstructorList.push_back(ctx);
        return;
    }

    // TODO 临时代码，支持println
    if (ctx->IDENTIFIER()->getText() == "println") {
        return;
    }

    std::string idName = ctx->IDENTIFIER()->getText();
    // 获得参数类型，这些类型已经在表达式中推断出来
    std::vector<Type*> paramTypes = getParamTypes(ctx);

    bool found = false;
    Class *theClass;

    // 看看是不是点符号表达式调用，调用的是类的方法
    PlayScriptParser::ExpressionContext *exp = dynamic_cast<PlayScriptParser::ExpressionContext*>(ctx->parent);
    if (exp != nullptr) {
        if (exp->bop && exp->bop->getType() == PlayScriptParser::DOT) {
            // TODO 派生类和父类的转换关系？
            Symbol *symbol = at_->symbolOfNode[exp->expression(0)];
            Variable *syTmp = static_cast<Variable*>(symbol);
            theClass = dynamic_cast<Class *>(syTmp->getType());

            if (syTmp != nullptr && theClass != nullptr) {
                
                // 查找名称和参数类型都匹配的函数。不允许名称和参数都相同，但返回值不同的情况
                Function *function = theClass->getFunction(idName, paramTypes);
                if (function != nullptr) {
                    found = true;
                    at_->symbolOfNode[ctx] = function;
                    at_->typeOfNode[ctx] = function->getReturnType();
                } else {
                    Variable *funcVar = theClass->getFunctionVariable(idName, paramTypes);
                    if (funcVar != nullptr) {
                        found = true;
                        at_->symbolOfNode[ctx] = funcVar;
                        at_->typeOfNode[ctx] = ((FunctionType*)funcVar->getType())->getReturnType();
                    } else {
                        at_->log("unable to find method " + idName + " in Class " + theClass->getName(), exp);
                    }
                }
            } else {
                at_->log("unable to resolve a class", ctx);
            }
        } 
    }

    Scope *scope = at_->enclosingScopeOfNode(ctx);

    // 从当前Scope逐级查找函数(或方法)
    if (!found) {
        Function *function = at_->lookupFunction(scope, idName, paramTypes);
        // 寻找对应的函数(方法)
        if (function != nullptr) {
            found = true;
            // 设置新的节点
            at_->symbolOfNode[ctx] = function;
            // 设置新节点的返回值类型
            at_->typeOfNode[ctx] = function->getReturnType();
        }
    }

    if (!found) {
        // 看看是不是类的构建函数，用相同的名称查找一个class
        Class *theClass = at_->lookupClass(scope, idName);
        if (theClass != nullptr) {

            Function *function = theClass->findConstructos(paramTypes);
            if (function != nullptr) {
                found = true;
                at_->symbolOfNode[ctx] = function;
            } else if (ctx->expressionList() == nullptr) { // 如果是与类名相同的方法，并且没有参数，那么就是缺省构造方法
                found = true;
                at_->symbolOfNode[ctx] = (Symbol*)theClass->defaultConstructor();
            } else {
                at_->log("unknown class constructor: " + ctx->getText(), ctx);
            }

            at_->typeOfNode[ctx] = theClass;    // 这次函数调用是返回一个对象

        } else {    // 看看是不是一个函数型的变量

            Variable *variable = at_->lookupFunctionVariable(scope, idName, paramTypes);
            FunctionType *tmp = variable != nullptr ? dynamic_cast<FunctionType*> (variable->getType()) : nullptr;

            if (variable != nullptr && tmp != nullptr) {
                found = true;
                at_->symbolOfNode[ctx] = variable;
                at_->typeOfNode[ctx] = variable->getType(); 
            } else {
                at_->log("unknown function or function variable: " + ctx->getText(), ctx);
            }
        }
    }
}


std::vector<Type*> RefResolver::getParamTypes(PlayScriptParser::FunctionCallContext* ctx)
{
    std::vector<Type*> paramTypes;
    if (ctx->expressionList() != nullptr) {
        for (PlayScriptParser::ExpressionContext *exp : ctx->expressionList()->expression()) {
            Type *type = at_->typeOfNode[exp];
            paramTypes.push_back(type);
        }
    }

    return paramTypes;
}

// 消解this()的构造函数
void RefResolver::resolveThisConstructorCall(PlayScriptParser::FunctionCallContext *ctx)
{
    Class *theClass = at_->enclosingClassOfNode(ctx);

    if (theClass != nullptr) {
        Function *function = at_->enclosingFunctionOfNode(ctx);
        if (function != nullptr && function->isConstructor()) {
            // 检查是不是构造函数中的第一句
            PlayScriptParser::FunctionDeclarationContext *fdx = (PlayScriptParser::FunctionDeclarationContext*)function->ctx;

            if (!firstStatmentInFunction(fdx, ctx)) {
                at_->log("this() must be first statement in a constructor", ctx);
                return;
            }

            std::vector<Type*> paramTypes = getParamTypes(ctx); 
            Function *refered = theClass->findConstructos(paramTypes);

            if (refered != nullptr) {
                at_->symbolOfNode[ctx] = refered;
                at_->typeOfNode[ctx] = theClass;
                at_->thisConstructorRef[function] = refered;

            } else if (paramTypes.size() == 0) {    // 缺省构造函数
                at_->symbolOfNode[ctx] = (Symbol*)theClass->defaultConstructor();
                at_->typeOfNode[ctx] = theClass;
                at_->thisConstructorRef[function] = (Function*)theClass->defaultConstructor();
            } else {
                at_->log("can not find a constructor matches this()", ctx);
            }
        } else {
            at_->log("this() should only be called inside a class costructor", ctx);
        }
    } else {
        at_->log("this() should only be called inside a class", ctx);
    }
}

bool RefResolver::firstStatmentInFunction(PlayScriptParser::FunctionDeclarationContext *fdx, PlayScriptParser::FunctionCallContext *ctx)
{
    if (fdx->functionBody()->block()->blockStatements()->blockStatement(0)->statement() != nullptr 
        && fdx->functionBody()->block()->blockStatements()->blockStatement(0)->statement()->expression() != nullptr
        && fdx->functionBody()->block()->blockStatements()->blockStatement(0)->statement()->expression()->functionCall() == ctx)
    {
        return true;
    }

    return false;
}

/**
 * 消解Super()构造函数
 * TODO 对于调用super()是有要求的，比如：
 *  1)必须出现在构造函数的第一行，
 *  2)this()和super不能同时出现，等等。
 */
void RefResolver::resolveSuperConstructorCall(PlayScriptParser::FunctionCallContext *ctx)
{
    Class *theClass = at_->enclosingClassOfNode(ctx);
    if (theClass != nullptr) {
        Function *function = at_->enclosingFunctionOfNode(ctx);
        
        if (function != nullptr && function->isConstructor()) {
            Class *parentClass = theClass->getParentClass();
            if (parentClass != nullptr) {
                // 检查是不是构造函数中的第一句
                PlayScriptParser::FunctionDeclarationContext *fdx = (PlayScriptParser::FunctionDeclarationContext*)function->ctx;
                if (!firstStatmentInFunction(fdx, ctx)) {
                    at_->log("super() must be first statement in a constructor", ctx);
                    return;
                }

                std::vector<Type*> paramTypes = getParamTypes(ctx);
                Function *refered = parentClass->findConstructos(paramTypes);
                if (refered != nullptr) {
                    at_->symbolOfNode[ctx] = refered;
                    at_->typeOfNode[ctx] = theClass;
                    at_->superConstructorRef[function] = refered;

                } else if (paramTypes.size() == 0) {    // 缺省构造函数
                    at_->symbolOfNode[ctx] = (Symbol*)theClass->defaultConstructor();
                    at_->typeOfNode[ctx] = theClass;
                    at_->superConstructorRef[function] = (Function*)theClass->defaultConstructor();

                } else {
                    at_->log("can not find a constructor matches this()", ctx);
                }
            } else {    // 父类是最顶层的基类。
                //TODO 这里暂时不处理
            }
        } else {
            at_->log("super() should only be called inside a class constructor", ctx);
        }
    } else {
        at_->log("super() should only be called inside a class", ctx);
    }
}

// 消解处理点符号表达式的层层引用
void RefResolver::exitExpression(PlayScriptParser::ExpressionContext *ctx)
{
    Type *type;

    if (ctx->bop != nullptr && ctx->bop->getType() == PlayScriptParser::DOT) {
        // 这是个左递归，要不断的把左边的节点的计算结果存到node2Symbol，所以要在exitExpression里操作
        Symbol *symbol = at_->symbolOfNode[ctx->expression(0)];
        
        Variable *syTmp = static_cast<Variable*>(symbol);
        Class *theClass = dynamic_cast<Class *>(syTmp->getType());
        
        if (syTmp != nullptr && theClass != nullptr) {
            // 引用类的属性
            if (ctx->IDENTIFIER() != nullptr) {
                std::string idName = ctx->IDENTIFIER()->getText();
                Variable *variable = at_->lookupVariable(theClass, idName); // 在类的scope里去查找，不需要改变当前的scope

                if (variable != nullptr) {
                    at_->symbolOfNode[ctx] = variable;
                    type = variable->getType(); // 类型综合(冒泡)
                } else {
                    at_->log("unable to find field " + idName + " in Class " + theClass->getName(), ctx);
                }
            } else if (ctx->functionCall() != nullptr) {   // 引用类的方法
                type = at_->typeOfNode[ctx->functionCall()];
            }
        } else {
            at_->log("symbol is not a qualified object: " + symbol->getName(), ctx);
        }
    } else if (ctx->primary() != nullptr) {
        /**
         * 变量引用冒泡： 如果下级是一个变量，往上冒泡传递，以便在点符号表达式中使用
         * 也包括This和Super的冒泡
         */
        Symbol *symbol = at_->symbolOfNode[ctx->primary()];
        at_->symbolOfNode[ctx] = symbol;
    }

    // 类型推断和综合
    if (ctx->primary() != nullptr) {
        type = at_->typeOfNode[ctx->primary()];

    } else if (ctx->functionCall() != nullptr) {
        type = at_->typeOfNode[ctx->functionCall()]; 

    } else if (ctx->bop != nullptr && ctx->expression().size() >= 2) {
        Type *type1 = at_->typeOfNode[ctx->expression(0)];
        Type *type2 = at_->typeOfNode[ctx->expression(1)];

        PrimitiveType *tmp1;
        PrimitiveType *tmp2;

        switch (ctx->bop->getType()) {
            case PlayScriptParser::ADD:
                tmp1 = dynamic_cast<PrimitiveType *> (type1);
                tmp2 = dynamic_cast<PrimitiveType *> (type2);
                if (type1 == PrimitiveType::String || type2 == PrimitiveType::String) {
                    type = PrimitiveType::String;
                } else if (tmp1 != nullptr && tmp2 != nullptr) {
                    // 类型“向上”对齐，比如一个int和一个float，取float
                    type = PrimitiveType::getUpperType(type1, type2);
                } else {
                    at_->log("operand should be PrimitiveType for additive and multiplicative operation", ctx);
                }
                break;

            case PlayScriptParser::SUB:
            case PlayScriptParser::MUL:
            case PlayScriptParser::DIV:
                tmp1 = dynamic_cast<PrimitiveType *> (type1);
                tmp2 = dynamic_cast<PrimitiveType *> (type2);
                if (tmp1 != nullptr && tmp2 != nullptr) {
                    // 类型“向上”对齐，比如一个int和一个float，取float
                    type = PrimitiveType::getUpperType(type1, type2);
                } else {
                    at_->log("operand should be PrimitiveType for additive and multiplicative operation", ctx);
                }
                break;

            case PlayScriptParser::EQUAL:
            case PlayScriptParser::NOTEQUAL:
            case PlayScriptParser::LE:
            case PlayScriptParser::LT:
            case PlayScriptParser::GE:
            case PlayScriptParser::GT:
            case PlayScriptParser::AND:
            case PlayScriptParser::OR:
            case PlayScriptParser::BANG:
                type = PrimitiveType::Boolean;
                break;
                
            case PlayScriptParser::ASSIGN:
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
                type = type1;
                break;
        }
    }

    //类型冒泡
    at_->typeOfNode[ctx] = type;
}