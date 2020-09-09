#include <aoc15/d09.h>

#include <iostream>
#include <regex>
#include <set>

const std::regex regex{"([a-zA-Z]+) to ([a-zA-Z]+) = ([0-9]+)"};

std::map<std::pair<std::string, std::string>, size_t> distances;

auto shortestDistance(const std::vector<std::string> &v) -> size_t
{
    std::set<std::string> set;
    std::smatch match;
    for (const auto &s : v) {
        std::regex_match(s, match, regex);
        set.insert(match[1]);
        set.insert(match[2]);
        distances.insert({{match[1], match[2]}, std::stoul(match[3])});
        distances.insert({{match[2], match[1]}, std::stoul(match[3])});
    }
    std::vector<std::string> perms(set.begin(), set.end());
    auto res = std::numeric_limits<size_t>::max();
    std::sort(perms.begin(), perms.end());
    do {
        auto r{0U};
        for (auto i = 0U; i < perms.size() - 1; ++i) {
            r += distances[{perms.at(i), perms.at(i + 1)}];
        }
        if (r < res) {
            res = r;
        }
    } while (std::next_permutation(perms.begin(), perms.end()));

    return res;
}

auto longestDistance(const std::vector<std::string> &v) -> size_t
{
    std::set<std::string> set;
    std::smatch match;
    for (const auto &s : v) {
        std::regex_match(s, match, regex);
        set.insert(match[1]);
        set.insert(match[2]);
        distances.insert({{match[1], match[2]}, std::stoul(match[3])});
        distances.insert({{match[2], match[1]}, std::stoul(match[3])});
    }
    std::vector<std::string> perms(set.begin(), set.end());
    auto res = 0U;
    std::sort(perms.begin(), perms.end());
    do {
        auto r{0U};
        for (auto i = 0U; i < perms.size() - 1; ++i) {
            r += distances[{perms.at(i), perms.at(i + 1)}];
        }
        if (r > res) {
            res = r;
        }
    } while (std::next_permutation(perms.begin(), perms.end()));

    return res;
}
