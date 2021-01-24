#include <iostream>
#include "antlr4-runtime.h"
#include "PlayScriptLexer.h"
#include "PlayScriptParser.h"
#include "ASTEvaluator.h"
#include "PlayScriptCompiler.h"
#include "AnnotatedTree.h"
#include "ConvertToAsm.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace antlr4;
using namespace std;
using namespace play;

;

class PlayScript
{
    private:
        char divider_{'/'};

    public:
        PlayScriptCompiler compiler_;
        AnnotatedTree *at_;

        const char* filepath_;
        int astSwitch_{1};
        int symbolSwitch_{0};
        int modelSwith_{1};

    public:
        PlayScript()
        {

        }

        ~PlayScript()
        {
            delete at_;
        }

        void exec()
        {
            bool verbose = symbolSwitch_  == 1 ? true : false;
            bool astDump = astSwitch_ == 1 ? true : false;

            at_ = compiler_.compile(filepath_, verbose, astDump);

            if (!at_->hasCompilationError()) {
                switch (modelSwith_) {
                    case 1:
                        createAST();
                        break;
                    case 2:
                        createASM();
                        break;
                    case 3:
                        createJIT();
                        break;
                    default:
                        cout << "模式选择错误，请重新选择" << endl;
                        break;
                }
            }
        }
    
    private:
        void createAST()
        {
            antlrcpp::Any result = compiler_.Execute(at_);
        }

        void createASM()
        {
            const char *p = strrchr(filepath_, divider_); 
            string result = compiler_.AsmExecute(at_);
            ConvertToAsm convert(p + 1);
            if (convert.output(result)) {
                cout << "导出成功" << endl;
            } else {
                cout << "导出失败" << endl;
            }
        }

        void createJIT()
        {
            compiler_.JitExecute(at_);
        }

};

int main(int argc, const char* argv[]) {

    PlayScript play;

    if (argc <= 1) {
        cout << "请输出测试脚本文件(test目录)" << endl; 
        return 0;
    }

    play.filepath_ = argv[1];

    printf("是否展示AST(0:关闭,1:开启)\n");
    scanf("%d", &play.astSwitch_);

    printf("是否展示符号表(0:关闭,1:开启)\n");
    scanf("%d", &play.symbolSwitch_);

    cout << "请选择模式:(1:普通模式[默认]，2: 生成ASM, 3: 开启JIT)" << endl;
    scanf("%d", &play.modelSwith_);

    play.exec();

    return 0;
}