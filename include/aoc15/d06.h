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

#endif // AOC15_D06_H

