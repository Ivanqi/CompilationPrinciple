#ifndef TYPEANDSCOPESCANNER_H
#define TYPEANDSCOPESCANNER_H

#include "ParserRuleContext.h"
#include "PlayScriptBaseListener.h"
#include "PlayScriptParser.h"
#include "AnnotatedTree.h"

#include <stack>
using namespace antlr4;

namespace play {
    /**
     * 第一遍扫描：识别出所有类型(包括类和函数)，以及Scope(但函数的参数信息要等下一个阶段才会添加进去)
     */
    class TypeAndScopeScanner: public PlayScriptBaseListener
    {
        private:
            AnnotatedTree *at_;

            std::stack<Scope*> scopeStack;
        
        public:
            TypeAndScopeScanner(AnnotatedTree *at);
        
        private:
            Scope* pushScope(Scope *scope, ParserRuleContext *ctx);

            // 从栈中弹出scope
            void popScope();

            // 在遍历树的过程中，当前的Scope
            Scope* currentScope();
            
        public:
            virtual void enterProg(PlayScriptParser::ProgContext *ctx);

            virtual void exitProg(PlayScriptParser::ProgContext *ctx);

            virtual void enterBlock(PlayScriptParser::BlockContext *ctx);

            virtual void exitBlock(PlayScriptParser::BlockContext *ctx);

            virtual void enterStatement(PlayScriptParser::StatementContext *ctx);

            virtual void exitStatement(PlayScriptParser::StatementContext *ctx);

            virtual void enterFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx);

            virtual void exitFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx);

            virtual void enterClassDeclaration(PlayScriptParser::ClassDeclarationContext *ctx);

            virtual void exitClassDeclaration(PlayScriptParser::ClassDeclarationContext *ctx);   
    };
};
#endif