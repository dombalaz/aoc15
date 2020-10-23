cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED True)
set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/d01.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d02.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d03.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d04.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d05.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d06.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d07.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d08.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d09.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d10.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d11.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d12.cpp
)
set(AOC15_LIBRARY aoc15)

add_compile_options(-Wall -Wextra -pedantic)

add_library(${AOC15_LIBRARY} SHARED ${SOURCE})

target_include_directories(${AOC15_LIBRARY} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${AOC15_LIBRARY} PUBLIC ${OPENSSL_INCLUDE_DIR})
target_link_libraries(${AOC15_LIBRARY} ${OPENSSL_CRYPTO_LIBRARY})
target_link_libraries(${AOC15_LIBRARY} nlohmann_json::nlohmann_json)
