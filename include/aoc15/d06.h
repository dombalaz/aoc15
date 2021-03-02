#pragma once

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

namespace Aoc15
{
using Point = std::pair<std::uint32_t, std::uint32_t>;

using LightsGrid = std::vector<std::vector<bool>>;

using BLightsGrid = std::vector<std::vector<std::uint32_t>>;

enum class LightInstruction
{
    On,
    Off,
    Toggle
};

constexpr auto LightsGridSize{1000U};

constexpr auto InstructionIndex{1U};
constexpr auto FirstPointXIndex{2U};
constexpr auto FirstPointYIndex{3U};
constexpr auto SecondPointXIndex{4U};
constexpr auto SecondPointYIndex{5U};

auto solveD6P1(const std::vector<std::string> &in) -> std::uint32_t;

auto solveD6P2(const std::vector<std::string> &in) -> std::uint32_t;

auto createLightsGrid(std::uint32_t width, std::uint32_t height, bool init = false) -> LightsGrid;

void doLights(LightInstruction li, LightsGrid &lg, const Point &from, const Point &to);

void turnLightsOn(LightsGrid &lg, const Point &from, const Point &to);

void turnLightsOff(LightsGrid &lg, const Point &from, const Point &to);

void toggleLights(LightsGrid &lg, const Point &from, const Point &to);

auto countLightsOn(const LightsGrid &lg) -> std::uint32_t;

auto createBLightsGrid(std::uint32_t width, std::uint32_t height, std::uint32_t init = 0) -> BLightsGrid;

void doLights(LightInstruction li, BLightsGrid &blg, const Point &from, const Point &to);

void turnLightsOn(BLightsGrid &blg, const Point &from, const Point &to);

void turnLightsOff(BLightsGrid &blg, const Point &from, const Point &to);

void toggleLights(BLightsGrid &blg, const Point &from, const Point &to);

auto totalBrightness(const BLightsGrid &blg) -> std::uint32_t;
}
