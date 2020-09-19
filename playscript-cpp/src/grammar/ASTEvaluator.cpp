#include "ASTEvaluator.h"
#include "AnnotatedTree.h"
#include "FunctionObject.h"
#include "Function.h"
#include "Variable.h"
#include "MyLValue.h"
#include "ClassObject.h"
#include "Class.h"
#include "PrimitiveType.h"
#include "BlockScope.h"
#include "BreakObject.h"
#include "ReturnObject.h"
#include "This.h"
#include "Super.h"

using namespace play;

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
        Stack<StackFrame*>::reverse_iterator it;
        for (it = stacks.rbegin(); it != stacks.rend(); it++) {
            StackFrame *f = *it;

            FunctionObject *functionObject = dynamic_cast<FunctionObject*>(frame->object_);
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
            if (f->scope_->getEnclosingScope() == frame->scope_->getEnclosingScope()) {
                frame->parentFrame_ = f->parentFrame_;
                break;
            } else if (f->scope_ == frame->scope_->getEnclosingScope()){
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
                f->parentFrame_ = f;
                break;
            } else if (functionObject != NULL) {
                if (functionObject->getReceiver() != NULL && functionObject->getReceiver()->getEnclosingScope() == f->scope_) {
                    frame->parentFrame_ = f;
                    break;
                }
            }
        }

        if (frame->parentFrame_ == NULL) {
            frame->parentFrame_ = stacks.top();
            stacks.pop();
        }
    }

    stacks.push(frame);

    if (traceStackFrame) {
        dumpStackFrame();
    }
}

void ASTEvaluator::popStack()
{
    stacks.pop();
}

void ASTEvaluator::dumpStackFrame()
{
    cout << "\nStack Frames ----------------" << endl;

    Stack<StackFrame*>::iterator it;
    for (it = stacks.begin(); it != stacks.end(); it++) {
        cout << (*it)->toString() << endl;
    }

    cout << "-----------------------------\n" << endl;
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
        FunctionType *tmp = dynamic_cast<FunctionType*>(it->first->getType());
        if (tmp != NULL) {
            antlrcpp::Any object = classObject->fields[it->first];
            if (object.isNotNull()) {
                FunctionObject *functionObject = static_cast<FunctionObject*>(object);
                getClosureValues(functionObject->function_, tempObject);
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
        Class *c = ancestorChain.top();
        ancestorChain.pop();
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
// void ASTEvaluator::println(PlayScriptParser::FunctionCallContext *ctx)
// {
//     if (ctx->expressionList() != NULL) {
//         antlrcpp::Any value = visitExpression(ctx->expressionList());
//         LValue *tmp = value.as<LValue*>();
//         if (tmp != NULL) {
//             value = tmp->getValue();
//         }

//         std::cout << value.as<std::string>() << std::endl;
//     }
// }

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
    bool rtn = false;

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
        rtn = obj1.equals(obj2);
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::GE(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType)
{
    antlrcpp::Any rtn = NULL;

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

antlrcpp::Any ASTEvaluator::GT(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType)
{
    antlrcpp::Any rtn = NULL;

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

antlrcpp::Any ASTEvaluator::LE(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType)
{
    antlrcpp::Any rtn = NULL;

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

antlrcpp::Any ASTEvaluator::LT(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType)
{
    antlrcpp::Any rtn = NULL;

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
    antlrcpp::Any rtn = false;
    for (PlayScriptParser::ClassBodyDeclarationContext  *child : ctx->classBodyDeclaration()) {
        rtn = visitClassBodyDeclaration(child);
    }

    return rtn;
}


antlrcpp::Any ASTEvaluator::visitClassBodyDeclaration(PlayScriptParser::ClassBodyDeclarationContext *ctx)
{
    antlrcpp::Any rtn = false;
    if (ctx->memberDeclaration() != NULL) {
        rtn = visitMemberDeclaration(ctx->memberDeclaration());
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitMemberDeclaration(PlayScriptParser::MemberDeclarationContext *ctx)
{
    antlrcpp::Any rtn = NULL;
    if (ctx->fieldDeclaration() != NULL) {
        rtn = visitFieldDeclaration(ctx->fieldDeclaration());
    }
    return rtn;
}

antlrcpp::Any ASTEvaluator::visitFieldDeclaration(PlayScriptParser::FieldDeclarationContext *ctx)
{
    antlrcpp::Any rtn = NULL;
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
        rtn = visitVariableInitializer(ctx->variableInitializer());
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
    return stoi(ctx->getText());
}

antlrcpp::Any ASTEvaluator::visitFloatLiteral(PlayScriptParser::FloatLiteralContext *ctx)
{
    return stof(ctx->getText());
}

antlrcpp::Any ASTEvaluator::visitFunctionBody(PlayScriptParser::FunctionBodyContext *ctx)
{
    antlrcpp::Any rtn = NULL;
    if (ctx->block() != NULL) {
        rtn = visitBlock(ctx->block());
    }
    return rtn;
}

antlrcpp::Any ASTEvaluator::visitFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx)
{
    return visitFunctionBody(ctx->functionBody());
}


antlrcpp::Any ASTEvaluator::visitBlock(PlayScriptParser::BlockContext *ctx)
{
    BlockScope *scope = (BlockScope *)at_->node2Scope[ctx];
    if (scope != NULL) {    // 有些block是不对应scope的，比如函数底下的block
        StackFrame *frame = new StackFrame(scope);
        pushStack(frame);
    }

    antlrcpp::Any rtn = visitBlockStatements(ctx->blockStatements());

    if (scope != NULL) {
        popStack();
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitBlockStatements(PlayScriptParser::BlockStatementsContext *ctx)
{
    antlrcpp::Any rtn = NULL;
    for (PlayScriptParser::BlockStatementContext *child : ctx->blockStatement()) {
        rtn = visitBlockStatement(child);

        // 如果返回的是block，那么不执行下面的语句
        BreakObject *tmp1 = rtn.as<BreakObject*>();
        ReturnObject *tmp2 = rtn.as<ReturnObject*>();

        if (tmp1 != NULL) {
            break;
        } else if (tmp2 != NULL) {
            /**
             * 碰到return， 退出函数
             * TODO 要能层层退出一个个block，弹出一个栈帧
             */
            break;
        }
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitBlockStatement(PlayScriptParser::BlockStatementContext *ctx)
{
    antlrcpp::Any rtn = NULL;
    if (ctx->variableDeclarators() != NULL) {
        rtn = visitVariableDeclarators(ctx->variableDeclarators());

    } else if (ctx->statement() != NULL) {
        rtn = visitStatement(ctx->statement());
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
    antlrcpp::Any rtn = NULL;

    // 二元表达式
    if (ctx->bop != NULL && ctx->expression().size() >= 2) {
        antlrcpp::Any left = visitExpression(ctx->expression(0));
        antlrcpp::Any right = visitExpression(ctx->expression(1));

        antlrcpp::Any leftObject = left;
        antlrcpp::Any rightObject = right;

        if (left.as<LValue*>() != NULL) {
            leftObject = left.as<LValue*>()->getValue();
        }

        if (right.as<LValue*>() != NULL) {
            rightObject = right.as<LValue*>()->getValue();
        }

        // 本节点期待的数据类型
        Type *type = at_->typeOfNode[ctx];

        // 左右两个子节点的类型
        Type *type1 = at_->typeOfNode[ctx->expression(0)];
        Type *type2 = at_->typeOfNode[ctx->expression(1)];

        switch (ctx->bop->getType()) {
            case PlayScriptParser::ADD:
                rtn = add(leftObject, rightObject, type);
                break;

            case PlayScriptParser::SUB:
                rtn = minus(leftObject, rightObject, type);
                break;
            
            case PlayScriptParser::MUL:
                rtn = mul(leftObject, rightObject, type);
                break;
            
            case PlayScriptParser::DIV:
                rtn = div(leftObject, rightObject, type);
                break;
            
            case PlayScriptParser::EQUAL:
                rtn = EQ(leftObject, rightObject, PrimitiveType::getUpperType(type1, type2));
                break;
            
            case PlayScriptParser::NOTEQUAL:
                rtn = !EQ(leftObject, rightObject, PrimitiveType::getUpperType(type1, type2));
                break;
            
            case PlayScriptParser::LE:
                rtn = LE(leftObject, rightObject, PrimitiveType::getUpperType(type1, type2));
                break;
            
            case PlayScriptParser::LT:
                rtn = LT(leftObject, rightObject, PrimitiveType::getUpperType(type1, type2));
                break;

            case PlayScriptParser::GE:
                rtn = GE(leftObject, rightObject, PrimitiveType::getUpperType(type1, type2));
                break;

            case PlayScriptParser::GT:
                rtn = GT(leftObject, rightObject, PrimitiveType::getUpperType(type1, type2));
                break;
            
            case PlayScriptParser::AND:
                rtn = leftObject.as<bool>() && rightObject.as<bool>();
                break;
            
            case PlayScriptParser::OR:
                rtn = leftObject.as<bool>() || rightObject.as<bool>();
                break;
            
            case PlayScriptParser::ASSIGN:
                if (left.as<LValue*>() != NULL) {
                    left.as<LValue*>()->setValue(rightObject);
                    rtn = right;
                } else {
                    cout << "Unsupported feature during assignment" << endl;
                }
                break;
            
            default:
                break;

        }

    } else if (ctx->bop != NULL && ctx->bop->getType() == PlayScriptParser::DOT) {
        // 此语法是左递归的，算法体现这一点
        antlrcpp::Any leftObject = visitExpression(ctx->expression(0));

        if (leftObject.as<LValue*>() != NULL) {
           antlrcpp::Any value =  leftObject.as<LValue*>()->getValue();

           if (value.as<ClassObject*>() != NULL) {
               ClassObject *valueContainer = value.as<ClassObject*>();
               Variable *leftVar = (Variable *)at_->symbolOfNode[ctx->expression(0)];

               // 获得field或调用方法
                if (ctx->IDENTIFIER() != NULL) {
                   Variable *variable = (Variable *) at_->symbolOfNode[ctx];

                   // 对于this 和super引用的属性，不用考虑重载，因为它们的解析是准确的
                   This *tmpThis = dynamic_cast<This*>(leftVar);
                   Super *tmpSuper = dynamic_cast<Super*>(leftVar);

                    if (!(tmpThis != NULL || tmpSuper != NULL)) {
                       // 类的成员可能需要重载
                       variable = at_->lookupVariable(valueContainer->type, variable->getName());
                    }

                    LValue *lValue = new MyLValue(valueContainer, variable);
                    rtn = lValue;

                } else if (ctx->functionCall() != NULL) {
                    // 要计算方法的参数，才能加对象的StackFrame
                    if (traceFunctionCall) {
                        cout << "\n >> MethodCall :" << ctx->getText() << endl;
                    }


                    rtn = methodCall(valueContainer, ctx->functionCall(), dynamic_cast<Super*>(leftVar) != NULL);
                }
           }
        } else {
            cout << "Expecting an Object Reference" << endl;
        }
        
    } else if (ctx->primary()) {
        return visitPrimary(ctx->primary());
        
    }

    return nullptr;
}

/**
 * 对象方法调用
 * 要先计算完参数的值，然后再添加对象的StackFrame，然后再调用方法
 * 
 * @param classObject 实际调用时的对象。通过这个对象可以获得真实的类
 * @param ctx
 */
antlrcpp::Any ASTEvaluator::methodCall(ClassObject *classObject, PlayScriptParser::FunctionCallContext *ctx, bool isSuper)
{
    antlrcpp::Any rtn = NULL;

    /**
     * 查找函数，并根据需要创建FunctionObject
     * 如果查找到的类的属性，FunctionType型，需要在对象的帧栈里查
     */
    StackFrame *classFrame = new StackFrame(classObject);
    pushStack(classFrame);

    FunctionObject *funtionObject = getFuntionObject(ctx);

    popStack();

    Function *function = funtionObject->function_;

    // 对普通的类方法，需要在运行时动态绑定
    Class *theClass = classObject->getType();   // 这是从对象获得的类型，是真实类型。可能是变量声明时的类型的子类

    if (!function->isConstructor() && !isSuper) {
        // 从当前类逐向上查找，找到正确的方法定义
        Function *overrided = theClass->getFunction(function->getName(), function->getParamTypes()); 

        // 原来这个function，可能指向一个父类的实现。现在从子类中可能找到重载后的方法，这个时候要绑定到子类的方法上
        if (overrided != NULL && overrided != function) {
            function = overrided;
            funtionObject->setFunction(function);
        }
    }

    // 计算参数值
    vector<antlrcpp::Any> paramValues = calcParamValues(ctx);

    // 对象的frame要等到函数参数都计算完了才能添加
    pushStack(classFrame);

    // 执行函数
    rtn = functionCall(funtionObject, paramValues);

    // 弹出栈帧
    popStack();

    return rtn;
}

// 计算某个函数调用时的参数值
vector<antlrcpp::Any> ASTEvaluator::calcParamValues(PlayScriptParser::FunctionCallContext *ctx)
{
    vector<antlrcpp::Any> paramValues;
    if (ctx->expressionList() != NULL) {
        for (PlayScriptParser::ExpressionContext *exp : ctx->expressionList()->expression()) {
            antlrcpp::Any value = visitExpression(exp);
            if (value.as<LValue*>() != NULL) {
                value = value.as<LValue*>()->getValue();
            }
            paramValues.push_back(value);
        }
    }

    return paramValues;
}

// 执行一个函数的方法体。需要先设置参数值，然后再执行代码
antlrcpp::Any ASTEvaluator::functionCall(FunctionObject *functionObject, vector<antlrcpp::Any>& paramValues)
{
    antlrcpp::Any rtn = NULL;

    // 添加函数的帧栈
    StackFrame *functionFrame = new StackFrame(functionObject);
    pushStack(functionFrame);

    // 给参数赋值，这些值进入functionFrame
    PlayScriptParser::FunctionDeclarationContext *functionCode = (PlayScriptParser::FunctionDeclarationContext*)functionObject->function_->ctx;

    if (functionCode->formalParameters()->formalParameterList() != NULL) {
        for (int i = 0; i < functionCode->formalParameters()->formalParameterList()->formalParameter().size(); i++) {
            PlayScriptParser::FormalParameterContext *param = functionCode->formalParameters()->formalParameterList()->formalParameter(i);
            LValue *lValue = (LValue*)visitVariableDeclaratorId(param->variableDeclaratorId());
            lValue->setValue(paramValues[i]);
        }
    }

    // 调用函数(方法)体
    rtn = visitFunctionDeclaration(functionCode);

    // 弹出StackFrame
    popStack(); // 函数的栈帧

    // 如果由一个return返回，真实返回值会被封在一个ReturnObject里
    if (rtn.as<ReturnObject*>() != NULL) {
        rtn = rtn.as<ReturnObject*>()->returnValue;
    }

    return rtn;
}

/**
 * 根据函数调用上下文，返回一个FunctionObject
 * 对于函数型的变量，这个functionObject是存在变量里的
 * 对于普通的函数调用，此时创建一个
 */
FunctionObject* ASTEvaluator::getFuntionObject(PlayScriptParser::FunctionCallContext *ctx)
{
    if (ctx->IDENTIFIER() == NULL) {    // 暂时不支持this和super
        return NULL;
    }

    Function *function;
    FunctionObject *functionObject;

    Symbol *symbol = at_->symbolOfNode[ctx];

    Variable *tmp = dynamic_cast<Variable*>(symbol);
    Function *funTmp = dynamic_cast<Function*>(symbol);
    // 函数类型的变量
    if (symbol != NULL) {
        Variable *variable = (Variable *)symbol;
        LValue *lValue = getLValue(variable);
        antlrcpp::Any value = lValue->getValue();

        if (value.as<FunctionObject*>() != NULL) {
            functionObject = value.as<FunctionObject*>();
            function = functionObject->function_;
        }

    } else if (funTmp != NULL) {
        function = funTmp;

    } else {
        string functionName = ctx->IDENTIFIER()->getText(); // 这是调用时的名称，不一定是真正的函数名，还可能是函数类型的变量名
        at_->log("unable to find function or function variable" + functionName, ctx);
    }

    if (functionObject == NULL) {
        functionObject = new FunctionObject(function);
    }

    return functionObject;
}