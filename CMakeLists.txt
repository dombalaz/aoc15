cmake_minimum_required(VERSION 3.10.2)

project(Advent-of-Code-15)

add_subdirectory(lib)

find_package(GTest)
if(GTEST_FOUND)
    enable_testing()
    add_subdirectory(test)
endif()

