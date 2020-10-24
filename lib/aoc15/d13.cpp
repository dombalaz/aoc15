#include <aoc15/d13.h>

#include <regex>
#include <set>

auto KeyHash::operator()(const Key &k) const -> std::size_t
{
    return std::hash<std::string>{}(k.first) ^ (std::hash<std::string>{}(k.second) << 1);
}

auto createPeopleHappinessMap(const std::vector<std::string> &v) -> PeopleHappinessMap
{
    const std::regex regex{"([a-zA-Z]+) would (gain|lose) ([0-9]+) happiness units by sitting next to ([a-zA-z]+)\\."};
    std::smatch match;
    PeopleHappinessMap r;
    for (const auto &s: v) {
        std::regex_match(s, match, regex);
        auto gl = match[2] == "gain" ? 1 : -1;
        r.emplace(Key{match[1], match[4]}, gl * std::stol(match[3]));
    }

    return r;
}

auto optimalHappiness(const PeopleHappinessMap &m) -> std::int64_t
{
    std::set<std::string> s;
    for (const auto &kv : m) {
        s.insert(kv.first.first);
    }

    std::vector<std::string> v(s.begin(), s.end());
    auto r{0};
    do {
        auto t{0};
        for (auto i = 1U; i < v.size(); ++i) {
            t += m.at({v.at(i - 1), v.at(i)});
            t += m.at({v.at(i), v.at(i - 1)});
        }
        if (v.size() > 2) {
            t += m.at({v.front(), v.back()});
            t += m.at({v.back(), v.front()});
        }
        if (r < t) {
            r = t;
        }
    } while (std::next_permutation(v.begin(), v.end()));

    return r;
}
