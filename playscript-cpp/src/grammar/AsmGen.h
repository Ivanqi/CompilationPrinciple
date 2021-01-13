#ifndef ASMGEN_H
#define ASMGEN_H
#pragma once
/**
 * 基于AST，产生汇编代码
 * 限制:
 *  1. 目前仅针对macos，64位
 *  2. 仅支持整型，字符串仅支持字面量
 *  3. 运算仅支持加减法
 */

#include "PlayScriptBaseVisitor.h"
#include "ParserRuleContext.h"
#include "PlayScriptParser.h"

#include <map>
#include <string>
#include <vector>

#include "Segmental.h"

using std::map;
using std::string;
using std::vector;
using namespace antlr4;
using namespace antlr4::tree;

namespace play
{
    class AnnotatedTree;
    class Variable;
    class AsmGen: public PlayScriptBaseVisitor 
    {
        private:
            // 之前编译的结果
            AnnotatedTree *at_{nullptr};

            ////////// 一些临时变量变量，用于保存扫描代码过程中的累计值 ///////////
            // rsp的偏移值，也就是栈帧的大小
            int rspOffset{0};

            /**
             * 计算过程中的临时变量存放的位置
             * key: AST的节点
             * value: 该节点存储的地址，可以是寄存器或栈
             * */
            map<ParserRuleContext*, string> tempVars;

            /**
             * 本地变量存储的地址。目前只在栈中分配，不优化到寄存器中
             * key: 变量
             * value: 该节点存储的地址，在栈中
             */
            map<Variable*, string> localVars;

            // 可以使用的寄存器
            vector<string> registersl{"%eax", "%ebx", "%r10d", "%r11d", "%r12d", "%r13d", "%r14d", "%r15d"};
            vector<string> paramRegisterl{"%edi", "%esi", "%edx", "%ecx", "%r8d", "%r9d"};
            vector<string> paramRegisterq{"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};

            // 扫描某个例程(函数)时生成的代码的缓存区
            string bodyAsm;

            // 字符串字面量
            vector<string> stringLiterals;

            map<string, string> remedyTemp;

            string incSymbol_{"++"};

            Segmental segm_;
        
        public:
            AsmGen(AnnotatedTree *at):at_(at)
            {

            }

            // 主控程序
            string generate();

            virtual antlrcpp::Any visitProg(PlayScriptParser::ProgContext *ctx) override;

            virtual antlrcpp::Any visitBlockStatements(PlayScriptParser::BlockStatementsContext *ctx) override;

            virtual antlrcpp::Any visitBlockStatement(PlayScriptParser::BlockStatementContext *ctx) override;

            virtual antlrcpp::Any visitVariableDeclarators(PlayScriptParser::VariableDeclaratorsContext *ctx) override;

            virtual antlrcpp::Any visitVariableDeclarator(PlayScriptParser::VariableDeclaratorContext *ctx) override;

            virtual antlrcpp::Any visitVariableDeclaratorId(PlayScriptParser::VariableDeclaratorIdContext *ctx) override;

            virtual antlrcpp::Any visitVariableInitializer(PlayScriptParser::VariableInitializerContext *ctx) override;

            virtual antlrcpp::Any visitExpression(PlayScriptParser::ExpressionContext *ctx) override;

            virtual antlrcpp::Any visitPrimary(PlayScriptParser::PrimaryContext *ctx) override;

            virtual antlrcpp::Any visitLiteral(PlayScriptParser::LiteralContext *ctx) override;

            virtual antlrcpp::Any visitIntegerLiteral(PlayScriptParser::IntegerLiteralContext *ctx) override;

            virtual antlrcpp::Any visitStatement(PlayScriptParser::StatementContext *ctx) override;

            virtual antlrcpp::Any visitFunctionCall(PlayScriptParser::FunctionCallContext *ctx) override;

            virtual antlrcpp::Any visitFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx) override;

            virtual antlrcpp::Any visitFunctionBody(PlayScriptParser::FunctionBodyContext *ctx) override;

            virtual antlrcpp::Any visitBlock(PlayScriptParser::BlockContext *ctx) override;

            virtual antlrcpp::Any visitExpressionList(PlayScriptParser::ExpressionListContext *ctx) override;

            virtual antlrcpp::Any visitFormalParameter(PlayScriptParser::FormalParameterContext *ctx) override;

            virtual antlrcpp::Any visitFormalParameterList(PlayScriptParser::FormalParameterListContext *ctx) override;

            virtual antlrcpp::Any visitFormalParameters(PlayScriptParser::FormalParametersContext *ctx) override;

            virtual antlrcpp::Any visitPrimitiveType(PlayScriptParser::PrimitiveTypeContext *ctx) override;

            virtual antlrcpp::Any visitTypeType(PlayScriptParser::TypeTypeContext *ctx) override;

        private:
            // 生成过程体
            void generateProcedure(string name, string& sb);

            string allocForExpression(PlayScriptParser::ExpressionContext *ctx);

            // 获取下一个可以的寄存器的索引
            int getAvailableRegister();

            string getStringLiteralAddress(string str);

            /**
             * 保存调用者需要保护的寄存器
             * 前提，某个寄存器被用过
             */
            void saveRegisters();

            // 恢复被保护的寄存器
            void restoreRegisters();
    };
};

#endif