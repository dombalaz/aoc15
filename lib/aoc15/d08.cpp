#include <aoc15/d08.h>

size_t countCharacters(const std::string &s)
{
    // I expect first and last chars to be '"' so not checking this.
    auto r = 0u;
    auto top = s.size() - 1;
    for (auto i = 1u; i < top; ++i) {
        if (s.at(i) == '\\') {
            if (s.at(i + 1) == '\\' || s.at(i + 1) == '\"') {
                ++i;
            } else if (s.at(i + 1) == 'x') {
                i += 3;
            }
        }
        ++r;
    }
    return r;
}
