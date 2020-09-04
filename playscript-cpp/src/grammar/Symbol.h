#pragma once
#include <string>
#include "Scope.h"
#include "PlayScriptBaseVisitor.h"

class Symbol
{
    protected:
        // 符号的名称
        std::string name;

        // 所属于作用域
        Scope *enclosingScope;

        // 可见性，比如public还是private
        int visibility = 0;

        // Symbol 关联的AST节点
        PlayScriptParser::ExpressionContext *ctx;

    
    public:
        std::string getName()
        {
            return name;
        }

        Scope* getEnclosingScope()
        {
            return enclosingScope;
        }

        void setEnclosingScope(Scope *sc)
        {
            enclosingScope = sc;
        }

};