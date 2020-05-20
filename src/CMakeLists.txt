cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED True)
set(TARGETS
    aoc15_d01
    aoc15_d02
    aoc15_d03
    aoc15_d04
)

add_compile_options(-Wall -Wextra -pedantic -Werror)

foreach(target ${TARGETS})
    add_executable(${target} ${CMAKE_CURRENT_SOURCE_DIR}/${target}.cpp)
    target_include_directories(${target} PUBLIC ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(${target} aoc15)
endforeach(target ${TARGETS})

