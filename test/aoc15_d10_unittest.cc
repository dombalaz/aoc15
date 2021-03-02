#include <aoc15/d10.h>
#include <gtest/gtest.h>

TEST(Day10_Part1_Test, LookAndSay)
{
    EXPECT_EQ(Aoc15::lookAndSay(""), "");
    EXPECT_EQ(Aoc15::lookAndSay("1"), "11");
    EXPECT_EQ(Aoc15::lookAndSay("11"), "21");
    EXPECT_EQ(Aoc15::lookAndSay("21"), "1211");
    EXPECT_EQ(Aoc15::lookAndSay("1211"), "111221");
    EXPECT_EQ(Aoc15::lookAndSay("111221"), "312211");
}
