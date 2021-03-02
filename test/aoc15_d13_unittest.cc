#include <aoc15/d13.h>
#include <gtest/gtest.h>

const std::vector<std::string> vec
{
    "Alice would gain 54 happiness units by sitting next to Bob.",
    "Alice would lose 79 happiness units by sitting next to Carol.",
    "Alice would lose 2 happiness units by sitting next to David.",
    "Bob would gain 83 happiness units by sitting next to Alice.",
    "Bob would lose 7 happiness units by sitting next to Carol.",
    "Bob would lose 63 happiness units by sitting next to David.",
    "Carol would lose 62 happiness units by sitting next to Alice.",
    "Carol would gain 60 happiness units by sitting next to Bob.",
    "Carol would gain 55 happiness units by sitting next to David.",
    "David would gain 46 happiness units by sitting next to Alice.",
    "David would lose 7 happiness units by sitting next to Bob.",
    "David would gain 41 happiness units by sitting next to Carol."
};

TEST(Day13_Part1_Test, createPeopleHappinessMap)
{
    auto res = Aoc15::createPeopleHappinessMap(vec);
    ASSERT_EQ(res.count({"Alice", "Bob"}), 1);
    ASSERT_EQ(res.count({"Bob", "Alice"}), 1);
    ASSERT_EQ(res.count({"Alice", "Carol"}), 1);
    ASSERT_EQ(res.count({"Carol", "Alice"}), 1);

    EXPECT_EQ(res.at({"Alice", "Bob"}), 54);
    EXPECT_EQ(res.at({"Bob", "Alice"}), 83);
    EXPECT_EQ(res.at({"Alice", "Carol"}), -79);
    EXPECT_EQ(res.at({"Bob", "Carol"}), -7);
}

TEST(Day13_Part1_Test, optimalHappiness)
{
    auto res = Aoc15::createPeopleHappinessMap(vec);
    EXPECT_EQ(optimalHappiness(res), 330);
}
