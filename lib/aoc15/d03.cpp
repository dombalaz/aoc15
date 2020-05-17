#include <aoc15/d03.h>

#include <utility>
#include <set>

uint visitedHousesBySanta(const std::string &in)
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
