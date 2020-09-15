#include <aoc15/d11.h>
#include <gtest/gtest.h>

TEST(Day11_Part1_Test, containsIncreasingStraightOf3Letters)
{
    EXPECT_TRUE(containsIncreasingStraightOf3Letters("abc"));
    EXPECT_TRUE(containsIncreasingStraightOf3Letters("bcd"));
    EXPECT_TRUE(containsIncreasingStraightOf3Letters("cde"));
    EXPECT_TRUE(containsIncreasingStraightOf3Letters("xyz"));

    EXPECT_FALSE(containsIncreasingStraightOf3Letters("abd"));

    EXPECT_TRUE(containsIncreasingStraightOf3Letters("hijklmmn"));
    EXPECT_FALSE(containsIncreasingStraightOf3Letters("abbceffg"));
    EXPECT_FALSE(containsIncreasingStraightOf3Letters("abbcegjk"));
}

TEST(Day11_Part1_Test, doesntContainsLetters)
{
    EXPECT_FALSE(doesntContainsLetters("i"));
    EXPECT_FALSE(doesntContainsLetters("l"));
    EXPECT_FALSE(doesntContainsLetters("o"));

    EXPECT_FALSE(doesntContainsLetters("hijklmmn"));
    EXPECT_TRUE(doesntContainsLetters("abbceffg"));
    EXPECT_TRUE(doesntContainsLetters("abbcegjk"));
}

TEST(Day11_Part1_Test, containsLetterPairs)
{
    EXPECT_TRUE(containsLetterPairs("aabb"));
    EXPECT_FALSE(containsLetterPairs("aaa"));

    EXPECT_FALSE(containsLetterPairs("hijklmmn"));
    EXPECT_TRUE(containsLetterPairs("abbceffg"));
    EXPECT_FALSE(containsLetterPairs("abbcegjk"));
}

TEST(Day11_Part1_Test, nextPass)
{
    EXPECT_EQ(nextPass("xx"), "xy");
    EXPECT_EQ(nextPass("xy"), "xz");
    EXPECT_EQ(nextPass("xz"), "ya");
    EXPECT_EQ(nextPass("ya"), "yb");
}

TEST(Day11_Part1_Test, nextValidPass)
{
    EXPECT_EQ(nextValidPass("abcdefgh"), "abcdffaa");
    EXPECT_EQ(nextValidPass("ghijklmn"), "ghjaabcc");
}
