cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

set(HEADER_FILES include/guajavita/commons/version.h)
set(SOURCE_FILES src/version.cpp)
add_library(GuaJavitaC STATIC ${SOURCE_FILES})
target_include_directories(GuaJavitaC PRIVATE include/guajavita/commons)
target_include_directories(GuaJavitaC PUBLIC include/)
