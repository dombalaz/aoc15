#include <aoc15/d17.h>
#include <gtest/gtest.h>

TEST(Day17_Part1_Test, combinationsToTopSum)
{
    EXPECT_EQ(Aoc15::combinationsToTopSum({"20", "15", "10", "5", "5"}, 25), 4);
    EXPECT_EQ(Aoc15::combinationsToTopSum({"15", "20", "5", "5", "10"}, 25), 4);
    EXPECT_EQ(Aoc15::combinationsToTopSum({20, 15, 10, 5, 5}, 25, 5), 4);
}

TEST(Day17_Part2_Test, combinationsToTopSumWithRecursionCounter)
{
    EXPECT_EQ(Aoc15::combinationsWithMinToTopSum({"20", "15", "10", "5", "5"}, 25), 3);
    EXPECT_EQ(Aoc15::combinationsWithMinToTopSum({"15", "20", "5", "5", "10"}, 25), 3);
    EXPECT_EQ(Aoc15::combinationsWithMinToTopSum({20, 15, 10, 5, 5}, 25), 3);
}
