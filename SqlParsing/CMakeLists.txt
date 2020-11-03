cmake_minimum_required(VERSION 3.5)
project(SqlParsing CXX)

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
    src/grammar/SqlParsingBaseListener.cpp
    src/grammar/SqlParsingBaseVisitor.cpp
    src/grammar/SqlParsingLexer.cpp
    src/grammar/SqlParsingListener.cpp
    src/grammar/SqlParsingParser.cpp
    src/grammar/SqlParsingVisitor.cpp
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


add_library(antlr-cpp-runtime ${antrl-cpp-src})

add_executable(play ${src_dir} src/main.cpp)

target_link_libraries(play antlr-cpp-runtime)