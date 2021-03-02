#include <aoc15/d09.h>
#include <gtest/gtest.h>

TEST(Day09_Part1_Test, ShortestDistance)
{
    std::vector<std::string> v{
        "London to Dublin = 464",
        "London to Belfast = 518",
        "Dublin to Belfast = 141"
    };
    EXPECT_EQ(Aoc15::solveD9P1(v), 605);
}

TEST(Day09_Part2_Test, LongestDistance)
{
    std::vector<std::string> v{
        "London to Dublin = 464",
        "London to Belfast = 518",
        "Dublin to Belfast = 141"
    };
    EXPECT_EQ(Aoc15::solveD9P2(v), 982);
}
