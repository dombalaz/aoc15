#pragma once

#include <string_view>

namespace Aoc15
{
auto solveD11P1(std::string_view in) -> std::string;

auto solveD11P2(std::string_view in) -> std::string;

auto containsIncreasingStraightOf3Letters(std::string_view in) -> bool;

auto doesntContainsLetters(std::string_view in) -> bool;

auto containsLetterPairs(std::string_view in) -> bool;

auto nextPass(std::string_view in) -> std::string;

auto nextValidPass(std::string_view in) -> std::string;
}