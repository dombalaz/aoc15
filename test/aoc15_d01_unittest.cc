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
