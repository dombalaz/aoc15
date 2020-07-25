cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED True)
set(AOC15_BIN aoc15-bin)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(${AOC15_BIN} ${CMAKE_CURRENT_SOURCE_DIR}/aoc15.cpp)
target_include_directories(${AOC15_BIN} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${AOC15_BIN} aoc15)
set_target_properties(${AOC15_BIN} PROPERTIES OUTPUT_NAME aoc15)
