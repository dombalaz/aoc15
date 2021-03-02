#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace Aoc15
{
auto solveD8P1(const std::vector<std::string> &in) -> size_t;

auto solveD8P2(const std::vector<std::string> &in) -> size_t;

auto countCharacters(std::string_view s) -> size_t;

auto countEncodedChars(std::string_view s) -> size_t;
}
