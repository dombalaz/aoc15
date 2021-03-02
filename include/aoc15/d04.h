#pragma once

#include <cstdint>
#include <string_view>

namespace Aoc15
{
constexpr auto D4P1Number{5};

constexpr auto D4P2Number{6};

auto solveD4P1(std::string_view in) -> std::uint32_t;

auto solveD4P2(std::string_view in) -> std::uint32_t;

auto solveD4(std::string_view in, std::uint32_t leadingZeroes) -> std::uint32_t;
}
