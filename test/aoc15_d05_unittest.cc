#include <aoc15/d05.h>
#include <gtest/gtest.h>

TEST(Day05_Task01_Test, ContainsAtLeast3Vowels)
{
    EXPECT_TRUE(containsAtLeast3Vowels("aei"));
    EXPECT_TRUE(containsAtLeast3Vowels("aaa"));
    EXPECT_TRUE(containsAtLeast3Vowels("xazegov"));
    EXPECT_TRUE(containsAtLeast3Vowels("aeiouaeiouaeiou"));

    EXPECT_FALSE(containsAtLeast3Vowels(""));
    EXPECT_FALSE(containsAtLeast3Vowels("x"));
    EXPECT_FALSE(containsAtLeast3Vowels("aa"));
    EXPECT_FALSE(containsAtLeast3Vowels("xxaexx"));
}

TEST(Day05_Task01_Test, ContainsOneLetterTwiceInRow)
{
    EXPECT_TRUE(containsOneLetterTwiceInRow("xx"));
    EXPECT_TRUE(containsOneLetterTwiceInRow("abcdde"));
    EXPECT_TRUE(containsOneLetterTwiceInRow("aabbccdd"));

    EXPECT_FALSE(containsOneLetterTwiceInRow(""));
    EXPECT_FALSE(containsOneLetterTwiceInRow("x"));
    EXPECT_FALSE(containsOneLetterTwiceInRow("abcde"));
}

TEST(Day05_Task01_Test, DoesntContainsTheStrings)
{
    EXPECT_TRUE(doesntContainsTheStrings(""));
    EXPECT_TRUE(doesntContainsTheStrings("ace"));

    EXPECT_FALSE(doesntContainsTheStrings("ab"));
    EXPECT_FALSE(doesntContainsTheStrings("cd"));
    EXPECT_FALSE(doesntContainsTheStrings("pq"));
    EXPECT_FALSE(doesntContainsTheStrings("xy"));
    EXPECT_FALSE(doesntContainsTheStrings("xxxxxabxxxx"));
}

TEST(Dayo05_Task01_Test, IsNice)
{
    EXPECT_TRUE(isNice("ugknbfddgicrmopn"));
    EXPECT_TRUE(isNice("aaa"));

    EXPECT_FALSE(isNice("jchzalrnumimnmhp"));
    EXPECT_FALSE(isNice("haegwjzuvuyypxyu"));
    EXPECT_FALSE(isNice("dvszwmarrgswjxmb"));
}
