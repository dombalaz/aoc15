cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED True)
set(TARGETS
    aoc15_d01_unittest
    aoc15_d02_unittest    
    aoc15_d03_unittest
    aoc15_d04_unittest
    aoc15_d05_unittest
    aoc15_d06_unittest
    aoc15_d07_unittest
    aoc15_d08_unittest
    aoc15_d09_unittest
    aoc15_d10_unittest
    aoc15_d11_unittest
    aoc15_d12_unittest
)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_custom_target(valgrind)

foreach(target ${TARGETS})
    add_executable(${target} ${target}.cc)
    target_include_directories(
        ${target} PRIVATE ${CMAKE_SOURCE_DIR}/include
    )
    target_include_directories(${target} PRIVATE ${GTEST_INCLUDE_DIRS})
    target_link_libraries(${target} aoc15 GTest::GTest GTest::Main)
    add_test(Test_${target} ${target} --gtest_output=xml:${target}-report.xml)

    add_custom_target(valgrind_${target} COMMAND valgrind --leak-check=full -s --error-exitcode=1 ${CMAKE_CURRENT_BINARY_DIR}/${target} DEPENDS ${target})
    add_dependencies(valgrind valgrind_${target})
endforeach(target ${TARGETS})

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS ${TARGETS})
