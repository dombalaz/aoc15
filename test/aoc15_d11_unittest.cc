#include <aoc15/d11.h>
#include <gtest/gtest.h>

TEST(Day11_Part1_Test, containsIncreasingStraightOf3Letters)
{
    EXPECT_TRUE(Aoc15::containsIncreasingStraightOf3Letters("abc"));
    EXPECT_TRUE(Aoc15::containsIncreasingStraightOf3Letters("bcd"));
    EXPECT_TRUE(Aoc15::containsIncreasingStraightOf3Letters("cde"));
    EXPECT_TRUE(Aoc15::containsIncreasingStraightOf3Letters("xyz"));

    EXPECT_FALSE(Aoc15::containsIncreasingStraightOf3Letters("abd"));

    EXPECT_TRUE(Aoc15::containsIncreasingStraightOf3Letters("hijklmmn"));
    EXPECT_FALSE(Aoc15::containsIncreasingStraightOf3Letters("abbceffg"));
    EXPECT_FALSE(Aoc15::containsIncreasingStraightOf3Letters("abbcegjk"));
}

TEST(Day11_Part1_Test, doesntContainsLetters)
{
    EXPECT_FALSE(Aoc15::doesntContainsLetters("i"));
    EXPECT_FALSE(Aoc15::doesntContainsLetters("l"));
    EXPECT_FALSE(Aoc15::doesntContainsLetters("o"));

    EXPECT_FALSE(Aoc15::doesntContainsLetters("hijklmmn"));
    EXPECT_TRUE(Aoc15::doesntContainsLetters("abbceffg"));
    EXPECT_TRUE(Aoc15::doesntContainsLetters("abbcegjk"));
}

TEST(Day11_Part1_Test, containsLetterPairs)
{
    EXPECT_TRUE(Aoc15::containsLetterPairs("aabb"));
    EXPECT_FALSE(Aoc15::containsLetterPairs("aaa"));

    EXPECT_FALSE(Aoc15::containsLetterPairs("hijklmmn"));
    EXPECT_TRUE(Aoc15::containsLetterPairs("abbceffg"));
    EXPECT_FALSE(Aoc15::containsLetterPairs("abbcegjk"));
}

TEST(Day11_Part1_Test, nextPass)
{
    EXPECT_EQ(Aoc15::nextPass("xx"), "xy");
    EXPECT_EQ(Aoc15::nextPass("xy"), "xz");
    EXPECT_EQ(Aoc15::nextPass("xz"), "ya");
    EXPECT_EQ(Aoc15::nextPass("ya"), "yb");
}

TEST(Day11_Part1_Test, nextValidPass)
{
    EXPECT_EQ(Aoc15::nextValidPass("abcdefgh"), "abcdffaa");
    EXPECT_EQ(Aoc15::nextValidPass("ghijklmn"), "ghjaabcc");
}
