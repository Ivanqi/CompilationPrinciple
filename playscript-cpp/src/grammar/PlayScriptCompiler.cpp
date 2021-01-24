#include "PlayScriptCompiler.h"
#include "TypeAndScopeScanner.h"
#include "TypeResolver.h"
#include "RefResolver.h"
#include "TypeChecker.h"
#include "SematicValidator.h"
#include "ClosureAnalyzer.h"
#include "ASTEvaluator.h"
#include "AsmGen.h"
#include "IRGen.h"

#include <iostream>

using namespace play;

AnnotatedTree* PlayScriptCompiler::compile(std::string script, bool verbose, bool ast_dump)
{
    at_ = new AnnotatedTree();
    std::ifstream ifs;
    ifs.open(script);

    ANTLRInputStream *input = new ANTLRInputStream(ifs);
    PlayScriptLexer *lexer = new PlayScriptLexer(input);
    CommonTokenStream *tokens = new CommonTokenStream(lexer);

    tokens->fill();

    parser = new PlayScriptParser(tokens);

    at_->ast = parser->prog();
    

    // 语义分析
    ParseTreeWalker walker;

    // 多步的语义分析
    //优点：1.代码清晰; 2.允许使用声明之前，这在支持面向对象，递归函数等特征时是必须的
    //parse1: 类型和Scope
    
    // pass1: 类型和Scope
    TypeAndScopeScanner *pass1 = new TypeAndScopeScanner(at_);
    walker.walk(pass1, at_->ast);


    // pass2: 把变量，类继承，函数声明的类型都解析出来。也就是所有声明用到类型的地方
    TypeResolver *pass2 = new TypeResolver(at_);
    walker.walk(pass2, at_->ast);

    // pass3: 消解所有的变量引用，函数引用。另外还做了类型的推断
    RefResolver *pass3 = new RefResolver(at_);
    walker.walk(pass3, at_->ast);
    
    // pass4: 类型检查
    TypeChecker *pass4 = new TypeChecker(at_);
    walker.walk(pass4, at_->ast);

    // pass5: 其他语义检查
    SematicValidator *pass5 = new SematicValidator(at_);
    walker.walk(pass5, at_->ast);

    // pass6: 做闭包的分析
    ClosureAnalyzer *closureAnalyzer = new ClosureAnalyzer(at_);
    closureAnalyzer->analyzeClosures();

    // 打印AST
    if (verbose || ast_dump){
        dumpAST();
    }

    //打印符号表
    if(verbose){
        dumpSymbols();
    }
    
    return at_;

};

AnnotatedTree* PlayScriptCompiler::compile(std::string script)
{
    return compile(script, false, false);
}

// 打印符号表
void PlayScriptCompiler::dumpSymbols()
{
    if (at_ != NULL) {
        std::cout << at_->getScopeTreeString() << std::endl;
    }
}

void PlayScriptCompiler::dumpAST()
{
    if (at_ != NULL) {
        std::cout << at_->ast->toStringTree(parser) << std::endl;
    }
    std::cout << std::endl;
}

antlrcpp::Any PlayScriptCompiler::Execute(AnnotatedTree *at)
{
    ASTEvaluator *visitor = new ASTEvaluator(at);
    antlrcpp::Any result = visitor->visit(at->ast);
    return result;
}

string PlayScriptCompiler::AsmExecute(AnnotatedTree *at)
{
    AsmGen *visitor = new AsmGen(at);
    string result = visitor->generate();

    return result;
}

void PlayScriptCompiler::IRExecute(AnnotatedTree *at)
{
    IRGen irGen;
    irGen.InitializeModuleAndPassManager();

    irGen.visit(at->ast);
    irGen.PrintIR();
    irGen.ExecuteJIT();
}