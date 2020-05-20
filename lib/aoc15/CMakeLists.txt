cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED True)
set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/d01.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d02.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d03.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d04.cpp
)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_library(aoc15 SHARED ${SOURCE})

target_include_directories(aoc15 PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(aoc15 PUBLIC ${OPENSSL_INCLUDE_DIR})
target_link_libraries(aoc15 ${OPENSSL_CRYPTO_LIBRARY})
