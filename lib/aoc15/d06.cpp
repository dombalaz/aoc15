#include <aoc15/d06.h>

#include <algorithm>
#include <limits>
#include <numeric>
#include <regex>

const std::regex regexD6("(turn on|toggle|turn off) ([0-9]*),([0-9]*) through ([0-9]*),([0-9]*)");

auto Aoc15::solveD6P1(const std::vector<std::string> &in) -> std::uint32_t
{
    auto lg = createLightsGrid(LightsGridSize, LightsGridSize);
    std::smatch match;
    for (const auto &s : in) {
        std::regex_match(s, match, regexD6);
        LightInstruction li{LightInstruction::On};
        if(match[InstructionIndex] == "turn on") {
            li = LightInstruction::On;
        } else if (match[1] == "turn off") {
            li = LightInstruction::Off;
        } else { 
            li = LightInstruction::Toggle;
        }
        Point from{std::stoul(match[FirstPointXIndex]), std::stoul(match[FirstPointYIndex])};
        Point to{std::stoul(match[SecondPointXIndex]), std::stoul(match[SecondPointYIndex])};
        doLights(li, lg, from, to);
    }

    return countLightsOn(lg);
}

auto Aoc15::solveD6P2(const std::vector<std::string> &in) -> std::uint32_t
{
    auto blg = createBLightsGrid(LightsGridSize, LightsGridSize);
    std::smatch match;
    for (const auto &s : in) {
        std::regex_match(s, match, regexD6);
        LightInstruction li{LightInstruction::On};
        if(match[InstructionIndex] == "turn on") {
            li = LightInstruction::On;
        } else if (match[1] == "turn off") {
            li = LightInstruction::Off;
        } else { 
            li = LightInstruction::Toggle;
        }
        Point from{std::stoul(match[FirstPointXIndex]), std::stoul(match[FirstPointYIndex])};
        Point to{std::stoul(match[SecondPointXIndex]), std::stoul(match[SecondPointYIndex])};
        doLights(li, blg, from, to);
    }

    return totalBrightness(blg);
}

auto Aoc15::createLightsGrid(std::uint32_t width, std::uint32_t height, bool init) -> LightsGrid
{
    return LightsGrid(height, std::vector<bool>(width, init));
}

void Aoc15::doLights(LightInstruction li, LightsGrid &lg, const Point &from, const Point &to)
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

void Aoc15::turnLightsOn(LightsGrid &lg, const Point &from, const Point &to)
{
    for (auto i{from.second}; i <= to.second; ++i) {
        for (auto j{from.first}; j <= to.first; ++j) {
            lg[i][j] = true;
        }
    }
}

void Aoc15::turnLightsOff(LightsGrid &lg, const Point &from, const Point &to)
{
    for (auto i{from.second}; i <= to.second; ++i) {
        for (auto j {from.first}; j <= to.first; ++j) {
            lg[i][j] = false;
        }
    }
}

void Aoc15::toggleLights(LightsGrid &lg, const Point &from, const Point &to)
{
    for (auto i{from.second}; i <= to.second; ++i) {
        for (auto j{from.first}; j <= to.first; ++j) {
            lg[i][j] = !lg[i][j];
        }
    }
}

auto Aoc15::countLightsOn(const LightsGrid &lg) -> std::uint32_t
{
    return std::accumulate(lg.begin(), lg.end(), 0, [](const auto &lhs, const auto &rhs) -> std::uint32_t { return lhs + std::count(rhs.begin(), rhs.end(), true); });
}

auto Aoc15::createBLightsGrid(std::uint32_t width, std::uint32_t height, std::uint32_t init) -> BLightsGrid
{
    return BLightsGrid(height, std::vector<std::uint32_t>(width, init));
}

void Aoc15::doLights(LightInstruction li, BLightsGrid &blg, const Point &from, const Point &to)
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

void Aoc15::turnLightsOn(BLightsGrid &blg, const Point &from, const Point &to)
{
    for (auto i{from.second}; i <= to.second; ++i) {
        for (auto j{from.first}; j <= to.first; ++j) {
            if (blg[i][j] != std::numeric_limits<std::uint32_t>::max()) {
                ++(blg[i][j]);
            }
        }
    }
}

void Aoc15::turnLightsOff(BLightsGrid &blg, const Point &from, const Point &to)
{
    for (auto i{from.second}; i <= to.second; ++i) {
        for (auto j{from.first}; j <= to.first; ++j) {
            if(blg[i][j] != 0) {
                --(blg[i][j]);
            }
        }
    }
}

void Aoc15::toggleLights(BLightsGrid &blg, const Point &from, const Point &to)
{
    turnLightsOn(blg, from, to);
    turnLightsOn(blg, from, to);
}

auto Aoc15::totalBrightness(const BLightsGrid &blg) -> std::uint32_t
{
    return std::accumulate(blg.begin(), blg.end(), 0UL, [](const auto &lhs, const auto &rhs) -> std::uint32_t { return lhs + std::accumulate(rhs.begin(), rhs.end(), 0UL); });
}
