#include <aoc15/d04.h>
#include <gtest/gtest.h>

TEST(Day04_Task01_Test, CorrectMiningNumber)
{
    EXPECT_EQ(609043, Aoc15::solveD4P1("abcdef"));
    EXPECT_EQ(1048970, Aoc15::solveD4P1("pqrstuv"));
}
