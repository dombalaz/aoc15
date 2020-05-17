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
    EXPECT_EQ(1, areaOfSmallest(1, 10, 1));
    EXPECT_EQ(1, areaOfSmallest(10, 1, 1));

    EXPECT_EQ(10, areaOfSmallest(1, 10, 10));
    EXPECT_EQ(10, areaOfSmallest(10, 1, 10));
    EXPECT_EQ(10, areaOfSmallest(10, 10, 1));
}

TEST(Day02_Task02_Test, RibbonTest)
{
    EXPECT_EQ(34, ribbonForGift(2, 3, 4));
    EXPECT_EQ(14, ribbonForGift(1, 1, 10));
    EXPECT_EQ(122, ribbonForGift(1, 10, 10));
}
