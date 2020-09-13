#ifndef PLAYSCRIPTCOMPILER_H
#define PLAYSCRIPTCOMPILER_H

#pragma once
#include "CharStream.h"
#include "CommonTokenStream.h"
#include "tree/ParseTreeWalker.h"
#include "AnnotatedTree.h"
#include "PlayScriptLexer.h"
#include "PlayScriptParser.h"

#include <string>

namespace play 
{
    class PlayScriptCompiler
    {
        public:
            AnnotatedTree *at;

            PlayScriptParser *parser;

        public:
            AnnotatedTree* compile(std::string, bool verbose, bool ast_dump);

            AnnotatedTree* compile(std::string script);

            // 打印符号表
            void dumpSymbols();

            // 打印AST，以lisp格式
            void dumpAST();
    };
};


#endif