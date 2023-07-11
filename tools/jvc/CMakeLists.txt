cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

CPMAddPackage(
        NAME COBALT
        VERSION 0.3
        GITHUB_REPOSITORY "florianwolz/cobalt"
        GIT_TAG "0.3"
)
message(STATUS "Added ${COBALT_SOURCE_DIR}")
set(SOURCE_FILES src/main.cpp)
include_directories(${COBALT_SOURCE_DIR})
add_executable(jvc ${SOURCE_FILES})
target_link_libraries(jvc LINK_PRIVATE GuaJavitaC GuaJavitaLLVM)
