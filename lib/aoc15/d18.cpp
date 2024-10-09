#include <algorithm>
#include <aoc15/d18.h>
#include <numeric>
#include <vector>

namespace Aoc15
{

auto countOn(const std::vector<std::string>& grid) -> int
{
    return std::accumulate(grid.begin(), grid.end(), 0, [](int c, const std::string& s) {
        return c + std::count(s.begin(), s.end(), '#');
    });
}

auto nextState(const std::vector<std::string>& grid) -> std::vector<std::string>
{
    auto r{grid};
    auto size{static_cast<int>(grid.size())};

    for (auto i{0}; i < size; ++i) {
        for (auto j{0}; j < size; ++j) {
            auto neighbourCount{0};
            std::vector<std::pair<int, int>> neighbourIndices = {
                {i - 1, j - 1},
                {i - 1, j},
                {i - 1, j + 1},
                {i, j - 1,},
                {i, j + 1},
                {i + 1, j - 1},
                {i + 1, j},
                {i + 1, j + 1}
            };
            for (const auto& kv : neighbourIndices) {
                if (kv.first < 0 || kv.second < 0 || size <= kv.first || size <= kv.second) {
                    continue;
                }
                if (grid[kv.first][kv.second] == '#') {
                    ++neighbourCount;
                }
            }
            if (grid[i][j] == '#') {
                if (neighbourCount != 2 && neighbourCount != 3) {
                    r[i][j] = '.';
                }
            } else {
                if (neighbourCount == 3) {
                    r[i][j] = '#';
                }
            }
        }
    }
    return r;
}

auto nextState2(const std::vector<std::string>& grid) -> std::vector<std::string>
{
    auto r{nextState(grid)};
    auto last = grid.size() - 1;
    r[0][0] = '#';
    r[0][last] = '#';
    r[last][0] = '#';
    r[last][last] = '#';
    return r;
}

auto solveD18P1(const std::vector<std::string>& in) -> int
{
    auto tmp{in};
    for (auto i{0}; i < 100; ++i) {
        tmp = nextState(tmp);
    }
    return countOn(tmp);
}

auto solveD18P2(const std::vector<std::string>& in) -> int
{
    auto tmp{in};
    auto last = in.size() - 1;
    tmp[0][0] = '#';
    tmp[0][last] = '#';
    tmp[last][0] = '#';
    tmp[last][last] = '#';
    for (auto i{0}; i < 100; ++i) {
        tmp = nextState2(tmp);
    }
    return countOn(tmp);
}

} // namespace Aoc15