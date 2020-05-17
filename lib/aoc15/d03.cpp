#include <aoc15/d03.h>

#include <utility>
#include <set>
#include <vector>

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

uint visitedHousesBySantaAndRobot(const std::string &in)
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
