cmake_minimum_required(VERSION 3.5)
project(play CXX)

set(CMAKE_CXX_COMPILER "c++")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS -g)

message(STATUS "PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}")

INCLUDE_DIRECTORIES(
    src/grammar
    ../third_party/
    ../third_party/antlr4-cpp-runtime-4.8/src
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
    src/grammar/TypeResolver.cpp
    src/grammar/VoidType.cpp
    src/grammar/DefaultFunctionType.cpp
    src/grammar/PrimitiveType.cpp
    src/grammar/RefResolver.cpp
    src/grammar/TypeChecker.cpp
    src/grammar/SematicValidator.cpp
    src/grammar/ClosureAnalyzer.cpp
    src/grammar/StackFrame.cpp
    src/grammar/PlayObject.cpp
    src/grammar/MyLValue.cpp
    src/grammar/FunctionObject.cpp
    src/grammar/ClassObject.cpp
    src/grammar/NullObject.cpp
    src/grammar/AsmGen.cpp
    src/grammar/ConvertToAsm.cpp
    src/grammar/IRGen.cpp
)

file(GLOB antrl-cpp-src
    ../third_party/antlr4-cpp-runtime-4.8/src/*.cpp
    ../third_party/antlr4-cpp-runtime-4.8/src/atn/*.cpp
    ../third_party/antlr4-cpp-runtime-4.8/src/dfa/*.cpp
    ../third_party/antlr4-cpp-runtime-4.8/src/misc/*.cpp
    ../third_party/antlr4-cpp-runtime-4.8/src/support/*.cpp
    ../third_party/antlr4-cpp-runtime-4.8/src/tree/*.cpp
    ../third_party/antlr4-cpp-runtime-4.8/src/tree/pattern/*.cpp
    ../third_party/antlr4-cpp-runtime-4.8/src/tree/xpath/*.cpp
)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

message(STATUS "LLVM_INCLUDE_DIRS: ${LLVM_INCLUDE_DIRS}")
message(STATUS "LLVM_DEFINITIONS: ${LLVM_DEFINITIONS}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

MESSAGE(STATUS "SRC_LIST: " ${SRC_LIST})

llvm_map_components_to_libnames(llvm_libs all)

message(STATUS "llvm_libs: " ${llvm_libs})

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

add_library(antlr-cpp-runtime ${antrl-cpp-src})

add_executable(play ${src_dir} src/main.cpp)

target_link_libraries(play antlr-cpp-runtime)

target_link_libraries(play ${llvm_libraries})
target_link_libraries(play  ${llvm_libs})