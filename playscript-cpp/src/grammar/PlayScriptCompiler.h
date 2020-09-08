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
        AnnotatedTree* compile(const char* script, bool verbose, bool ast_dump);
};

#endif