#include <aoc15/d06.h>

#include <algorithm>
#include <numeric>

auto createLightsGrid(size_t width, size_t height, bool init) -> LightsGrid
{
    return LightsGrid(height, std::vector<bool>(width, init));
}

void doLights(LightInstruction li, LightsGrid &lg, const Point &from, const Point &to)
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

auto countLightsOn(const LightsGrid &lg) -> size_t
{
    return std::accumulate(lg.begin(), lg.end(), 0, [](const auto &lhs, const auto &rhs) -> size_t { return lhs + std::count(rhs.begin(), rhs.end(), true); });
}

auto createBLightsGrid(size_t width, size_t height, size_t init) -> BLightsGrid
{
    return BLightsGrid(height, std::vector<size_t>(width, init));
}

void doLights(LightInstruction li, BLightsGrid &blg, const Point &from, const Point &to)
{
    switch (li) {
    case LightInstruction::On :
        turnLightsOn(blg, from, to);
        break;
    case LightInstruction::Off :
        turnLightsOff(blg, from, to);
        break;
    case LightInstruction::Toggle :
        toggleLights(blg, from, to);
        break;
    }
}

void turnLightsOn(BLightsGrid &blg, const Point &from, const Point &to)
{
    for (size_t i = from.second; i <= to.second; ++i) {
        for (size_t j = from.first; j <= to.first; ++j) {
            if (blg[i][j] != std::numeric_limits<size_t>::max()) {
                ++(blg[i][j]);
            }
        }
    }
}

void turnLightsOff(BLightsGrid &blg, const Point &from, const Point &to)
{
    for (size_t i = from.second; i <= to.second; ++i) {
        for (size_t j = from.first; j <= to.first; ++j) {
            if(blg[i][j] != 0) {
                --(blg[i][j]);
            }
        }
    }
}

void toggleLights(BLightsGrid &blg, const Point &from, const Point &to)
{
    turnLightsOn(blg, from, to);
    turnLightsOn(blg, from, to);
}

auto totalBrightness(const BLightsGrid &blg) -> size_t
{
    return std::accumulate(blg.begin(), blg.end(), 0UL, [](const auto &lhs, const auto &rhs) -> size_t { return lhs + std::accumulate(rhs.begin(), rhs.end(), 0UL); });
}
