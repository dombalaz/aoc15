#include <aoc15/d01.h>

#include <numeric>

auto getFloor(const std::string &in) -> int
{
    return std::accumulate(in.begin(), in.end(), 0, [](const auto &a, const auto &b) { return a + (b == '(' ? 1 : -1); });
}

auto getIndexOfFirstBasement(const std::string &in) -> int
{
    int r{0};
    for (size_t i = 0; i < in.size(); ++i) {
        r += in.at(i) == '(' ? 1 : -1;
        if (r < 0) {
            return static_cast<int>(i) + 1;
        }
    }
    return -1;
}

