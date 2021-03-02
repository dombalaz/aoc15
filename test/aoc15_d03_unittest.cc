#include <aoc15/d03.h>
#include <gtest/gtest.h>

TEST(Day03_Task01_Test, VisitedHousesBySanta)
{
    EXPECT_EQ(2, Aoc15::solveD3P1(">"));
    EXPECT_EQ(4, Aoc15::solveD3P1("^>v<"));
    EXPECT_EQ(2, Aoc15::solveD3P1("^v^v^v^v^v"));

    EXPECT_EQ(1, Aoc15::solveD3P1(""));
}

TEST(Day03_Task02_Test, VisitedHousesBySantaAndRobot)
{
    EXPECT_EQ(3, Aoc15::solveD3P2("^v"));
    EXPECT_EQ(3, Aoc15::solveD3P2("^>v<"));
    EXPECT_EQ(11, Aoc15::solveD3P2("^v^v^v^v^v"));

    EXPECT_EQ(1, Aoc15::solveD3P2(""));
}
