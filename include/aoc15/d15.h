#pragma once

#include <string>
#include <vector>

using uint = std::uint32_t;

struct IngredientProperties
{
    int capacity{};
    int durability{};
    int flavor{};
    int texture{};
    int calories{};
};

using Ingredient = std::pair<std::string, IngredientProperties>;

auto createIngredient(const std::string &s) -> Ingredient;

auto createIngredients(const std::vector<std::string> &v) -> std::vector<Ingredient>;

auto highestScoringCookie(const std::vector<Ingredient> &v, uint targetCalories = 0) -> uint;
