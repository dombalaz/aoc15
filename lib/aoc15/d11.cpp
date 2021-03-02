#include <aoc15/d11.h>

#include <algorithm>
#include <string>

auto Aoc15::solveD11P1(std::string_view in) -> std::string
{
    return nextValidPass(in);
}

auto Aoc15::solveD11P2(std::string_view in) -> std::string
{
    return nextValidPass(nextValidPass(in));
}

auto Aoc15::containsIncreasingStraightOf3Letters(std::string_view in) -> bool
{
    for (auto i = 2U; i < in.size(); ++i) {
        if (in[i - 2] + 1 == in[i - 1] && in[i - 1] + 1 == in[i]) {
            return true;
        }
    }
    return false;
}

auto Aoc15::doesntContainsLetters(std::string_view in) -> bool
{
    return !std::any_of(
        in.begin(),
        in.end(),
        [l = {'i', 'o', 'l'}](const auto &c) {
            return  std::find(l.begin(), l.end(), c) != l.end();
        }
    );
}

auto Aoc15::containsLetterPairs(std::string_view in) -> bool
{
    auto c = 0U;
    for (auto i = 1U; i < in.size(); ++i) {
        if (in[i - 1] == in[i]) {
            ++c;
            ++i;
        }
    }
    return c == 2;
}

auto Aoc15::nextPass(std::string_view in) -> std::string
{
    std::string r{in};
    for (auto it = r.rbegin(); it != r.rend(); ++it) {
        if (*it == 'z') {
            *it = 'a';
        } else {
            ++*it;
            break;
        }
    }
    return r;
}

auto Aoc15::nextValidPass(std::string_view in) -> std::string
{
    std::string r{in};
    do {
        r = nextPass(r);
    } while (!(containsIncreasingStraightOf3Letters(r) && doesntContainsLetters(r) && containsLetterPairs(r)));
    return r;
}
