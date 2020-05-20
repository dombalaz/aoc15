#include <aoc15/d04.h>
#include <gtest/gtest.h>

TEST(Day04_Task01_Test, CorrectMiningNumber)
{
    EXPECT_EQ(609043, miningNumber("abcdef", 5));
    EXPECT_EQ(1048970, miningNumber("pqrstuv", 5));
}
