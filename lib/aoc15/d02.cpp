#include <aoc15/d02.h>

#include <algorithm>
#include <regex>

auto Aoc15::solveD2P1(const std::vector<std::string> &in) -> std::uint32_t
{
    return solveD2(in, paperForGift);
}

auto Aoc15::solveD2P2(const std::vector<std::string> &in) -> std::uint32_t
{
    return solveD2(in, ribbonForGift);
}

auto Aoc15::solveD2(const std::vector<std::string> &in, std::function<std::uint32_t(std::uint32_t, std::uint32_t, std::uint32_t)> fun) -> std::uint32_t
{
    auto r{0U};
    std::smatch match;
    const std::regex regexD2{"([0-9]+)x([0-9]+)x([0-9]+)"};
    for (const auto &s : in) {
        if (!std::regex_match(s, match, regexD2)) {
            throw std::invalid_argument("Input contains invalid line: " + s);
        }
        auto x = std::stoul(match[1]);
        auto y = std::stoul(match[2]);
        auto z = std::stoul(match[3]);
        r += fun(x, y, z);
    }
    return r;
}

auto Aoc15::paperForGift(std::uint32_t x, std::uint32_t y, std::uint32_t z) -> std::uint32_t
{
    return 2 * (x * y + x * z + y * z) + std::min({x * y, x * z, y * z});
}

auto Aoc15::ribbonForGift(std::uint32_t x, std::uint32_t y, std::uint32_t z) -> std::uint32_t
{
    return 2 * (x + y + z - std::max({x, y, z})) + x * y * z;
}
