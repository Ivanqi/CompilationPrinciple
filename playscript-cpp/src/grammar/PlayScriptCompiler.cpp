#include "PlayScriptCompiler.h"
#include "TypeAndScopeScanner.h"
#include "TypeResolver.h"
#include "RefResolver.h"
using namespace play;

AnnotatedTree* PlayScriptCompiler::compile(const char* script, bool verbose, bool ast_dump)
{
        AnnotatedTree *at;
        std::ifstream ifs;
        ifs.open(script);

        ANTLRInputStream input(ifs);
        PlayScriptLexer lexer(&input);
        CommonTokenStream tokens(&lexer);

        tokens.fill();

        PlayScriptParser parser(&tokens);

        at->ast = parser.prog();

        // 语义分析
        ParseTreeWalker walker;

        // 多步的语义分析
        //优点：1.代码清晰; 2.允许使用声明之前，这在支持面向对象，递归函数等特征时是必须的
        //parse1: 类型和Scope
        
        // pass1: 类型和Scope
        TypeAndScopeScanner *pass1 = new TypeAndScopeScanner(at);
        walker.walk(pass1, at->ast);

        // pass2: 把变量，类继承，函数声明的类型都解析出来。也就是所有声明用到类型的地方
        TypeResolver *pass2 = new TypeResolver(at);
        walker.walk(pass2, at->ast);


        

        return at;
}