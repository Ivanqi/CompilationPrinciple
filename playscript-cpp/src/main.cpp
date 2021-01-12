#include <iostream>
#include "antlr4-runtime.h"
#include "PlayScriptLexer.h"
#include "PlayScriptParser.h"
#include "ASTEvaluator.h"
#include "PlayScriptCompiler.h"
#include "AnnotatedTree.h"
#include "ConvertToAsm.h"
#include <iostream>

using namespace antlr4;
using namespace std;
using namespace play;

int main(int argc, const char* argv[]) {

    const char* filepath;
    PlayScriptCompiler compiler;
    AnnotatedTree *at;
    bool asmFlag = false;
    
    if (argc == 2) {
        filepath = argv[1];
        at = compiler.compile(filepath);
    } else if (argc > 3 && argc <= 5) {
        filepath = argv[1];
        const char* verboseStr = argv[2];
        const char* astDumpStr = argv[3];
        const char* astStr = argv[4];

        bool verbose = strcmp(verboseStr, "true") == 0 ? true : false;
        bool astDump = strcmp(astDumpStr, "true") == 0 ? true : false;
        asmFlag = strcmp(astStr, "true") == 0 ? true : false;
        at = compiler.compile(filepath, verbose, astDump);
    } else {
        cout << "无效参数列表" << endl; 
        return 0;
    }

    if (!at->hasCompilationError()) {
        if (asmFlag) {
            string result = compiler.AsmExecute(at);
            ConvertToAsm convert;
            if (convert.output(result)) {
                cout << "导出成功" << endl;
            } else {
                cout << "导出失败" << endl;
            }
        } else {
            antlrcpp::Any result = compiler.Execute(at);
        }
    }

    return 0;
}