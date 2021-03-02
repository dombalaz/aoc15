#include <aoc15/d01.h>
#include <gtest/gtest.h>

using namespace Aoc15;

TEST(Day01_Task01_Test, GetCorrectFloor)
{
    EXPECT_EQ(0, solveD1P1("(())"));
    EXPECT_EQ(0, solveD1P1("()()"));
    EXPECT_EQ(3, solveD1P1("((("));
    EXPECT_EQ(3, solveD1P1("(()(()("));
    EXPECT_EQ(3, solveD1P1("))((((("));
    EXPECT_EQ(-1, solveD1P1("())"));
    EXPECT_EQ(-1, solveD1P1("))("));
    EXPECT_EQ(-3, solveD1P1(")))"));
    EXPECT_EQ(-3, solveD1P1(")())())"));
    EXPECT_EQ(0, solveD1P1(""));
}

TEST(Day01_Task02_Test, GetIndexOnTheFirst)
{
    EXPECT_EQ(1, solveD1P2(")"));
}

TEST(Day01_Task02_Test, GetIndexInTheMiddle)
{
    EXPECT_EQ(3, solveD1P2("())()"));
    EXPECT_EQ(7, solveD1P2("((())))(("));
}

TEST(Day01_Task02_Test, GetIndexOnTheLast)
{
    EXPECT_EQ(5, solveD1P2("()())"));

    EXPECT_EQ(3, solveD1P2("())"));
}
