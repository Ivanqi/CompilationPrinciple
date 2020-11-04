cmake_minimum_required(VERSION 3.5)
project(report CXX)

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
    src/grammar/PlayReportBaseListener.cpp
    src/grammar/PlayReportBaseVisitor.cpp
    src/grammar/PlayReportLexer.cpp
    src/grammar/PlayReportListener.cpp
    src/grammar/PlayReportParser.cpp
    src/grammar/PlayReportVisitor.cpp
    src/grammar/ReportTemplate.cpp
    src/grammar/TabularData.cpp
    src/grammar/PlayReport.cpp
    src/grammar/PrimitiveType.cpp
    src/grammar/BinaryOp.cpp
    src/grammar/Add.cpp
    src/grammar/Minus.cpp
    src/grammar/Mul.cpp
    src/grammar/Div.cpp
    src/grammar/EQ.cpp
    src/grammar/GE.cpp
    src/grammar/GT.cpp
    src/grammar/LE.cpp
    src/grammar/LT.cpp
    src/grammar/FieldEvaluator.cpp
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

add_executable(report ${src_dir} src/main.cpp)

target_link_libraries(report antlr-cpp-runtime)