cmake_minimum_required(VERSION 3.5)
project(play CXX)

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 14)

message(STATUS "PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}")

INCLUDE_DIRECTORIES(
    src/grammar
    third_party/
    third_party/antlr4-cpp-runtime-4.8/src
    src/
)

set(src_dir
    src/grammar/PlayScriptBaseListener.cpp
    src/grammar/PlayScriptBaseVisitor.cpp
    src/grammar/PlayScriptLexer.cpp
    src/grammar/PlayScriptListener.cpp
    src/grammar/PlayScriptParser.cpp
    src/grammar/PlayScriptVisitor.cpp
    src/grammar/ASTEvaluator.h
    src/grammar/ASTEvaluator.cpp
    src/grammar/PlayScriptCompiler.cpp
    src/grammar/Symbol.cpp
    src/grammar/Scope.cpp
    src/grammar/Variable.cpp
    src/grammar/NameSpace.cpp
    src/grammar/Function.cpp
    src/grammar/TypeAndScopeScanner.cpp
    src/grammar/BlockScope.cpp
    src/grammar/Class.cpp
    src/grammar/This.cpp
    src/grammar/AnnotatedTree.cpp
)

file(GLOB antrl-cpp-src
    third_party/antlr4-cpp-runtime-4.8/src/*.cpp
    third_party/antlr4-cpp-runtime-4.8/src/atn/*.cpp
    third_party/antlr4-cpp-runtime-4.8/src/dfa/*.cpp
    third_party/antlr4-cpp-runtime-4.8/src/misc/*.cpp
    third_party/antlr4-cpp-runtime-4.8/src/support/*.cpp
    third_party/antlr4-cpp-runtime-4.8/src/tree/*.cpp
    third_party/antlr4-cpp-runtime-4.8/src/tree/pattern/*.cpp
    third_party/antlr4-cpp-runtime-4.8/src/tree/xpath/*.cpp
)

add_library(antlr-cpp-runtime ${antrl-cpp-src})
add_executable(play ${src_dir} src/main.cpp)
target_link_libraries(play antlr-cpp-runtime)