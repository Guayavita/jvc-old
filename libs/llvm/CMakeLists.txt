cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)
include(${CMAKE_HOME_DIRECTORY}/cmake/LLVM.cmake)

set(HEADER_FILES include/guajavita/llvm/jvLLVM.h)
set(SOURCE_FILES src/llvm.cpp)
llvm_map_components_to_libnames(llvm_libs support core irreader)

add_library(GuaJavitaLLVM STATIC ${SOURCE_FILES})
target_link_libraries(GuaJavitaLLVM ${llvm_libs})
target_include_directories(GuaJavitaLLVM PRIVATE include/guajavita/llvm)
target_include_directories(GuaJavitaLLVM PUBLIC include/)