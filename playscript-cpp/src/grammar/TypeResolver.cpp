#include "TypeResolver.h"
#include "AnnotatedTree.h"
#include "Scope.h"
#include "Class.h"
#include "Variable.h"
#include "Function.h"
#include "VoidType.h"
#include "DefaultFunctionType.h"
#include "PrimitiveType.h"

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

    Class *tmp = dynamic_cast<Class*>(scope);

    if (tmp != NULL || enterLocalVariable_) {
        // 设置变量类型
        Type *type = (Type *) at_->typeOfNode[(ParserRuleContext*)ctx->typeType()];

        for (PlayScriptParser::VariableDeclaratorContext *child: ctx->variableDeclarator()) {
            Variable *variable = (Variable *)at_->symbolOfNode[(ParserRuleContext*)child->variableDeclaratorId()];
            variable->setType(type);
        }
    }
}

// 把类成员变量的声明加入符号表
void TypeResolver::enterVariableDeclaratorId(PlayScriptParser::VariableDeclaratorIdContext *ctx)
{
    std::string idName = ctx->IDENTIFIER()->getText();
    // 寻找变量的上级声明
    Scope *scope = at_->enclosingScopeOfNode(ctx);

    // 第一步只把类的成员变量入符号表。在变量消解时，再把本地变量加入符号表，一边Enter，一边消解
    Class *tmp = dynamic_cast<Class*>(scope);
    if (tmp != NULL || enterLocalVariable_) {
        Variable *variable = new Variable(idName, scope, ctx);

        // 变量查重
        if (Scope::getVariable(scope, idName) != NULL) {
            at_->log("Variable or parameter already Declared: " + idName, ctx);
        }

        scope->addSymbol(variable);
        at_->symbolOfNode[ctx] = variable;
    }
}


void TypeResolver::exitFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx)
{
    Function *function = (Function*)at_->node2Scope[ctx];
    if (ctx->typeTypeOrVoid() != NULL) {
        function->returnType = at_->typeOfNode[ctx->typeTypeOrVoid()];
    } else {
        // TODO 如果是类的构建函数，返回值应该是一个类吧？
    }

    // 函数查重，检查名称和参数（这个时候参数已经齐了）
    Scope *scope = at_->enclosingScopeOfNode(ctx);
    Function *found = Scope::getFunction(scope, function->getName(), function->getParamTypes());

    if (found != NULL && found != function) {
        at_->log("Function or method already Declared: " + ctx->getText(), ctx);
    }
}

// 设置函数的参数的类型，这些参数已经在enterVariableDeclaratorId中作为变量声明了，现在设置它们的类型
void TypeResolver::exitFormalParameter(PlayScriptParser::FormalParameterContext *ctx)
{
    // 设置参数类型
    Type *type = at_->typeOfNode[ctx->typeType()];
    Variable *variable = (Variable*) at_->symbolOfNode[ctx->variableDeclaratorId()];
    variable->type = type;

    // 添加到函数的参数列表里
    Scope *scope = at_->enclosingScopeOfNode(ctx);
    Function *tmp = dynamic_cast<Function*>(scope);
    if (tmp != NULL) {  //TODO 从目前的语法来看，只有function才会使用FormalParameter
        tmp->parameters.push_back(variable);
    }
}

// 设置类的父类
void TypeResolver::enterClassDeclaration(PlayScriptParser::ClassDeclarationContext *ctx)
{
    Class *theClass = (Class *)at_->node2Scope[ctx];

    // 设置父类
    if (ctx->EXTENDS() != NULL) {
        std::string parentClassName = ctx->typeType()->getText();
        Type *type = at_->lookupType(parentClassName);
        Class *tmp = dynamic_cast<Class *>(type);

        if (type != NULL && tmp != NULL) {
            theClass->setParentClass(tmp);
        } else {
            at_->log("unknown class: " + parentClassName, ctx);
        } 
    }
}

void TypeResolver::exitTypeTypeOrVoid(PlayScriptParser::TypeTypeOrVoidContext *ctx)
{
    if (ctx->VOID() != NULL) {
        at_->typeOfNode[ctx] = VoidType::GetInstance();
    } else if (ctx->typeType() != NULL) {
        at_->typeOfNode[ctx] = (Type *)at_->typeOfNode[ctx->typeType()];
    }
}

void TypeResolver::exitTypeType(PlayScriptParser::TypeTypeContext *ctx)
{
    // 冒泡，将下级的属性标注在本级
    if (ctx->classOrInterfaceType() != NULL) {
        Type *type = (Type*)at_->typeOfNode[ctx->classOrInterfaceType()];
        at_->typeOfNode[ctx] = type;
    } else if (ctx->functionType() != NULL) {
        Type *type = (Type *) at_->typeOfNode[ctx->functionType()];
        at_->typeOfNode[ctx] = type;
    } else if (ctx->primitiveType() != NULL) {
        Type *type = (Type *) at_->typeOfNode[ctx->primitiveType()];
        at_->typeOfNode[ctx] = type;
    }
}

void TypeResolver::enterClassOrInterfaceType(PlayScriptParser::ClassOrInterfaceTypeContext *ctx)
{
    if (ctx->IDENTIFIER().size() > 0) {
        Scope *scope = at_->enclosingClassOfNode(ctx);
        std::string idName = ctx->getText();
        Class *theClass = at_->lookupClass(scope, idName);
        at_->typeOfNode[ctx] = theClass;
    }
}

void TypeResolver::exitFunctionType(PlayScriptParser::FunctionTypeContext *ctx)
{
    DefaultFunctionType *functionType = new DefaultFunctionType();
    at_->types.push_back(functionType);

    at_->typeOfNode[ctx] = functionType;

    functionType->returnType = (Type *) at_->typeOfNode[ctx->typeTypeOrVoid()];

    // 参数类型
    if (ctx->typeList() != NULL) {
        PlayScriptParser::TypeListContext *tcl = (PlayScriptParser::TypeListContext*)ctx->typeList();
        for (PlayScriptParser::TypeTypeContext *ttc : tcl->typeType()) {
            Type *type = (Type *)at_->typeOfNode[ttc];
            functionType->getParamTypes().push_back(type);
        }
    }
}

void TypeResolver::exitPrimitiveType(PlayScriptParser::PrimitiveTypeContext *ctx)
{
    Type *type;

    if (ctx->BOOLEAN() != NULL) {
        type = PrimitiveType::Boolean;
    } else if (ctx->INT() != NULL) {
        type = PrimitiveType::Integer;
    } else if (ctx->LONG() != NULL) {
        type = PrimitiveType::Long;
    } else if (ctx->FLOAT() != NULL) {
        type = PrimitiveType::Float;
    } else if (ctx->DOUBLE() != NULL) {
        type = PrimitiveType::Double;
    } else if (ctx->BYTE() != NULL) {
        type = PrimitiveType::Byte;
    } else if (ctx->SHORT() != NULL) {
        type = PrimitiveType::Short;
    } else if (ctx->CHAR() != NULL) {
        type = PrimitiveType::Char;
    }

    at_->typeOfNode[ctx] = type;
}