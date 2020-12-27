#include <aoc15/d15.h>

#include <iostream>
#include <numeric>
#include <regex>

auto allCombinationsForTop(uint top, uint n) -> std::vector<std::vector<uint>>
{
    if (n == 0) {
        return {};
    }
    if (n == 1) {
        return {{top}};
    }

    std::vector<std::vector<uint>> r;
    for (auto i{0U}; i <= top; ++i) {
        auto tmp = allCombinationsForTop(top - i, n - 1);
        for (auto &p : tmp) {
            p.insert(p.begin(), i);
            r.push_back(p);
        }
    }
    return r;
}

const std::regex regex{"([A-Z][a-z]*): capacity (-?[0-9]+), durability (-?[0-9]+), flavor (-?[0-9]+), texture (-?[0-9]+), calories (-?[0-9]+)"};
constexpr auto regexNameIndex{1U};
constexpr auto regexCapacityIndex{2U};
constexpr auto regexDurabilityIndex{3U};
constexpr auto regexFlavorIndex{4U};
constexpr auto regexTextureIndex{5U};
constexpr auto regexCaloriesIndex{6U};

auto createIngredient(const std::string &s) -> Ingredient
{
    std::smatch match;
    std::regex_match(s, match, regex);
    return {
        match[regexNameIndex],
        {
            std::stoi(match[regexCapacityIndex]),
            std::stoi(match[regexDurabilityIndex]),
            std::stoi(match[regexFlavorIndex]),
            std::stoi(match[regexTextureIndex]),
            std::stoi(match[regexCaloriesIndex])
        }
    };
}

auto createIngredients(const std::vector<std::string> &v) -> std::vector<Ingredient>
{
    std::vector<Ingredient> r;
    r.reserve(v.size());
    std::transform(
        v.begin(),
        v.end(),
        std::back_inserter(r),
        [](const auto &v) { return createIngredient(v); }
    );
    return r;
}

auto highestScoringCookie(const std::vector<Ingredient> &v, uint targetCalories) -> uint
{
    constexpr auto topValue{100U};
    auto c = allCombinationsForTop(topValue, v.size());
    auto max{0U};
    for (const auto &v1 : c) {
        auto tmp{0U};

        auto capacity{0};
        auto durability{0};
        auto flavor{0};
        auto texture{0};
        auto calories{0U};

        for (auto i{0U}; i < v1.size(); ++i) {
            capacity += v1[i] * v[i].second.capacity;
            durability += v1[i] * v[i].second.durability;
            flavor += v1[i] * v[i].second.flavor;
            texture += v1[i] * v[i].second.texture;
            calories += v1[i] * v[i].second.calories;
        }

        if (targetCalories != 0 && calories != targetCalories) {
            continue;
        }

        tmp = capacity <= 0 || durability <= 0 || flavor <= 0 || texture <= 0
            ? 0U
            : capacity * durability * flavor * texture;

        if (tmp > max) {
            max = tmp;
        }
    }
    return max;
}
