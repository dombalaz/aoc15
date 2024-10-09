#pragma once

#include <string>
#include <vector>

namespace Aoc15
{

using CharLightsGrid = std::vector<std::string>;

auto countOn(const std::vector<std::string>& grid) -> int;

auto nextState(const std::vector<std::string>& grid) -> std::vector<std::string>;

auto nextState2(const std::vector<std::string>& grid) -> std::vector<std::string>;

auto solveD18P1(const std::vector<std::string>& in) -> int;

auto solveD18P2(const std::vector<std::string>& in) -> int;

} // namespace Aoc15