#include <aoc15/d03.h>
#include <gtest/gtest.h>

TEST(Day03_Task01_Test, VisitedHousesBySanta)
{
    EXPECT_EQ(2, visitedHousesBySanta(">"));
    EXPECT_EQ(4, visitedHousesBySanta("^>v<"));
    EXPECT_EQ(2, visitedHousesBySanta("^v^v^v^v^v"));

    EXPECT_EQ(1, visitedHousesBySanta(""));
}

TEST(Day03_Task02_Test, VisitedHousesBySantaAndRobot)
{
    EXPECT_EQ(3, visitedHousesBySantaAndRobot("^v"));
    EXPECT_EQ(3, visitedHousesBySantaAndRobot("^>v<"));
    EXPECT_EQ(11, visitedHousesBySantaAndRobot("^v^v^v^v^v"));

    EXPECT_EQ(1, visitedHousesBySantaAndRobot(""));
}
