cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED True)
set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/aoc15_d01.cpp
)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(aoc15_d01 ${SOURCE})

target_include_directories(aoc15_d01 PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(aoc15_d01 aoc15)
