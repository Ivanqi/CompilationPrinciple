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
#include "PlayObject.h"
#include "NullObject.h"
#include "DefaultConstructor.h"

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
            } else if (functionObject != nullptr) {
                if (functionObject->getReceiver() != nullptr && functionObject->getReceiver()->getEnclosingScope() == f->scope_) {
                    frame->parentFrame_ = f;
                    break;
                }
            }
        }

        if (frame->parentFrame_ == nullptr) {
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

    while (f != nullptr) {
        if (f->scope_->containsSymbol(variable)) {  // 对于对象来说，会查找所有父类属性
            valueContainer = f->object_;
            break;
        }
    }

    // 通过正常的作用域找不到，就从闭包里找
    // 原理：PlayObject中可能有一些变量，其作用域跟StackFrame.scope是不同的
    if (valueContainer == nullptr) {
        f = stacks.top();
        while (f != nullptr) {
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
        if (tmp != nullptr) {
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
    while (theClass->getParentClass() != nullptr) {
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
        // 把变量加到obj里，缺省先都初始化成nullptr，不允许有未初始化的
        Variable *tmp = dynamic_cast<Variable*>(symbol);
        if (tmp != nullptr) {
            obj->fields[tmp] = nullptr;
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
    if (ctx->expressionList() != nullptr) {
        antlrcpp::Any value = visitExpressionList(ctx->expressionList());
        LValue *tmp = value.as<LValue*>();
        if (tmp != nullptr) {
            value = tmp->getValue();
        }

        std::cout << value.as<std::string>() << std::endl;
    }
}

antlrcpp::Any ASTEvaluator::add(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType)
{
    antlrcpp::Any rtn = nullptr;

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
    antlrcpp::Any rtn = nullptr;

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
    antlrcpp::Any rtn = nullptr;

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
    antlrcpp::Any rtn = nullptr;

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
    antlrcpp::Any rtn = nullptr;

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
    antlrcpp::Any rtn = nullptr;

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
    antlrcpp::Any rtn = nullptr;

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
    antlrcpp::Any rtn = nullptr;

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
    if (ctx->memberDeclaration() != nullptr) {
        rtn = visitMemberDeclaration(ctx->memberDeclaration());
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitMemberDeclaration(PlayScriptParser::MemberDeclarationContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    if (ctx->fieldDeclaration() != nullptr) {
        rtn = visitFieldDeclaration(ctx->fieldDeclaration());
    }
    return rtn;
}

antlrcpp::Any ASTEvaluator::visitFieldDeclaration(PlayScriptParser::FieldDeclarationContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    if (ctx->variableDeclarators() != nullptr) {
        rtn = visitVariableDeclarators(ctx->variableDeclarators());
    }
    return rtn;
}

antlrcpp::Any ASTEvaluator::visitVariableDeclarators(PlayScriptParser::VariableDeclaratorsContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    
    for (PlayScriptParser::VariableDeclaratorContext *child : ctx->variableDeclarator()) {
        rtn = visitVariableDeclarator(child);
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitVariableDeclarator(PlayScriptParser::VariableDeclaratorContext *ctx)
{
    antlrcpp::Any rtn = nullptr;

    LValue *lValue = (LValue *) visitVariableDeclaratorId(ctx->variableDeclaratorId());

    if (ctx->variableInitializer() != nullptr) {
        rtn = visitVariableInitializer(ctx->variableInitializer());
        LValue *tmp = rtn.as<LValue*>();
        if (tmp != nullptr) {
            rtn = tmp->getValue();
        }
        lValue->setValue(rtn); 
    }
    return rtn;
}

antlrcpp::Any ASTEvaluator::visitVariableDeclaratorId(PlayScriptParser::VariableDeclaratorIdContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    
    Symbol *symbol = at_->symbolOfNode[ctx];
    rtn = getLValue((Variable*) symbol);
    return rtn;
}

antlrcpp::Any ASTEvaluator::visitVariableInitializer(PlayScriptParser::VariableInitializerContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    if (ctx->expression() != nullptr) {
       rtn = visitExpression(ctx->expression());
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitFunctionBody(PlayScriptParser::FunctionBodyContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    if (ctx->block() != nullptr) {
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
    if (scope != nullptr) {    // 有些block是不对应scope的，比如函数底下的block
        StackFrame *frame = new StackFrame(scope);
        pushStack(frame);
    }

    antlrcpp::Any rtn = visitBlockStatements(ctx->blockStatements());

    if (scope != nullptr) {
        popStack();
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitBlockStatements(PlayScriptParser::BlockStatementsContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    for (PlayScriptParser::BlockStatementContext *child : ctx->blockStatement()) {
        rtn = visitBlockStatement(child);

        if (rtn.isNull()) continue;

        // 如果返回的是block，那么不执行下面的语句
        if (rtn.as<BreakObject*>() != nullptr) {
            break;
        } else if (rtn.as<ReturnObject*>() != nullptr) {
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
    antlrcpp::Any rtn = nullptr;
    if (ctx->variableDeclarators() != nullptr) {
        // rtn = visitVariableDeclarators(ctx->variableDeclarators());

    } else if (ctx->statement() != nullptr) {
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
    antlrcpp::Any rtn = nullptr;

    // 二元表达式
    if (ctx->bop != nullptr && ctx->expression().size() >= 2) {
        // antlrcpp::Any left = visitExpression(ctx->expression(0));
        // antlrcpp::Any right = visitExpression(ctx->expression(1));

        // antlrcpp::Any leftObject = left;
        // antlrcpp::Any rightObject = right;

        // if (left.as<LValue*>() != nullptr) {
        //     leftObject = left.as<LValue*>()->getValue();
        // }

        // if (right.as<LValue*>() != nullptr) {
        //     rightObject = right.as<LValue*>()->getValue();
        // }

        // // 本节点期待的数据类型
        // Type *type = at_->typeOfNode[ctx];

        // // 左右两个子节点的类型
        // Type *type1 = at_->typeOfNode[ctx->expression(0)];
        // Type *type2 = at_->typeOfNode[ctx->expression(1)];

        // switch (ctx->bop->getType()) {
        //     case PlayScriptParser::ADD:
        //         rtn = add(leftObject, rightObject, type);
        //         break;

        //     case PlayScriptParser::SUB:
        //         rtn = minus(leftObject, rightObject, type);
        //         break;
            
        //     case PlayScriptParser::MUL:
        //         rtn = mul(leftObject, rightObject, type);
        //         break;
            
        //     case PlayScriptParser::DIV:
        //         rtn = div(leftObject, rightObject, type);
        //         break;
            
        //     case PlayScriptParser::EQUAL:
        //         rtn = EQ(leftObject, rightObject, PrimitiveType::getUpperType(type1, type2));
        //         break;
            
        //     case PlayScriptParser::NOTEQUAL:
        //         rtn = !EQ(leftObject, rightObject, PrimitiveType::getUpperType(type1, type2));
        //         break;
            
        //     case PlayScriptParser::LE:
        //         rtn = LE(leftObject, rightObject, PrimitiveType::getUpperType(type1, type2));
        //         break;
            
        //     case PlayScriptParser::LT:
        //         rtn = LT(leftObject, rightObject, PrimitiveType::getUpperType(type1, type2));
        //         break;

        //     case PlayScriptParser::GE:
        //         rtn = GE(leftObject, rightObject, PrimitiveType::getUpperType(type1, type2));
        //         break;

        //     case PlayScriptParser::GT:
        //         rtn = GT(leftObject, rightObject, PrimitiveType::getUpperType(type1, type2));
        //         break;
            
        //     case PlayScriptParser::AND:
        //         rtn = leftObject.as<bool>() && rightObject.as<bool>();
        //         break;
            
        //     case PlayScriptParser::OR:
        //         rtn = leftObject.as<bool>() || rightObject.as<bool>();
        //         break;
            
        //     case PlayScriptParser::ASSIGN:
        //         if (left.as<LValue*>() != nullptr) {
        //             left.as<LValue*>()->setValue(rightObject);
        //             rtn = right;
        //         } else {
        //             cout << "Unsupported feature during assignment" << endl;
        //         }
        //         break;
            
        //     default:
        //         break;

        // }

    } else if (ctx->bop != nullptr && ctx->bop->getType() == PlayScriptParser::DOT) {
        // 此语法是左递归的，算法体现这一点
        // antlrcpp::Any leftObject = visitExpression(ctx->expression(0));

        // if (leftObject.as<LValue*>() != nullptr) {
        //    antlrcpp::Any value =  leftObject.as<LValue*>()->getValue();

        //    if (value.as<ClassObject*>() != nullptr) {
        //        ClassObject *valueContainer = value.as<ClassObject*>();
        //        Variable *leftVar = (Variable *)at_->symbolOfNode[ctx->expression(0)];

        //        // 获得field或调用方法
        //         if (ctx->IDENTIFIER() != nullptr) {
        //            Variable *variable = (Variable *) at_->symbolOfNode[ctx];

        //            // 对于this 和super引用的属性，不用考虑重载，因为它们的解析是准确的
        //             if (!(dynamic_cast<This*>(leftVar) != nullptr || dynamic_cast<Super*>(leftVar) != nullptr)) {
        //                // 类的成员可能需要重载
        //                variable = at_->lookupVariable(valueContainer->type, variable->getName());
        //             }

        //             LValue *lValue = new MyLValue(valueContainer, variable);
        //             rtn = lValue;

        //         } else if (ctx->functionCall() != nullptr) {
        //             // 要计算方法的参数，才能加对象的StackFrame
        //             if (traceFunctionCall) {
        //                 cout << "\n >> MethodCall :" << ctx->getText() << endl;
        //             }

        //             rtn = methodCall(valueContainer, ctx->functionCall(), dynamic_cast<Super*>(leftVar) != nullptr);
        //         }
        //    }
        // } else {
        //     cout << "Expecting an Object Reference" << endl;
        // }
        
    } else if (ctx->primary()) {
        // return visitPrimary(ctx->primary());
        
    } else if (ctx->postfix != nullptr) {  // 后缀运算，例如: i++ 或 i--
        // antlrcpp::Any value = visitExpression(ctx->expression(0));
        // LValue *lValue;
        // Type *type = at_->typeOfNode[ctx->expression(0)];

        // if (value.as<LValue*>() != nullptr) {
        //     lValue = value.as<LValue*>();
        //     value = lValue->getValue();
        // }

        // switch (ctx->postfix->getType()) {
        //     case PlayScriptParser::INC:
        //         if (type == PrimitiveType::Integer) {
        //             lValue->setValue(value.as<int>() + 1);
        //         } else {
        //             lValue->setValue(value.as<long>() + 1);
        //         }
        //         rtn = value;
        //         break;
            
        //     case PlayScriptParser::DEC:
        //         if (type == PrimitiveType::Integer) {
        //             lValue->setValue(value.as<int>() - 1);
        //         } else {
        //             lValue->setValue(value.as<long>() - 1);
        //         }
        //         rtn = value;
        //         break;
            
        //     default:
        //         break;
        // }

    } else if (ctx->prefix != nullptr) {   // 前缀操作。例如：++i 或 --i
        // antlrcpp::Any value = visitExpression(ctx->expression(0));
        // LValue *lValue;

        // Type *type = at_->typeOfNode[ctx->expression(0)];
        // if (value.as<LValue*>() != nullptr) {
        //     lValue = value.as<LValue*>();
        //     value = lValue->getValue();
        // }

        // switch (ctx->postfix->getType()) {
        //     case PlayScriptParser::INC:
        //         if (type == PrimitiveType::Integer) {
        //            rtn = value.as<int>() + 1;
        //         } else {
        //             rtn = value.as<long>() + 1;
        //         }
        //         lValue->setValue(rtn);
        //         break;

        //     case PlayScriptParser::DEC:
        //         if (type == PrimitiveType::Integer) {
        //             rtn = value.as<int>() - 1;
        //         } else {
        //             rtn = value.as<long>() - 1;
        //         }
        //         lValue->setValue(rtn);
        //         break;
            
        //     case PlayScriptParser::BANG:    // 符号，逻辑非运算
        //         rtn = !value.as<bool>();
        //         break;
            
        //     default:
        //         break;
        // }

    } else if (ctx->functionCall() != nullptr) {   // functionCall
        rtn = visitFunctionCall(ctx->functionCall());
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitExpressionList(PlayScriptParser::ExpressionListContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    for (PlayScriptParser::ExpressionContext *child : ctx->expression()) {
        rtn = visitExpression(child);
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitForInit(PlayScriptParser::ForInitContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    if (ctx->variableDeclarators() != nullptr) {
        rtn = visitVariableDeclarators(ctx->variableDeclarators());

    } else if (ctx->expressionList() != nullptr) {
        rtn = visitExpressionList(ctx->expressionList());
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitLiteral(PlayScriptParser::LiteralContext *ctx)
{
    antlrcpp::Any rtn = nullptr;

    
    if (ctx->integerLiteral() != nullptr) {        // 整数
        rtn = visitIntegerLiteral(ctx->integerLiteral());

    } else if (ctx->floatLiteral() != nullptr) {   // 浮点数
        rtn = visitFloatLiteral(ctx->floatLiteral());

    } else if (ctx->BOOL_LITERAL() != nullptr) {   // 布尔值
        if (ctx->BOOL_LITERAL()->getText() == "true") {
            rtn = true;
        } else {
            rtn = false;
        }
    } else if (ctx->STRING_LITERAL() != nullptr) { // 字符串
        string withQuotationMark = ctx->STRING_LITERAL()->getText();
        rtn = withQuotationMark.substr(1, withQuotationMark.length() - 1);

    } else if (ctx->CHAR_LITERAL() != nullptr) {   // 单个字符
        rtn = ctx->CHAR_LITERAL()->getText()[0];

    } else if (ctx->NULL_LITERAL() != nullptr) {   // nullptr字面量
        rtn = NullObject::GetInstance();
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitIntegerLiteral(PlayScriptParser::IntegerLiteralContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    if (ctx->DECIMAL_LITERAL() != nullptr) {
        rtn = atoi(ctx->DECIMAL_LITERAL()->getText().c_str());
    }
    return rtn;
}

antlrcpp::Any ASTEvaluator::visitFloatLiteral(PlayScriptParser::FloatLiteralContext *ctx)
{
    return (float)atof(ctx->getText().c_str());
}

antlrcpp::Any ASTEvaluator::visitParExpression(PlayScriptParser::ParExpressionContext *ctx)
{
    return visitExpression(ctx->expression());
}

antlrcpp::Any ASTEvaluator::visitPrimary(PlayScriptParser::PrimaryContext *ctx)
{
    antlrcpp::Any rtn;

    if (ctx->literal() != nullptr) {   // 字面量
        rtn = visitLiteral(ctx->literal());

    } else if (ctx->IDENTIFIER() != nullptr) { // 变量
        Symbol *symbol = at_->symbolOfNode[ctx];

        if (dynamic_cast<Variable*>(symbol) != nullptr) {
            rtn = getLValue(dynamic_cast<Variable*>(symbol));

        } else if (dynamic_cast<Function*>(symbol) != nullptr) {
            FunctionObject *obj = new FunctionObject(dynamic_cast<Function*>(symbol));
            rtn = obj;
        }

    } else if (ctx->expression() != nullptr) { // 括号括起来的表达式
        rtn = visitExpression(ctx->expression());

    } else if (ctx->THIS() != nullptr) {   // this
        This *thisRef = (This *)at_->symbolOfNode[ctx];
        rtn = getLValue(thisRef);
    }
    // todo 缺少 SUPER

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitPrimitiveType(PlayScriptParser::PrimitiveTypeContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    if (ctx->INT() != nullptr) {
        rtn = PlayScriptParser::INT;

    } else if (ctx->LONG() != nullptr) {
        rtn = PlayScriptParser::LONG;

    } else if (ctx->FLOAT() != nullptr) {
        rtn = PlayScriptParser::FLOAT;

    } else if (ctx->DOUBLE() != nullptr) {
        rtn = PlayScriptParser::DOUBLE;

    } else if (ctx->BOOLEAN() != nullptr) {
        rtn = PlayScriptParser::BOOLEAN;

    } else if (ctx->CHAR() != nullptr) {
        rtn = PlayScriptParser::CHAR;

    } else if (ctx->SHORT() != nullptr) {
        rtn = PlayScriptParser::SHORT;

    } else if (ctx->BYTE() != nullptr) {
        rtn = PlayScriptParser::BYTE;
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitStatement(PlayScriptParser::StatementContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    if (ctx->statementExpression != nullptr) {
        rtn = visitExpression(ctx->statementExpression);

    } else if (ctx->IF() != nullptr) {
        // bool condition = (bool) visitParExpression(ctx->parExpression());
        // if (true == condition) {
        //     rtn = visitStatement(ctx->statement(0));
        // } else if (ctx->ELSE() != nullptr) {
        //     rtn = visitStatement(ctx->statement(1));
        // }

    } else if (ctx->WHILE() != nullptr) {   // while
        // if (ctx->parExpression()->expression() != nullptr && ctx->statement(0) != nullptr) {

        //     while (true) {
        //         // 每次循环都要计算一下循环条件
        //         bool condition = true;
        //         antlrcpp::Any value = visitExpression(ctx->parExpression()->expression());

        //         if (value.as<LValue*>() != nullptr) {
        //             condition = (bool) value.as<LValue*>()->getValue();
        //         } else {
        //             condition = value.as<bool>();
        //         }

        //         if (condition) {
        //             // 执行while后面的语句
        //             if (condition) {
        //                 rtn = visitStatement(ctx->statement(0));

        //                 // break
        //                 if (rtn.as<BreakObject*>() != nullptr) {
        //                     rtn = nullptr;     // 清除BreakObject，也就是只跳出一层循环
        //                     break;
        //                 } else if (rtn.as<ReturnObject*>() != nullptr) {    // return
        //                     break;
        //                 }
        //             }
        //         } else {
        //             break;
        //         }
        //     }
        // }

    } else if (ctx->FOR() != nullptr) {    // for循环
        // 添加StackFrame
        // BlockScope *scope = static_cast<BlockScope*>(at_->node2Scope[ctx]);
        // StackFrame *frame = new StackFrame(scope);
        // pushStack(frame);

        // PlayScriptParser::ForControlContext *forControl = ctx->forControl();
        // if (forControl->enhancedForControl() != nullptr) {

        // } else {
        //     // 初始化部分执行一次
        //     if (forControl->forInit() != nullptr) {
        //         rtn = visitForInit(forControl->forInit());
        //     }

        //     while (true) {
        //         bool condition = true;  // 如果没有条件判断部分，意味着一直循环
        //         if (forControl->expression() != nullptr) {
        //             antlrcpp::Any value = visitExpression(forControl->expression());
        //             if (value.as<LValue*>() != nullptr) {
        //                 condition = (bool) value.as<LValue*>()->getValue();
        //             } else {
        //                 condition = (bool) value;
        //             }
        //         }

        //         if (condition) {
        //             // 执行for的语句体
        //             rtn = visitStatement(ctx->statement(0));

        //             // 处理break
        //             if (rtn.as<BreakObject*>() != nullptr) {
        //                 rtn = nullptr;
        //                 break;

        //             } else if(rtn.as<ReturnObject*>() != nullptr) {    // return
        //                 break;
        //             }

        //             // 执行forUpdate，通常是"i++"这样语句。这个顺序不能出错
        //             if (forControl->forUpdate != nullptr) {
        //                 visitExpressionList(forControl->forUpdate);
        //             }
        //         } else {
        //             break;
        //         }
        //     }
        // }

        // // 去掉StackFrame
        // popStack();

    } else if (ctx->blockLabel != nullptr) {   // block
        // rtn = visitBlock(ctx->blockLabel);

    } else if (ctx->BREAK() != nullptr) {      // break
        // rtn = BreakObject::GetInstance();

    } else if (ctx->RETURN() != nullptr) {     // return语句
        // if (ctx->expression() != nullptr) {
        //     rtn = visitExpression(ctx->expression());

        //     // return 语句应该不需要左值    // TODO 取左值的场景需要优化，目前都是取左值
        //     if (rtn.as<LValue*>() != nullptr) {
        //         rtn = rtn.as<LValue*>()->getValue();
        //     }

        //     // 把闭包涉及的环境变量都打包带走
        //     if (rtn.as<FunctionObject*>() != nullptr) {
        //         FunctionObject *functionObject = rtn.as<FunctionObject*>();
        //         getClosureValues(functionObject->function_, functionObject);

        //     } else if (rtn.as<ClassObject*>() != nullptr) {
        //         // 如果返回的是一个对象，那么检查它的所有属性里有没有闭包的。 // TODO 如果属性仍然是一个对象，可能就要向下递归查找
        //         ClassObject *classObject = rtn.as<ClassObject*>();
        //         getClosureValues(classObject);

        //     }
        // }
        // // 把真实的返回值封装一个RetrunObject对象里，告诉visitBlockStatements停止执行下面的语句
        // rtn = new ReturnObject(rtn);
    }

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitTypeType(PlayScriptParser::TypeTypeContext *ctx)
{
    return visitPrimitiveType(ctx->primitiveType());
}

antlrcpp::Any ASTEvaluator::visitProg(PlayScriptParser::ProgContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    // pushStack(new StackFrame((BlockScope*) at_->node2Scope[ctx]));

    rtn = visitBlockStatements(ctx->blockStatements());

    // popStack();

    return rtn;
}

antlrcpp::Any ASTEvaluator::visitFunctionCall(PlayScriptParser::FunctionCallContext *ctx)
{
    // this
    if (ctx->THIS() != nullptr) {
        thisConstructor(ctx);
        return nullptr;    // 不需要有返回值，因为本身就是在构造方法里调用

    } else if (ctx->SUPER() != nullptr) {   // super
        thisConstructor(ctx);               // 似乎跟this完全一样。因为方法的绑定是解析准确了的
        return nullptr;
    }

    antlrcpp::Any rtn = nullptr;

    // 这是调用时的名称，不一定真正的函数名，还可能函数的变量名
    string functionName = ctx->IDENTIFIER()->getText();

    // 如果调用的是类的缺省构造函数，则直接创建对象并返回
    // Symbol *symbol = at_->symbolOfNode[ctx];

    // DefaultConstructor *tmpDefault = dynamic_cast<DefaultConstructor*>(symbol);
    // if (tmpDefault != nullptr) {
    //     // 类的缺省构造函数。没有一个具体函数跟它关联，只是指向一个类
    //     return createAndInitClassObject(tmpDefault->Class());   // 返回新创建的对象

    // } else if (functionName == "println") {
    //     // 用于打印输出
    //     println(ctx);
    //     return rtn;
    // }

    // // 在上下文中查找函数，并根据需要创建FunctionObject
    // FunctionObject *functionObject = getFuntionObject(ctx);
    // Function *function = functionObject->function_;

    // // 如果是对象的构造方法，则按照对象方法调用去执行，并返回所创建的对象
    // if (function->isConstructor()) {
    //     Class *theClass = (Class*) function->getEnclosingScope();

    //     ClassObject *newObject = createAndInitClassObject(theClass);  // 先做缺省的初始化

    //     methodCall(newObject, ctx, false);

    //     return newObject;   // 返回新创建的对象
    // }

    // // 计算参数值
    // vector<antlrcpp::Any> paramValues = calcParamValues(ctx);

    // if (traceFunctionCall) {
    //     cout << "\n>>FunctionCall : " + ctx->getText() << endl;
    // }

    // rtn = functionCall(functionObject, paramValues);

    return rtn;
}

void ASTEvaluator::thisConstructor(PlayScriptParser::FunctionCallContext *ctx)
{
    Symbol *symbol = at_->symbolOfNode[ctx];
    
    DefaultConstructor *tmpDefault = dynamic_cast<DefaultConstructor*>(symbol);
    Function *tmpFun = dynamic_cast<Function*>(symbol);

    if (tmpDefault != nullptr) {   // 缺省构造函数
        return;                 // 这里不用管，因为缺省构造函数一定会被调用

    } else if (tmpFun != nullptr) {
        Function *function = tmpFun;
        FunctionObject *functionObject = new FunctionObject(function);

        vector<antlrcpp::Any> paramValues = calcParamValues(ctx);

        functionCall(functionObject, paramValues);
    }
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
    antlrcpp::Any rtn = nullptr;

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
        if (overrided != nullptr && overrided != function) {
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
    if (ctx->expressionList() != nullptr) {
        for (PlayScriptParser::ExpressionContext *exp : ctx->expressionList()->expression()) {
            antlrcpp::Any value = visitExpression(exp);
            if (value.as<LValue*>() != nullptr) {
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
    antlrcpp::Any rtn = nullptr;

    // 添加函数的帧栈
    StackFrame *functionFrame = new StackFrame(functionObject);
    pushStack(functionFrame);

    // 给参数赋值，这些值进入functionFrame
    PlayScriptParser::FunctionDeclarationContext *functionCode = (PlayScriptParser::FunctionDeclarationContext*)functionObject->function_->ctx;

    if (functionCode->formalParameters()->formalParameterList() != nullptr) {
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
    if (rtn.as<ReturnObject*>() != nullptr) {
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
    if (ctx->IDENTIFIER() == nullptr) {    // 暂时不支持this和super
        return nullptr;
    }

    Function *function;
    FunctionObject *functionObject;

    Symbol *symbol = at_->symbolOfNode[ctx];

    // 函数类型的变量
    if (dynamic_cast<Variable*>(symbol) != nullptr) {
        Variable *variable = dynamic_cast<Variable*>(symbol);
        LValue *lValue = getLValue(variable);
        antlrcpp::Any value = lValue->getValue();

        if (value.as<FunctionObject*>() != nullptr) {
            functionObject = value.as<FunctionObject*>();
            function = functionObject->function_;
        }

    } else if (dynamic_cast<Function*>(symbol) != nullptr) {
        function = dynamic_cast<Function*>(symbol);

    } else {
        string functionName = ctx->IDENTIFIER()->getText(); // 这是调用时的名称，不一定是真正的函数名，还可能是函数类型的变量名
        at_->log("unable to find function or function variable" + functionName, ctx);
    }

    if (functionObject == nullptr) {
        functionObject = new FunctionObject(function);
    }

    return functionObject;
}