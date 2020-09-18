#include "ASTEvaluator.h"
#include "FunctionObject.h"
// #include "Variable.h"
#include "MyLValue.h"
#include "ClassObject.h"
#include "Class.h"
#include "PrimitiveType.h"

#include <iostream>

using namespace play;

/**
 * 栈帧入栈
 * 其中最重要的任务，是要保证栈帧的parentFrame设置正确，否则
 * 1. 随着栈的变深，查找变量的性能降低
 * 2. 甚至有可能找错栈帧，比如在递归(直接或间接)的场景下
 */
void ASTEvaluator::pushStack(StackFrame *frame)
{
    // if (stacks.size() > 0) {
    //     //从栈顶到栈底依次查找
    //     Stack<StackFrame*>::reverse_iterator it;
    //     for (it = stacks.rbegin(); it != stacks.rend(); it++) {
    //         StackFrame *f = *it;

    //         FunctionObject *functionObject = dynamic_cast<FunctionObject*>(frame->object_);
    //         /*
    //             如果新加入的栈桢，跟某个已有的栈桢的enclosingScope是一样的，那么这俩的parentFrame也一样。
    //             因为它们原本就是同一级的嘛。
    //             比如：
    //             void foo(){};
    //             void bar(foo());
    //             或者：
    //             void foo();
    //             if (...){
    //                 foo();
    //             }
    //         */
    //         if (f->scope_->getEnclosingScope() == frame->scope_->getEnclosingScope()) {
    //             frame->parentFrame_ = f->parentFrame_;
    //             break;
    //         } else if (f->scope_ == frame->scope_->getEnclosingScope()){
    //             /*
    //                 如果新加入的栈桢，是某个已有的栈桢的下一级，那么就把把这个父子关系建立起来。比如：
    //                 void foo(){
    //                     if (...){  //把这个块往栈桢里加的时候，就符合这个条件。
    //                     }
    //                 }
    //                 再比如,下面的例子:
    //                 class MyClass{
    //                     void foo();
    //                 }
    //                 MyClass c = MyClass();  //先加Class的栈桢，里面有类的属性，包括父类的
    //                 c.foo();                //再加foo()的栈桢
    //             */
    //             f->parentFrame_ = f;
    //             break;
    //         } else if (functionObject != NULL) {
    //             if (functionObject->getReceiver() != NULL && functionObject->getReceiver()->getEnclosingScope() == f->scope_) {
    //                 frame->parentFrame_ = f;
    //                 break;
    //             }
    //         }
    //     }

    //     if (frame->parentFrame_ == NULL) {
    //         frame->parentFrame_ = stacks.top();
    //         stacks.pop();
    //     }
    // }

    // stacks.push(frame);

    // if (traceStackFrame) {
    //     dumpStackFrame();
    // }
}

void ASTEvaluator::popStack()
{
    stacks.pop();
}

void ASTEvaluator::dumpStackFrame()
{
    std::cout << "\nStack Frames ----------------" << std::endl;

    Stack<StackFrame*>::iterator it;
    for (it = stacks.begin(); it != stacks.end(); it++) {
        std::cout << (*it)->toString() << std::endl;
    }

    std::cout << "-----------------------------\n" << std::endl;
}

LValue* ASTEvaluator::getLValue(Variable *variable)
{
    StackFrame *f = stacks.top();
    PlayObject *valueContainer;

    while (f != NULL) {
        if (f->scope_->containsSymbol(variable)) {  // 对于对象来说，会查找所有父类属性
            valueContainer = f->object_;
            break;
        }
    }

    // 通过正常的作用域找不到，就从闭包里找
    // 原理：PlayObject中可能有一些变量，其作用域跟StackFrame.scope是不同的
    if (valueContainer == NULL) {
        f = stacks.top();
        while (f != NULL) {
            if (f->contains(variable)) {
                valueContainer = f->object_;
                break;
            }
            f = f->parentFrame_;
        }
    }

    MyLValue *lvalue = new MyLValue(valueContainer, variable);

    return lvalue;
}

/**
 * 为闭包获取环境变量的值
 * @param function 闭包所关联的函数。这个函数会访问一些环境变量
 * @param valueContainer 存放环境变量的值的容器
 */
void ASTEvaluator::getClosureValues(Function *function, PlayObject *valueContainer)
{
    if (function->closureVariables.size() > 0) {
        for (Variable *var : function->closureVariables) {
            LValue *lValue = getLValue(var); // 现在还可以从栈里取，退出函数以后就不行了
            antlrcpp::Any value = lValue->getValue();
            valueContainer->fields[var] = value;
        }
    }
}

// 为从函数中返回的对象设置闭包值。因为多个函数型属性可能共享值，所以要打包到ClassObject中，而不是functionObject中
void ASTEvaluator::getClosureValues(ClassObject *classObject)
{
    // 先放在一个临时对象里，避免对classObject即读又写
    PlayObject *tempObject = new PlayObject();

    for (auto it = classObject->fields.begin(); it != classObject->fields.end(); ++it) {
        FunctionType *tmp = dynamic_cast<FunctionType*>(it->first->type());
        if (tmp != NULL) {
            antlrcpp::Any object = classObject->fields[it->first];
            if (object != NULL) {
                FunctionObject *functionObject = static_cast<FunctionObject*>(object);
                getClosureValues(functionObject->function, tempObject);
            }
        }
    }

    classObject->fields.insert(tempObject->fields.begin(), tempObject->fields.end());
}

 // 从父类到子类层层执行缺省的初始化方法，即不带参数的初始化方法
ClassObject* ASTEvaluator::createAndInitClassObject(Class *theClass)
{
    ClassObject *obj = new ClassObject();
    obj->type = theClass;

    Stack<Class*> ancestorChain;

    // 从上到下执行缺省的初始化方法
    ancestorChain.push(theClass);
    while (theClass->getParentClass() != NULL) {
        ancestorChain.push(theClass->getParentClass());
        theClass = theClass->getParentClass();
    }

    // 执行缺省的初始化方法
    StackFrame *frame = new StackFrame(obj);
    pushStack(frame);
    while (ancestorChain.size() > 0) {
        Class *c = ancestorChain.pop();
        defaultObjectInit(c, obj);
    }

    popStack();

    return obj;
}

// 类的缺省初始化方法
void ASTEvaluator::defaultObjectInit(Class *theClass, ClassObject *obj)
{
    for (Symbol *symbol : theClass->symbols) {
        // 把变量加到obj里，缺省先都初始化成NULL，不允许有未初始化的
        Variable *tmp = dynamic_cast<Variable*>(symbol);
        if (tmp != NULL) {
            obj->fields[tmp] = NULL;
        }
    }

    // 执行缺省初始化
    PlayScriptParser::ClassBodyContext *ctx = ((PlayScriptParser::ClassDeclarationContext*)theClass->ctx)->classBody();
    visitClassBody(ctx);

    //TODO 其实这里还没干完活。还需要调用显式声明的构造方法
}

// 自己硬编码的println方法
void ASTEvaluator::println(PlayScriptParser::FunctionCallContext *ctx)
{
    if (ctx->expressionList() != NULL) {
        antlrcpp::Any value = visitExpression(ctx->expressionList());
        LValue *tmp = value.as<LValue*>();
        if (tmp != NULL) {
            value = tmp->getValue();
        }

        std::cout << value.as<sring>() << std::endl;
    }
}

antlrcpp::Any ASTEvaluator::add(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType)
{
    antlrcpp::Any rtn = NULL;

    if (targetType == PrimitiveType::String) {
        rtn = obj1.as<string>() + obj2.as<string>();

    } else if (targetType == PrimitiveType::Integer) {
        rtn = obj1.as<int>() + obj2.as<int>();

    } else if (targetType == PrimitiveType::Float) {
        rtn = obj1.as<float>() + obj2.as<float>();

    } else if (targetType == PrimitiveType::Long) {
        rtn = obj1.as<long>() + obj2.as<long>();

    } else if (targetType == PrimitiveType::Double) {
        rtn = obj1.as<double>() + obj2.as<double>();

    } else if (targetType == PrimitiveType::Short) {
        rtn = obj1.as<short>() + obj2.as<short>();
    } else {
        cout << "unsupported add operation" << endl;
    }

    return rtn;

}

antlrcpp::Any ASTEvaluator::minus(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType)
{
    antlrcpp::Any rtn = NULL;

    if (targetType == PrimitiveType::Integer) {
        rtn = obj1.as<int>() - obj2.as<int>();

    } else if (targetType == PrimitiveType::Float) {
        rtn = obj1.as<float>() - obj2.as<float>();

    } else if (targetType == PrimitiveType::Long) {
        rtn = obj1.as<long>() - obj2.as<long>();

    } else if (targetType == PrimitiveType::Double) {
        rtn = obj1.as<double>() - obj2.as<double>();

    } else if (targetType == PrimitiveType::Short) {
        rtn = obj1.as<short>() - obj2.as<short>();
    } else {
        cout << "unsupported minus operation" << endl;
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::mul(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType)
{
    antlrcpp::Any rtn = NULL;

    if (targetType == PrimitiveType::Integer) {
        rtn = obj1.as<int>() * obj2.as<int>();

    } else if (targetType == PrimitiveType::Float) {
        rtn = obj1.as<float>() * obj2.as<float>();

    } else if (targetType == PrimitiveType::Long) {
        rtn = obj1.as<long>() * obj2.as<long>();

    } else if (targetType == PrimitiveType::Double) {
        rtn = obj1.as<double>() * obj2.as<double>();

    } else if (targetType == PrimitiveType::Short) {
        rtn = obj1.as<short>() * obj2.as<short>();
    } else {
        cout << "unsupported mul operation" << endl;
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::div(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType)
{
    antlrcpp::Any rtn = NULL;

    if (targetType == PrimitiveType::Integer) {
        rtn = obj1.as<int>() / obj2.as<int>();

    } else if (targetType == PrimitiveType::Float) {
        rtn = obj1.as<float>() / obj2.as<float>();

    } else if (targetType == PrimitiveType::Long) {
        rtn = obj1.as<long>() / obj2.as<long>();

    } else if (targetType == PrimitiveType::Double) {
        rtn = obj1.as<double>() / obj2.as<double>();

    } else if (targetType == PrimitiveType::Short) {
        rtn = obj1.as<short>() / obj2.as<short>();
    } else {
        cout << "unsupported div operation" << endl;
    }

    return rtn;
}

bool ASTEvaluator::EQ(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType)
{
    bool rtn = NULL;

    if (targetType == PrimitiveType::Integer) {
        rtn = obj1.as<int>() == obj2.as<int>();

    } else if (targetType == PrimitiveType::Float) {
        rtn = obj1.as<float>() == obj2.as<float>();

    } else if (targetType == PrimitiveType::Long) {
        rtn = obj1.as<long>() == obj2.as<long>();

    } else if (targetType == PrimitiveType::Double) {
        rtn = obj1.as<double>() == obj2.as<double>();

    } else if (targetType == PrimitiveType::Short) {
        rtn = obj1.as<short>() ==  obj2.as<short>();
    } else {
        // 对于对象实例，函数，直接比较对象引用
        rtn = obj1 == obj2;
    }

    return rtn;
}

bool ASTEvaluator::GE(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType)
{
    bool rtn = NULL;

    if (targetType == PrimitiveType::Integer) {
        rtn = obj1.as<int>() >= obj2.as<int>();

    } else if (targetType == PrimitiveType::Float) {
        rtn = obj1.as<float>() >= obj2.as<float>();

    } else if (targetType == PrimitiveType::Long) {
        rtn = obj1.as<long>() >= obj2.as<long>();

    } else if (targetType == PrimitiveType::Double) {
        rtn = obj1.as<double>() >= obj2.as<double>();

    } else if (targetType == PrimitiveType::Short) {
        rtn = obj1.as<short>() >= obj2.as<short>();
    } else {
        cout << "unsupported GE operation" << endl;
    }

    return rtn;
}

bool ASTEvaluator::GT(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType)
{
    bool rtn = NULL;

    if (targetType == PrimitiveType::Integer) {
        rtn = obj1.as<int>() > obj2.as<int>();

    } else if (targetType == PrimitiveType::Float) {
        rtn = obj1.as<float>() > obj2.as<float>();

    } else if (targetType == PrimitiveType::Long) {
        rtn = obj1.as<long>() > obj2.as<long>();

    } else if (targetType == PrimitiveType::Double) {
        rtn = obj1.as<double>() > obj2.as<double>();

    } else if (targetType == PrimitiveType::Short) {
        rtn = obj1.as<short>() > obj2.as<short>();
    } else {
        cout << "unsupported GT operation" << endl;
    }

    return rtn;
}

bool ASTEvaluator::LE(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType)
{
    bool rtn = NULL;

    if (targetType == PrimitiveType::Integer) {
        rtn = obj1.as<int>() < obj2.as<int>();

    } else if (targetType == PrimitiveType::Float) {
        rtn = obj1.as<float>() < obj2.as<float>();

    } else if (targetType == PrimitiveType::Long) {
        rtn = obj1.as<long>() < obj2.as<long>();

    } else if (targetType == PrimitiveType::Double) {
        rtn = obj1.as<double>() < obj2.as<double>();

    } else if (targetType == PrimitiveType::Short) {
        rtn = obj1.as<short>() < obj2.as<short>();
    } else {
        cout << "unsupported LE operation" << endl;
    }

    return rtn;
}


antlrcpp::Any ASTEvaluator::visitClassBody(PlayScriptParser::ClassBodyContext *ctx)
{
    antlrcpp::Any rtn = NULL;
    for (PlayScriptParser::ClassDeclarationContext *child : ctx->classBodyDeclaration()) {
        rtn = visitClassBodyDeclaration(child);
    }

    return rtn;
}


antlrcpp::Any ASTEvaluator::visitClassBodyDeclaration(PlayScriptParser::ClassBodyDeclarationContext *ctx)
{
    antlrcpp::Any rtn = NULL;
    if (ctx->memberDeclaration() != NULL) {
        rtn = visitMemberDeclaration(ctx->memberDeclaration());
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitMemberDeclaration(PlayScriptParser::MemberDeclarationContext *ctx)
{
    antlrcpp::Any = NULL;
    if (ctx->fieldDeclaration() != NULL) {
        rtn = visitFieldDeclaration(ctx->fieldDeclaration());
    }
}

antlrcpp::Any ASTEvaluator::visitFieldDeclaration(PlayScriptParser::FieldDeclarationContext *ctx)
{
    antlrcpp::Any = NULL;
    if (ctx->variableDeclarators() != NULL) {
        rtn = visitVariableDeclarators(ctx->variableDeclarators());
    }
    return rtn;
}

antlrcpp::Any ASTEvaluator::visitVariableDeclarators(PlayScriptParser::VariableDeclaratorsContext *ctx)
{
    antlrcpp::Any rtn = NULL;
    
    for (PlayScriptParser::VariableDeclaratorContext *child : ctx->variableDeclarator()) {
        rtn = visitVariableDeclarator(child);
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitVariableDeclarator(PlayScriptParser::VariableDeclaratorContext *ctx)
{
    antlrcpp::Any rtn = NULL;

    LValue *lValue = (LValue *) visitVariableDeclaratorId(ctx->variableDeclaratorId());

    if (ctx->variableInitializer() != NULL) {
        rtn = visitArrayInitializer(ctx->variableInitializer());
        LValue *tmp = rtn.as<LValue*>();
        if (tmp != NULL) {
            rtn = tmp->getValue();
        }
        lValue->setValue(rtn); 
    }
    return rtn;
}

antlrcpp::Any ASTEvaluator::visitVariableDeclaratorId(PlayScriptParser::VariableDeclaratorIdContext *ctx)
{
    antlrcpp::Any rtn = NULL;
    
    Symbol *symbol = at_->symbolOfNode[ctx];
    rtn = getLValue((Variable*) symbol);
    return rtn;
}

antlrcpp::Any ASTEvaluator::visitVariableInitializer(PlayScriptParser::VariableInitializerContext *ctx)
{
    antlrcpp::Any rtn = NULL;
    if (ctx->expression() != NULL) {
       rtn = visitExpression(ctx->expression());
    }

    return rtn;
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