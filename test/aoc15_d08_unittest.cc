#include <aoc15/d08.h>
#include <gtest/gtest.h>

TEST(Day08_Part1_Test, CountCharacters)
{
    EXPECT_EQ(Aoc15::countCharacters(R"("")"), 0);
    EXPECT_EQ(Aoc15::countCharacters(R"("abc")"), 3);
    EXPECT_EQ(Aoc15::countCharacters(R"("aaa\"aaa")"), 7);
    EXPECT_EQ(Aoc15::countCharacters(R"("\x27")"), 1);
}

TEST(Day08_Part2_Test, CountEncodedChars)
{
    EXPECT_EQ(Aoc15::countEncodedChars(R"("")"), 6);
    EXPECT_EQ(Aoc15::countEncodedChars(R"("abc")"), 9);
    EXPECT_EQ(Aoc15::countEncodedChars(R"("aaa\"aaa")"), 16);
    EXPECT_EQ(Aoc15::countEncodedChars(R"("\x27")"), 11);

    EXPECT_EQ(Aoc15::countEncodedChars(R"("\\")"), 10);
}
