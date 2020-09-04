#include <aoc15/d10.h>
#include <gtest/gtest.h>

TEST(Day10_Part1_Test, LookAndSay)
{
    EXPECT_EQ(lookAndSay(""), "");
    EXPECT_EQ(lookAndSay("1"), "11");
    EXPECT_EQ(lookAndSay("11"), "21");
    EXPECT_EQ(lookAndSay("21"), "1211");
    EXPECT_EQ(lookAndSay("1211"), "111221");
    EXPECT_EQ(lookAndSay("111221"), "312211");
}
