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

add_definitions(-DANTLR4CPP_STATIC)
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

# Now build our tools
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

message("${llvm_libs}")
# Link against LLVM libraries
target_link_libraries(${CMAKE_PROJECT_NAME} ${llvm_libs} Boost::tokenizer antlr4_static)
