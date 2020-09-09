#include <aoc15/d08.h>

auto countCharacters(const std::string &s) -> size_t
{
    // I expect first and last chars to be '"' so not checking this.
    auto r = 0U;
    auto top = s.size() - 1;
    for (auto i = 1U; i < top; ++i) {
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

auto countEncodedChars(const std::string &s) -> size_t
{
    auto top = s.size() - 1;
    auto countSpecial{0U};
    for (auto i = 1U; i < top; ++i) {
        if (s.at(i) == '\\') {
            if (s.at(i + 1) == '\\' || s.at(i + 1) == '\"') {
                ++i;
                countSpecial += 2;
            } else if (s.at(i + 1) == 'x') {
                i += 3;
                ++countSpecial;
            }
        }
    }
    return s.size() + countSpecial + 4;
}
