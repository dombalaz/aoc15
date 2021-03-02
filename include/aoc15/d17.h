#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace Aoc15
{
auto solveD17P1(const std::vector<std::string>& in) -> std::int64_t;

auto solveD17P2(const std::vector<std::string>& in) -> std::int64_t;

auto combinationsToTopSum(const std::vector<std::string> &nums, std::uint32_t sum) -> std::uint32_t;

/*
 * This expects sorted array.
 */
auto combinationsToTopSum(const std::vector<std::uint32_t> &nums, std::uint32_t sum, std::uint32_t counter) -> std::uint32_t;

auto combinationsWithMinToTopSum(const std::vector<std::string> &nums, std::uint32_t sum) -> std::uint32_t;

auto combinationsWithMinToTopSum(const std::vector<std::uint32_t> &nums, std::uint32_t sum) -> std::uint32_t;
} // namespace Aoc15