#include "SimpleScript.h"

int main(int argc, char* argv[]) {

    SimpleScript *script = new SimpleScript();
    script->REPL(argc, argv);
    return 0;
}