#include <aoc15/d02.h>
#include <gtest/gtest.h>

TEST(Day02_Task01_Test, PaperForGift)
{
    EXPECT_EQ(58, paperForGift(2, 3, 4));
    EXPECT_EQ(43, paperForGift(1, 1, 10));

    EXPECT_EQ(58, paperForGift(4, 2, 3));
    EXPECT_EQ(58, paperForGift(3, 4, 2));
    EXPECT_EQ(28, paperForGift(2, 2, 2));
}

TEST(Day02_Task01_Test, AreaOfSmallest)
{
    EXPECT_EQ(6, areaOfSmallest(2, 3, 4));
    EXPECT_EQ(1, areaOfSmallest(1, 1, 10));

    EXPECT_EQ(6, areaOfSmallest(4, 2, 3));
    EXPECT_EQ(6, areaOfSmallest(3, 4, 2));
    EXPECT_EQ(4, areaOfSmallest(2, 2, 2));
}

