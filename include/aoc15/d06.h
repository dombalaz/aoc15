#pragma once

#include <utility>
#include <vector>

enum class LightInstruction
{
    On,
    Off,
    Toggle
};

constexpr auto LightsGridSize{1000U};

using LightsGrid = std::vector<std::vector<bool>>;

using Point = std::pair<size_t, size_t>;

auto createLightsGrid(size_t width, size_t height, bool init = false) -> LightsGrid;

void doLights(LightInstruction li, LightsGrid &lg, const Point &from, const Point &to);

void turnLightsOn(LightsGrid &lg, const Point &from, const Point &to);

void turnLightsOff(LightsGrid &lg, const Point &from, const Point &to);

void toggleLights(LightsGrid &lg, const Point &from, const Point &to);

auto countLightsOn(const LightsGrid &lg) -> size_t;

using BLightsGrid = std::vector<std::vector<size_t>>;

auto createBLightsGrid(size_t width, size_t height, size_t init = 0) -> BLightsGrid;

void doLights(LightInstruction li, BLightsGrid &blg, const Point &from, const Point &to);

void turnLightsOn(BLightsGrid &blg, const Point &from, const Point &to);

void turnLightsOff(BLightsGrid &blg, const Point &from, const Point &to);

void toggleLights(BLightsGrid &blg, const Point &from, const Point &to);

auto totalBrightness(const BLightsGrid &blg) -> size_t;
