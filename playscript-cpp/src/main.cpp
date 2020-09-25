#include <iostream>
#include "antlr4-runtime.h"
#include "PlayScriptLexer.h"
#include "PlayScriptParser.h"
#include "ASTEvaluator.h"
#include "PlayScriptCompiler.h"
#include "AnnotatedTree.h"
#include <iostream>

using namespace antlr4;
using namespace std;
using namespace play;

void returnMsg(antlrcpp::Any result) {

    if (result.is<string>()) {
        cout << result.as<string>() << endl;

    } else if (result.is<int>()) {
        cout << result.as<int>() << endl;

    } else if (result.is<float>()) {
        cout << result.as<float>() << endl;

    } else if (result.is<long>()) {
        cout << result.as<long>() << endl;

    } else if (result.is<double>()) {
        cout << result.as<double>() << endl;
        
    } else if (result.is<short>()) {
        cout << result.as<short>() << endl;
    } else {
        cout << "没有匹配对应的格式" << endl;
    }
}

int main(int argc, const char* argv[]) {

    const char* filepath;
    PlayScriptCompiler compiler;
    AnnotatedTree *at;
    
    if (argc == 2) {
        filepath = argv[1];
        at = compiler.compile(filepath);
    } else if (argc > 3 && argc <= 4) {
        filepath = argv[1];
        const char* verboseStr = argv[2];
        const char* astDumpStr = argv[3];

        bool verbose = strcmp(verboseStr, "true") == 0 ? true : false;
        bool astDump = strcmp(astDumpStr, "true") == 0 ? true : false;
        at = compiler.compile(filepath, verbose, astDump);
    } else {
        cout << "无效参数列表" << endl; 
        return 0;
    }

    if (!at->hasCompilationError()) {
        antlrcpp::Any result = compiler.Execute(at);
        returnMsg(result);
    }

    return 0;
}