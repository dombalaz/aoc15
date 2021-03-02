#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace Aoc15
{
struct IngredientProperties
{
    int capacity{};
    int durability{};
    int flavor{};
    int texture{};
    int calories{};
};

using Ingredient = std::pair<std::string, IngredientProperties>;

auto solveD15P1(const std::vector<std::string>& in) -> std::int64_t;

auto solveD15P2(const std::vector<std::string>& in) -> std::int64_t;

auto createIngredient(const std::string &s) -> Ingredient;

auto createIngredients(const std::vector<std::string> &v) -> std::vector<Ingredient>;

auto highestScoringCookie(const std::vector<Ingredient> &v, std::uint32_t targetCalories = 0) -> std::uint32_t;
} // namespace Aoc15