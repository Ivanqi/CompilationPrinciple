#include <iostream>
#include "antlr4-runtime.h"
#include "PlayScriptLexer.h"
#include "PlayScriptParser.h"
#include "ASTEvaluator.h"

using namespace antlr4;
using namespace std;

int main(int argc, const char* argv[]) {
    const char* filepath = argv[1];
    std::ifstream ifs;
    ifs.open(filepath);

    ANTLRInputStream input(ifs);
    PlayScriptLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();
    for (auto token : tokens.getTokens()) {
        std::cout << token->toString() << std::endl;
    }

    PlayScriptParser parser(&tokens);
    tree::ParseTree *tree = parser.prog();

    cout << tree->toStringTree(&parser) << endl;

    return 0;
}