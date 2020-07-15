#include <aoc15/d06.h>

#include <algorithm>
#include <numeric>

LightsGrid createLightsGrid(size_t width, size_t height, bool init)
{
    return LightsGrid(height, std::vector<bool>(width, init));
}

void doLights(LightInstruction li, LightsGrid lg, const Point &from, const Point &to)
{
    switch (li) {
    case LightInstruction::On :
        turnLightsOn(lg, from, to);
        break;
    case LightInstruction::Off :
        turnLightsOff(lg, from, to);
        break;
    case LightInstruction::Toggle :
        toggleLights(lg, from, to);
        break;
    }
}

void turnLightsOn(LightsGrid &lg, const Point &from, const Point &to)
{
    for (size_t i = from.second; i <= to.second; ++i) {
        for (size_t j = from.first; j <= to.first; ++j) {
            lg[i][j] = true;
        }
    }
}

void turnLightsOff(LightsGrid &lg, const Point &from, const Point &to)
{
    for (size_t i = from.second; i <= to.second; ++i) {
        for (size_t j = from.first; j <= to.first; ++j) {
            lg[i][j] = false;
        }
    }
}

void toggleLights(LightsGrid &lg, const Point &from, const Point &to)
{
    for (size_t i = from.second; i <= to.second; ++i) {
        for (size_t j = from.first; j <= to.first; ++j) {
            lg[i][j] = !lg[i][j];
        }
    }
}

size_t countLightsOn(const LightsGrid &lg)
{
    return std::accumulate(lg.begin(), lg.end(), 0, [](const auto &lhs, const auto &rhs) -> size_t { return lhs + std::count(rhs.begin(), rhs.end(), true); });
}
