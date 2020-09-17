#include <iostream>
#include "antlr4-runtime.h"
#include "PlayScriptLexer.h"
#include "PlayScriptParser.h"
#include "ASTEvaluator.h"
#include "PlayScriptCompiler.h"
#include <iostream>

using namespace antlr4;
using namespace std;
using namespace play;

int main(int argc, const char* argv[]) {

    const char* filepath;
    PlayScriptCompiler compiler;
    
    if (argc == 2) {
        filepath = argv[1];
        compiler.compile(filepath);
    } else if (argc > 3 && argc <= 4) {
        filepath = argv[1];
        const char* verboseStr = argv[2];
        const char* astDumpStr = argv[3];

        bool verbose = strcmp(verboseStr, "true") == 0 ? true : false;
        bool astDump = strcmp(astDumpStr, "true") == 0 ? true : false;
        compiler.compile(filepath, verbose, astDump);
    } else {
        cout << "无效参数列表" << endl; 
    }

    return 0;
}