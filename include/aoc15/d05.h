#pragma once

#include <cstdint>
#include <functional>
#include <string>
#include <vector>

namespace Aoc15
{
auto solveD5P1(const std::vector<std::string> &in) -> std::uint32_t;

auto solveD5P2(const std::vector<std::string> &in) -> std::uint32_t;

auto solveD5(const std::vector<std::string> &in, std::function<bool(std::string_view)> fun) -> std::uint32_t;

auto containsAtLeast3Vowels(std::string_view in) -> bool;

auto containsOneLetterTwiceInRow(std::string_view in) -> bool;

auto doesntContainsTheStrings(std::string_view in) -> bool;

auto isNice(std::string_view in) -> bool;

auto twoPairsOfTwoLetters(std::string_view in) -> bool;

auto repeatedLetterWithLetterBetween(std::string_view in) -> bool;

auto isNice2(std::string_view in) -> bool;
}
