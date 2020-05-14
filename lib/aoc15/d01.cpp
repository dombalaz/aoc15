#include <aoc15/d01.h>

int getFloor(const std::string &in)
{
    int r{0};
    for (const auto &c : in) {
        r += c == '(' ? 1 : -1;
    }
    return r;
}

