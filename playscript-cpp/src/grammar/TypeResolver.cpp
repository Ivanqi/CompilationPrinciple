#include "TypeResolver.h"
#include "AnnotatedTree.h"
#include "Scope.h"
#include "Class.h"
#include "Variable.h"
#include "Function.h"
#include "VoidType.h"
#include "DefaultFunctionType.h"
#include "PrimitiveType.h"
#include <iostream>

using namespace play;

TypeResolver::TypeResolver(AnnotatedTree *at): at_(at)
{

}

TypeResolver::TypeResolver(AnnotatedTree *at, bool enterLocalVariable)
    : at_(at), enterLocalVariable_(enterLocalVariable)
{
}

// 设置所声明的变量的类型
void TypeResolver::exitVariableDeclarators(PlayScriptParser::VariableDeclaratorsContext *ctx)
{
    Scope *scope = at_->enclosingScopeOfNode(ctx);

    // if (dynamic_cast<Class*>(scope) != nullptr || enterLocalVariable_) {
        // 设置变量类型
        Type *type = (Type *) at_->typeOfNode[(ParserRuleContext*)ctx->typeType()];

        for (PlayScriptParser::VariableDeclaratorContext *child: ctx->variableDeclarator()) {
            Variable *variable = (Variable *)at_->symbolOfNode[(ParserRuleContext*)child->variableDeclaratorId()];
            variable->setType(type);
        }
    // }
}

// 把类成员变量的声明加入符号表
void TypeResolver::enterVariableDeclaratorId(PlayScriptParser::VariableDeclaratorIdContext *ctx)
{
    std::string idName = ctx->IDENTIFIER()->getText();
    // 寻找变量的上级声明
    Scope *scope = at_->enclosingScopeOfNode(ctx);

    // 第一步只把类的成员变量入符号表。在变量消解时，再把本地变量加入符号表，一边Enter，一边消解
    //  if (dynamic_cast<Class*>(scope) != nullptr || enterLocalVariable_) {
        Variable *variable = new Variable(idName, scope, ctx);

        // 变量查重
        if (Scope::getVariable(scope, idName) != nullptr) {
            at_->log("Variable or parameter already Declared: " + idName, ctx);
        }

        scope->addSymbol(variable);
        at_->symbolOfNode[ctx] = variable;
    //  }
}

// 设置函数属性
void TypeResolver::exitFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx)
{
    Function *func = (Function*)at_->node2Scope[ctx];
    if (ctx->typeTypeOrVoid() != nullptr) {
        func->returnType = at_->typeOfNode[ctx->typeTypeOrVoid()];
    } else {
        // TODO 如果是类的构建函数，返回值应该是一个类吧？
    }

    // 函数查重，检查名称和参数（这个时候参数已经齐了）
    Scope *scope = at_->enclosingScopeOfNode(ctx);
    Function *found = Scope::getFunction(scope, func->getName(), func->getParamTypes());

    if (found != nullptr && found != func) {
        at_->log("Function or method already Declared: " + ctx->getText(), ctx);
    }
}

// 设置函数的参数的类型，这些参数已经在enterVariableDeclaratorId中作为变量声明了，现在设置它们的类型
// 设置函数的返回类型
void TypeResolver::exitFormalParameter(PlayScriptParser::FormalParameterContext *ctx)
{
    // 设置参数类型
    Type *type = at_->typeOfNode[ctx->typeType()];

    // ctx->variableDeclaratorId() 获取上一个AST节点的属性信息
    Variable *variable = (Variable*) at_->symbolOfNode[ctx->variableDeclaratorId()];
    variable->type = type;

    // 添加到函数的参数列表里
    Scope *scope = at_->enclosingScopeOfNode(ctx);
    // 主要判断是不是function的参数
    Function *tmp = dynamic_cast<Function*>(scope);
    if (tmp != nullptr) {  //TODO 从目前的语法来看，只有function才会使用FormalParameter
        tmp->parameters.push_back(variable);
    }
}

// 设置类的父类
void TypeResolver::enterClassDeclaration(PlayScriptParser::ClassDeclarationContext *ctx)
{
    Class *theClass = (Class *)at_->node2Scope[ctx];

    // 设置父类
    if (ctx->EXTENDS() != nullptr) {
        std::string parentClassName = ctx->typeType()->getText();
        Type *type = at_->lookupType(parentClassName);
        Class *tmp = dynamic_cast<Class *>(type);

        if (type != nullptr && tmp != nullptr) {
            theClass->setParentClass(tmp);
        } else {
            at_->log("unknown class: " + parentClassName, ctx);
        } 
    }
}

// 设置类型推断。设置I属性
void TypeResolver::exitTypeTypeOrVoid(PlayScriptParser::TypeTypeOrVoidContext *ctx)
{
    if (ctx->VOID() != nullptr) {  // 判断是不是空类型
        at_->typeOfNode[ctx] = VoidType::GetInstance();
    } else if (ctx->typeType() != nullptr) {
        at_->typeOfNode[ctx] = (Type *)at_->typeOfNode[ctx->typeType()];
    }
}

// 设置类型推断。设置I属性
void TypeResolver::exitTypeType(PlayScriptParser::TypeTypeContext *ctx)
{
    // 冒泡，将下级的属性标注在本级
    if (ctx->classOrInterfaceType() != nullptr) {  // 类型
        Type *type = (Type*)at_->typeOfNode[ctx->classOrInterfaceType()];
        at_->typeOfNode[ctx] = type;

    } else if (ctx->functionType() != nullptr) {   // 函数
        Type *type = (Type *) at_->typeOfNode[ctx->functionType()];
        at_->typeOfNode[ctx] = type;

    } else if (ctx->primitiveType() != nullptr) {  // 基础字面量
        Type *type = (Type *) at_->typeOfNode[ctx->primitiveType()];
        at_->typeOfNode[ctx] = type;
    }
}

void TypeResolver::enterClassOrInterfaceType(PlayScriptParser::ClassOrInterfaceTypeContext *ctx)
{
    if (ctx->IDENTIFIER().size() > 0) {
        Scope *scope = at_->enclosingClassOfNode(ctx);
        if (scope == nullptr) {
            return;
        }

        std::string idName = ctx->getText();
        Class *theClass = at_->lookupClass(scope, idName);
        at_->typeOfNode[ctx] = theClass;
    }
}

// 设置函数类型
void TypeResolver::exitFunctionType(PlayScriptParser::FunctionTypeContext *ctx)
{
    DefaultFunctionType *functionType = new DefaultFunctionType();
    at_->types.push_back(functionType);

    at_->typeOfNode[ctx] = functionType;

    // 设置函数返回值类型
    functionType->returnType = (Type *) at_->typeOfNode[ctx->typeTypeOrVoid()];

    // 参数类型
    if (ctx->typeList() != nullptr) {
        PlayScriptParser::TypeListContext *tcl = (PlayScriptParser::TypeListContext*)ctx->typeList();
        for (PlayScriptParser::TypeTypeContext *ttc : tcl->typeType()) {
            Type *type = (Type *)at_->typeOfNode[ttc];
            functionType->getParamTypes().push_back(type);
        }
    }
}

// 设置初识类型
void TypeResolver::exitPrimitiveType(PlayScriptParser::PrimitiveTypeContext *ctx)
{
    Type *type;

    if (ctx->BOOLEAN() != nullptr) {       // 布尔类型
        type = PrimitiveType::Boolean;

    } else if (ctx->INT() != nullptr) {    // 整型
        type = PrimitiveType::Integer;

    } else if (ctx->LONG() != nullptr) {   // 长整型
        type = PrimitiveType::Long;

    } else if (ctx->FLOAT() != nullptr) {  // 单浮点型
        type = PrimitiveType::Float;

    } else if (ctx->DOUBLE() != nullptr) { // 双浮点型
        type = PrimitiveType::Double;

    } else if (ctx->BYTE() != nullptr) {   // 二进制类型
        type = PrimitiveType::Byte;

    } else if (ctx->SHORT() != nullptr) {  // 短整型
        type = PrimitiveType::Short;

    } else if (ctx->CHAR() != nullptr) {   // char类型
        type = PrimitiveType::Char;
    }

    at_->typeOfNode[ctx] = type;
}

// 根据字面量来推断类型 
void TypeResolver::exitLiteral(PlayScriptParser::LiteralContext *ctx)
{
    Type *type;

    if (ctx->integerLiteral() != nullptr) {        // 整型字面量
        type = PrimitiveType::Integer;

    } else if (ctx->floatLiteral() != nullptr) {   // 浮点型字面量
        type = PrimitiveType::Float;

    } else if (ctx->CHAR_LITERAL() != nullptr) {   // char 字面量
        type = PrimitiveType::Char;

    } else if (ctx->STRING_LITERAL() != nullptr) { // string 字面量
        type = PrimitiveType::Char;

    } else if (ctx->BOOL_LITERAL() != nullptr) {   // 布尔字面量
        type = PrimitiveType::Boolean;

    } else if (ctx->NULL_LITERAL() != nullptr) {   // NULL 字面量
        type = PrimitiveType::Null;
    }

    at_->typeOfNode[ctx] = type;
}