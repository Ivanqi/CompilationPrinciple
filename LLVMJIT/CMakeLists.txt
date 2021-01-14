# CMakeLists.txt

# minimum required CMAKE version
cmake_minimum_required(VERSION 3.5)

project(llvmjit CXX)

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 14)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

message(STATUS "LLVM_INCLUDE_DIRS: ${LLVM_INCLUDE_DIRS}")
message(STATUS "LLVM_DEFINITIONS: ${LLVM_DEFINITIONS}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(SRC_LIST main.cpp llvmjit.h)

MESSAGE(STATUS "SRC_LIST: " ${SRC_LIST})

add_executable(llvmjit ${SRC_LIST})

llvm_map_components_to_libnames(llvm_libs all)

message(STATUS "llvm_libs: " ${llvm_libs})

target_link_libraries(llvmjit  ${llvm_libs})