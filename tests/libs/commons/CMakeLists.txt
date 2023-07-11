cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

CPMAddPackage("gh:doctest/doctest@2.4.11")
add_executable(GuajavitaLCT src/test.cpp)
target_link_libraries(GuajavitaLCT  doctest)
enable_testing()
add_test(GuajavitaLCT GuajavitaLCT)
