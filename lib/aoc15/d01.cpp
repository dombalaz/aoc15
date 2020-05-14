#include <aoc15/d01.h>

int getFloor(const std::string &x)
{
    int r = 0;
    for (const auto &c : x) {
        r += c == '(' ? 1 : -1;
    }
    return r;
}

