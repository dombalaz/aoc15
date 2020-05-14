#include <aoc15/d01.h>

int getFloor(const std::string &in)
{
    int r{0};
    for (const auto &c : in) {
        r += c == '(' ? 1 : -1;
    }
    return r;
}

int getIndexOfFirstBasement(const std::string &in)
{
    int r{0};
    for (size_t i = 0; i < in.size(); ++i) {
        r += in.at(i) == '(' ? 1 : -1;
        if (r < 0) {
            return i + 1;
        }
    }
    return -1;
}

