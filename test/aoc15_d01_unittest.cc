#include <aoc15/d01.h>
#include <gtest/gtest.h>

TEST(Day01Test, GetCorrectFloor)
{
    EXPECT_EQ(0, getFloor("(())"));
    EXPECT_EQ(0, getFloor("()()"));
    EXPECT_EQ(3, getFloor("((("));
    EXPECT_EQ(3, getFloor("(()(()("));
    EXPECT_EQ(3, getFloor("))((((("));
    EXPECT_EQ(-1, getFloor("())"));
    EXPECT_EQ(-1, getFloor("))("));
    EXPECT_EQ(-3, getFloor(")))"));
    EXPECT_EQ(-3, getFloor(")())())"));

    EXPECT_EQ(0, getFloor(""));
}

TEST(DAY01TEST, GetIndexOnTheFirst)
{
    EXPECT_EQ(1, getIndexOfFirstBasement(")"));
}

TEST(DAY01TEST, GetIndexInTheMiddle)
{
    EXPECT_EQ(3, getIndexOfFirstBasement("())()"));
    EXPECT_EQ(7, getIndexOfFirstBasement("((())))(("));
}

TEST(DAY01TEST, GetIndexOnTheLast)
{
    EXPECT_EQ(5, getIndexOfFirstBasement("()())"));

    EXPECT_EQ(3, getIndexOfFirstBasement("())"));
}

TEST(DAY01TEST, BasementNotReached)
{
    EXPECT_EQ(-1, getIndexOfFirstBasement(""));
    EXPECT_EQ(-1, getIndexOfFirstBasement("("));
    EXPECT_EQ(-1, getIndexOfFirstBasement("()()"));
}
