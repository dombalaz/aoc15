#include <aoc15/d15.h>
#include <gtest/gtest.h>

TEST(Day15_Part1_Test, createIngredient)
{
    auto r = Aoc15::createIngredient("Butterscotch: capacity -1, durability -2, flavor 6, texture 3, calories 8");
    EXPECT_EQ(r.first, "Butterscotch");
    auto &s = r.second;
    EXPECT_EQ(s.capacity, -1);
    EXPECT_EQ(s.durability, -2);
    EXPECT_EQ(s.flavor, 6);
    EXPECT_EQ(s.texture, 3);
    EXPECT_EQ(s.calories, 8);
}

TEST(Day15_Part1_Test, createIngredients)
{
    auto v = Aoc15::createIngredients({
        "Butterscotch: capacity -1, durability -2, flavor 6, texture 3, calories 8",
        "Cinnamon: capacity 2, durability 3, flavor -2, texture -1, calories 3"
    });
    EXPECT_EQ(v.size(), 2);
    auto &r1 = v[0];
    auto &r2 = v[1];
    auto &s1 = r1.second;
    auto &s2 = r2.second;

    EXPECT_EQ(r1.first, "Butterscotch");
    EXPECT_EQ(s1.capacity, -1);
    EXPECT_EQ(s1.durability, -2);
    EXPECT_EQ(s1.flavor, 6);
    EXPECT_EQ(s1.texture, 3);
    EXPECT_EQ(s1.calories, 8);

    EXPECT_EQ(r2.first, "Cinnamon");
    EXPECT_EQ(s2.capacity, 2);
    EXPECT_EQ(s2.durability, 3);
    EXPECT_EQ(s2.flavor, -2);
    EXPECT_EQ(s2.texture, -1);
    EXPECT_EQ(s2.calories, 3);
}

TEST(Day15_Part1_Test, highestScoringCookie)
{
    auto v = Aoc15::createIngredients({
        "Butterscotch: capacity -1, durability -2, flavor 6, texture 3, calories 8",
        "Cinnamon: capacity 2, durability 3, flavor -2, texture -1, calories 3"
    });
    EXPECT_EQ(Aoc15::highestScoringCookie(v), 62842880U);
}

TEST(Day15_Part1_Test, highestScoringCookieWithExactCalories)
{
    auto v = Aoc15::createIngredients({
        "Butterscotch: capacity -1, durability -2, flavor 6, texture 3, calories 8",
        "Cinnamon: capacity 2, durability 3, flavor -2, texture -1, calories 3"
    });
    EXPECT_EQ(Aoc15::highestScoringCookie(v, 500), 57600000);
}