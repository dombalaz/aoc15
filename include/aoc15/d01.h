#pragma once

#include <cstdint>
#include <string_view>

namespace Aoc15
{
/**
 * @brief Computes the floor that Santa is taken to.
 * 
 * The valid input contains only symbols '(' and ')'. If the input is invalid
 * the exception is thrown.
 * 
 * @param input Floor instructions.
 * @return int Resulting floor.
 */
auto solveD1P1(std::string_view in) -> int;

/**
 * @brief Computes the position of the basement character.
 * 
 * The basement character is the character, that causes Santa to first enter
 * the basement. If the input is invalid the exception is thrown. If the
 * basement character doesn't exist for given input, the result will be empty. 
 * 
 * @param in Floor instructions.
 * @return unsigned Position of the basement character.
 */
auto solveD1P2(std::string_view in) -> std::uint32_t;
}