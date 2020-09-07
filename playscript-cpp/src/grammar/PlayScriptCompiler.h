#ifndef PLAYSCRIPTCOMPILER_H
#define PLAYSCRIPTCOMPILER_H

#pragma once
#include "CharStream.h"
#include "CommonTokenStream.h"
#include "tree/ParseTreeWalker.h"
#include "AnnotatedTree.h"
#include "PlayScriptLexer.h"
#include "PlayScriptParser.h"

class PlayScriptCompiler
{
    public:
        AnnotatedTree compile(const char* script, bool verbose, bool ast_dump)
        {
            AnnotatedTree at;
            std::ifstream ifs;
            ifs.open(script);

            ANTLRInputStream input(ifs);
            PlayScriptLexer lexer(&input);
            CommonTokenStream tokens(&lexer);

            tokens.fill();

            PlayScriptParser parser(&tokens);

            at.ast = parser.prog();

            // 语义分析
            ParseTreeWalker walker;

            // 多步的语义分析
            //优点：1.代码清晰; 2.允许使用声明之前，这在支持面向对象，递归函数等特征时是必须的
            //parse1: 类型和Scope
    

            return at;
        }
};

#endif