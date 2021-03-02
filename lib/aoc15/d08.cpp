#include <aoc15/d08.h>

auto Aoc15::solveD8P1(const std::vector<std::string> &in) -> size_t
{
    auto r{0U};
    auto total{0U};
    for (const auto &s : in) {
        r += countCharacters(s);
        total += s.size();
    }
    return total - r;
}

auto Aoc15::solveD8P2(const std::vector<std::string> &in) -> size_t
{
    auto r{0U};
    auto total{0U};
    for (const auto &s : in) {
        r += countEncodedChars(s);
        total += s.size();
    }
    return r - total;
}

auto Aoc15::countCharacters(std::string_view s) -> size_t
{
    auto r{0U};
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

auto Aoc15::countEncodedChars(std::string_view s) -> size_t
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
