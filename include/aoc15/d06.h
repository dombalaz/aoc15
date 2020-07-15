#ifndef AOC15_D06_H
#define AOC15_D06_H

#include <utility>
#include <vector>

enum class LightInstruction
{
    On,
    Off,
    Toggle
};

constexpr auto LightsGridSize{1000u};

using LightsGrid = std::vector<std::vector<bool>>;

using Point = std::pair<size_t, size_t>;

LightsGrid createLightsGrid(size_t width, size_t height, bool init = false);

void doLights(LightInstruction li, LightsGrid &lg, const Point &from, const Point &to);

void turnLightsOn(LightsGrid &lg, const Point &from, const Point &to);

void turnLightsOff(LightsGrid &lg, const Point &from, const Point &to);

void toggleLights(LightsGrid &lg, const Point &from, const Point &to);

size_t countLightsOn(const LightsGrid &lg);

using BLightsGrid = std::vector<std::vector<size_t>>;

BLightsGrid createBLightsGrid(size_t width, size_t height, size_t init = 0);

void doLights(LightInstruction li, BLightsGrid &lg, const Point &from, const Point &to);

void turnLightsOn(BLightsGrid &lg, const Point &from, const Point &to);

void turnLightsOff(BLightsGrid &lg, const Point &from, const Point &to);

void toggleLights(BLightsGrid &lg, const Point &from, const Point &to);

size_t totalBrightness(const BLightsGrid &lg);

#endif // AOC15_D06_H

