#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace Aoc15
{
using Key = std::pair<std::string, std::string>;

struct KeyHash
{
    auto operator()(const Key &k) const -> std::size_t;
};

using PeopleHappinessMap = std::unordered_map<Key, std::int64_t, KeyHash>;

auto solveD13P1(const std::vector<std::string>& in) -> std::int64_t;

auto solveD13P2(const std::vector<std::string>& in) -> std::int64_t;

auto createPeopleHappinessMap(const std::vector<std::string> &v) -> PeopleHappinessMap;

auto optimalHappiness(const PeopleHappinessMap &m) -> std::int64_t;
}

