cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED True)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(aoc15-d01-unittest aoc15_d01_unittest.cc)
add_executable(aoc15-d02-unittest aoc15_d02_unittest.cc)

target_include_directories(
    aoc15-d01-unittest PUBLIC ${CMAKE_SOURCE_DIR}/include
)
target_include_directories(
    aoc15-d02-unittest PUBLIC ${CMAKE_SOURCE_DIR}/include
)
target_include_directories(aoc15-d01-unittest PUBLIC ${GTEST_INCLUDE_DIRS})
target_include_directories(aoc15-d02-unittest PUBLIC ${GTEST_INCLUDE_DIRS})

target_link_libraries(aoc15-d01-unittest aoc15 GTest::GTest GTest::Main)
target_link_libraries(aoc15-d02-unittest aoc15 GTest::GTest GTest::Main)

add_test(TestAoC15D01 aoc15-d01-unittest)
add_test(TestAoC15D02 aoc15-d02-unittest)

add_custom_target(
    check COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS aoc15-d01-unittest aoc15-d02-unittest
)
