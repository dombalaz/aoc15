#pragma once

#include <cstdint>
#include <functional>
#include <string>
#include <vector>

namespace Aoc15
{
auto solveD2P1(const std::vector<std::string> &in) -> std::uint32_t;

auto solveD2P2(const std::vector<std::string> &in) -> std::uint32_t;

auto solveD2(const std::vector<std::string> &in, std::function<std::uint32_t(std::uint32_t, std::uint32_t, std::uint32_t)> fun) -> std::uint32_t;

auto paperForGift(std::uint32_t x, std::uint32_t y, std::uint32_t z) -> std::uint32_t;

auto ribbonForGift(std::uint32_t x, std::uint32_t y, std::uint32_t z) -> std::uint32_t;
}

