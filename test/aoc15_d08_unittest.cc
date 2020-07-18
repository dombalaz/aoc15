#include <aoc15/d08.h>
#include <gtest/gtest.h>

TEST(Day08_Part1_Test, CountCharacters)
{
    EXPECT_EQ(countCharacters(R"("")"), 0);
    EXPECT_EQ(countCharacters(R"("abc")"), 3);
    EXPECT_EQ(countCharacters(R"("aaa\"aaa")"), 7);
    EXPECT_EQ(countCharacters(R"("\x27")"), 1);
}
