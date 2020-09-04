#include <aoc15/d10.h>

auto lookAndSay(const std::string &s) -> std::string
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
