#include <aoc15/d10.h>

auto Aoc15::solveD10P1(std::string_view in) -> size_t
{
    constexpr auto fortyTimes {40U};
    std::string s{in};
    for (size_t i = 0; i < fortyTimes; ++i) {
        s = lookAndSay(s);
    }
    return s.size();
}

auto Aoc15::solveD10P2(std::string_view in) -> size_t
{

    constexpr auto fiftyTimes {50U};
    std::string s{in};
    for (size_t i = 0; i < fiftyTimes; ++i) {
        s = lookAndSay(s);
    }
    return s.size();
}

auto Aoc15::lookAndSay(std::string_view s) -> std::string
{
    if (s.empty()) {
        return {};
    }
    std::string res;
    char c{s.at(0)};
    size_t count{1};
    for (size_t i = 1; i < s.size(); ++i) {
        if (c != s.at(i)) {
            res += std::to_string(count);
            res += c;
            c = s.at(i);
            count = 1;
        } else {
            ++count;
        }
    }
    res += std::to_string(count);
    res += c;
    return res;
}
