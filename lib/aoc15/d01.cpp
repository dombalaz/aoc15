#include <aoc15/d01.h>

#include <cstdint>
#include <string>
#include <numeric>
#include <stdexcept>

auto Aoc15::solveD1P1(std::string_view in) -> int
{
    return std::accumulate(in.begin(), in.end(), 0, [](const auto &a, const auto &b) { return a + (b == '(' ? 1 : -1); });
}

auto Aoc15::solveD1P2(std::string_view in) -> std::uint32_t
{
    auto r{0};
    for (auto i{0U}; i < in.size(); ++i) {
        r += in[i] == '(' ? 1 : -1;
        if (r < 0) {
            return i + 1;
        }
    }

    throw std::logic_error("could not find negative floor");
}
