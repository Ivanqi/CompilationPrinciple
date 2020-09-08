#include <iostream>
#include "antlr4-runtime.h"
#include "PlayScriptLexer.h"
#include "PlayScriptParser.h"
#include "ASTEvaluator.h"
#include "PlayScriptCompiler.h"

using namespace antlr4;
using namespace std;
using namespace play;

int main(int argc, const char* argv[]) {
    const char* filepath = argv[1];

    PlayScriptCompiler compiler;
    compiler.compile(filepath, true, true);

    
    // std::ifstream ifs;
    // ifs.open(filepath);

    // ANTLRInputStream input(ifs);
    // PlayScriptLexer lexer(&input);
    // CommonTokenStream tokens(&lexer);

    // tokens.fill();
    // for (auto token : tokens.getTokens()) {
    //     std::cout << token->toString() << std::endl;
    // }

    // PlayScriptParser parser(&tokens);
    // tree::ParseTree *tree = parser.prog();

    // cout << tree->toStringTree(&parser) << endl;

    return 0;
}