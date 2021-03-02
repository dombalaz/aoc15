#include <aoc15/d02.h>
#include <gtest/gtest.h>

TEST(Day02_Task01_Test, PaperForGift)
{
    EXPECT_EQ(58, Aoc15::paperForGift(2, 3, 4));
    EXPECT_EQ(43, Aoc15::paperForGift(1, 1, 10));

    EXPECT_EQ(58, Aoc15::paperForGift(4, 2, 3));
    EXPECT_EQ(58, Aoc15::paperForGift(3, 4, 2));
    EXPECT_EQ(28, Aoc15::paperForGift(2, 2, 2));
}

TEST(Day02_Task02_Test, RibbonTest)
{
    EXPECT_EQ(34, Aoc15::ribbonForGift(2, 3, 4));
    EXPECT_EQ(14, Aoc15::ribbonForGift(1, 1, 10));
    EXPECT_EQ(122, Aoc15::ribbonForGift(1, 10, 10));
}
