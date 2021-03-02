#include <aoc15/d03.h>

#include <set>
#include <utility>
#include <vector>

auto Aoc15::solveD3P1(std::string_view in) -> std::uint32_t
{
    std::set<std::pair<int, int>> grid{{0, 0}};
    int x{0};
    int y{0};
    for (const auto &c : in) {
        switch (c) {
        case '^':
            ++y;
            break;
        case '>':
            ++x;
            break;
        case 'v':
            --y;
            break;
        case '<':
            --x;
            break;
        }
        grid.insert({x, y});
    }
    return grid.size();
}

auto Aoc15::solveD3P2(std::string_view in) -> std::uint32_t
{
    std::set<std::pair<int, int>> grid{{0, 0}};
    std::vector<std::pair<int, int>> cs{{0, 0}, {0, 0}};
    int santasMove{0};
    for(const auto &c : in) {
        switch(c) {
        case '^':
            ++cs[santasMove].second;
            break;
        case '>':
            ++cs[santasMove].first;
            break;
        case 'v':
            --cs[santasMove].second;
            break;
        case '<':
            --cs[santasMove].first;
            break;
        }
        grid.insert({cs.at(santasMove).first, cs.at(santasMove).second});
        santasMove = santasMove == 0 ? 1 : 0;
    }
    return grid.size();
}
