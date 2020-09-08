#ifndef TYPEANDSCOPESCANNER_H
#define TYPEANDSCOPESCANNER_H

#include "ParserRuleContext.h"
#include "PlayScriptBaseListener.h"
#include "PlayScriptParser.h"
#include "AnnotatedTree.h"
#include "Scope.h"
#include "NameSpace.h"
#include "BlockScope.h"
#include "Function.h"
#include "Class.h"

#include <stack>
using namespace antlr4;

namespace play {
    /**
     * 第一遍扫描：识别出所有类型(包括类和函数)，以及Scope(但函数的参数信息要等下一个阶段才会添加进去)
     */
    class TypeAndScopeScanner: public PlayScriptBaseListener
    {
        private:
            AnnotatedTree *at;

            std::stack<Scope*> scopeStack;
        
        public:
            TypeAndScopeScanner(AnnotatedTree *at_): at(at_)
            {
            }
        
        private:
            Scope* pushScope(Scope *scope, ParserRuleContext *ctx)
            {
                at->node2Scope.insert(std::pair<ParserRuleContext*, Scope*>(ctx, scope));
                scope->setCtx(ctx);

                scopeStack.push(scope);
                return scope;
            }

            // 从栈中弹出scope
            void popScope()
            {
                scopeStack.pop();
            }

            // 在遍历树的过程中，当前的Scope
            Scope* currentScope()
            {
                if (scopeStack.size() > 0) {
                    Scope* top = scopeStack.top();
                    scopeStack.pop();
                    return top;
                } else {
                    return NULL;
                }
            }

            virtual void enterProg(PlayScriptParser::ProgContext *ctx)
            {
                NameSpace *scope = new NameSpace("", currentScope(), ctx);
                at->namespaces = scope; // scope的根
                pushScope(scope, ctx);
            }

            virtual void exitProg(PlayScriptParser::ProgContext *ctx)
            {
                popScope();
            }


            virtual void enterBlock(PlayScriptParser::BlockContext *ctx) 
            {
                // 对于函数，不需要再额外建一个scope
                PlayScriptParser::FunctionBodyContext *tmp = dynamic_cast<PlayScriptParser::FunctionBodyContext*>(ctx->parent);
                if (tmp != NULL) {
                    BlockScope *scope = new BlockScope(currentScope(), ctx);
                    currentScope()->addSymbol(scope);
                    pushScope(scope, ctx);
                }
            }

            virtual void exitBlock(PlayScriptParser::BlockContext *ctx)
            {
                PlayScriptParser::FunctionBodyContext *tmp = dynamic_cast<PlayScriptParser::FunctionBodyContext*>(ctx->parent);
                if (tmp != NULL) {
                    popScope();
                }
            }

            virtual void enterStatement(PlayScriptParser::StatementContext *ctx) 
            {
                // 为for建立额外的Scope
                if (ctx->FOR() != NULL) {
                    BlockScope *scope = new BlockScope(currentScope(), ctx);
                    currentScope()->addSymbol(scope);
                    pushScope(scope, ctx);
                }
            }

            virtual void exitStatement(PlayScriptParser::StatementContext *ctx) 
            {
                //释放for语句的外层scope
                if (ctx->FOR() != NULL) {
                    popScope();
                }
            }

            virtual void enterFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx)  
            {
                std::string idName = ctx->IDENTIFIER()->getText();

                // 注意：目前function信息并不完整，参数要等到Typesolver中去确定
                Function *function = new Function(idName, currentScope(), ctx);

                at->types.push_back(function);

                currentScope()->addSymbol(function);
                
                // 创建一个新的scope
                pushScope(function, ctx);
            }

            virtual void exitFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx) 
            {
                popScope();
            }

            virtual void enterClassDeclaration(PlayScriptParser::ClassDeclarationContext *ctx)
            {
                // 把类的签名存到符号表中，不能跟已有符号名称冲突
                std::string idName = ctx->IDENTIFIER()->getText();

                Class *thClass = new Class(idName, ctx);
            }

            virtual void exitClassDeclaration(PlayScriptParser::ClassDeclarationContext *ctx)
            {

            }

    };
};
#endif