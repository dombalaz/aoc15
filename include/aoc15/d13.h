#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using Key = std::pair<std::string, std::string>;

struct KeyHash
{
    auto operator()(const Key &k) const -> std::size_t;
};

using PeopleHappinessMap = std::unordered_map<Key, std::int64_t, KeyHash>;

auto createPeopleHappinessMap(const std::vector<std::string> &v) -> PeopleHappinessMap;

auto optimalHappiness(const PeopleHappinessMap &m) -> std::int64_t;
