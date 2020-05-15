#include <aoc15/d01.h>
#include <gtest/gtest.h>

TEST(Day01_Task01_Test, GetCorrectFloor)
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

TEST(Day01_Task02_Test, GetIndexOnTheFirst)
{
    EXPECT_EQ(1, getIndexOfFirstBasement(")"));
}

TEST(Day01_Task02_Test, GetIndexInTheMiddle)
{
    EXPECT_EQ(3, getIndexOfFirstBasement("())()"));
    EXPECT_EQ(7, getIndexOfFirstBasement("((())))(("));
}

TEST(Day01_Task02_Test, GetIndexOnTheLast)
{
    EXPECT_EQ(5, getIndexOfFirstBasement("()())"));

    EXPECT_EQ(3, getIndexOfFirstBasement("())"));
}

TEST(Day01_Task02_Test, BasementNotReached)
{
    EXPECT_EQ(-1, getIndexOfFirstBasement(""));
    EXPECT_EQ(-1, getIndexOfFirstBasement("("));
    EXPECT_EQ(-1, getIndexOfFirstBasement("()()"));
}
