#include <aoc15/d11.h>

#include <algorithm>

auto containsIncreasingStraightOf3Letters(const std::string &in) -> bool
{
    for (auto i = 2U; i < in.size(); ++i) {
        if (in[i - 2] + 1 == in[i - 1] && in[i - 1] + 1 == in[i]) {
            return true;
        }
    }
    return false;
}

auto doesntContainsLetters(const std::string &in) -> bool
{
    return !std::any_of(
        in.begin(),
        in.end(),
        [l = {'i', 'o', 'l'}](const auto &c) {
            return  std::find(l.begin(), l.end(), c) != l.end();
        }
    );
}

auto containsLetterPairs(const std::string &in) -> bool
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

auto nextPass(const std::string &in) -> std::string
{
    auto r = in;
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

auto nextValidPass(const std::string &in) -> std::string
{
    auto r = in;
    do {
        r = nextPass(r);
    } while (!(containsIncreasingStraightOf3Letters(r) && doesntContainsLetters(r) && containsLetterPairs(r)));
    return r;
}
