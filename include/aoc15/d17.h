#pragma once

#include <cstdint>
#include <string>
#include <vector>

using uint = std::uint32_t;

auto combinationsToTopSum(const std::vector<std::string> &nums, uint sum) -> uint;

/*
 * This expects sorted array.
 */
auto combinationsToTopSum(const std::vector<uint> &nums, uint sum, uint counter) -> uint;

auto combinationsWithMinToTopSum(const std::vector<std::string> &nums, uint sum) -> uint;

auto combinationsWithMinToTopSum(const std::vector<uint> &nums, uint sum) -> uint;
