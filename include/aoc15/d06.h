#ifndef AOC15_D06_H
#define AOC15_D06_H

#include <utility>
#include <vector>

using LightsGrid = std::vector<std::vector<bool>>;

using Point = std::pair<size_t, size_t>;

LightsGrid createLightsGrid(size_t width, size_t height, bool init = false);

void turnLightsOn(LightsGrid &lightsGrid, const Point &from, const Point &to);

void turnLightsOff(LightsGrid &lightsGrid, const Point &from, const Point &to);

void toggleLights(LightsGrid &lightsGrid, const Point &from, const Point &to);

bool isLightOn(const LightsGrid &lightsGrid, const Point &point);

size_t countLights(const LightsGrid &lightsGrid);

#endif // AOC15_D06_H

