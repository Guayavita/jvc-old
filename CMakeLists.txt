cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)
project(jvc)


include(cmake/CPM.cmake)

find_package(LLVM REQUIRED CONFIG)


CPMAddPackage(
  NAME Boost
  VERSION 1.82.0
  GITHUB_REPOSITORY "boostorg/boost"
  GIT_TAG "boost-1.82.0"
)

CPMAddPackage(
  NAME ANTLR4
  VERSION 4.13.0
  GITHUB_REPOSITORY "antlr/antlr4"
  GIT_TAG "4.13.0"
  )

list(APPEND CMAKE_MODULE_PATH ${ANTLR4_SOURCE_DIR}/runtime/Cpp/cmake/)
add_definitions(-DANTLR4CPP_STATIC)
set(ANTLR4_WITH_STATIC_CRT OFF)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "ANTLR4 Path ${ANTLR4_SOURCE_DIR}")
include("${ANTLR4_SOURCE_DIR}/runtime/Cpp/cmake/ExternalAntlr4Cpp.cmake")
# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${ANTLR4_INCLUDE_DIRS})
#include_directories("${ANTLR4_SOURCE_DIR}/runtime/Cpp/runtime/src/")
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
set(Java_JAVA_EXECUTABLE "/home/cortiz/.sdkman/candidates/java/current/bin/java")
message(STATUS "AS ${Java_JAVA_EXECUTABLE}")
set(ANTLR_EXECUTABLE "${CMAKE_HOME_DIRECTORY}/tools/antlr-4.13.0-complete.jar")
find_package(ANTLR REQUIRED)

antlr_target(SampleGrammarLexer ${CMAKE_HOME_DIRECTORY}/antlr/guajavita.g4 LEXER
        PACKAGE antlrcpptest)


# include generated files in project environment
include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})

# add generated grammar to demo binary target
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp
        ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
        )

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

message("${llvm_libs}")
# Link against LLVM libraries
target_link_libraries(${CMAKE_PROJECT_NAME} ${llvm_libs} Boost::tokenizer antlr4_static)
