#include <aoc15/d05.h>
#include <gtest/gtest.h>

TEST(Day05_Task01_Test, ContainsAtLeast3Vowels)
{
    EXPECT_TRUE(Aoc15::containsAtLeast3Vowels("aei"));
    EXPECT_TRUE(Aoc15::containsAtLeast3Vowels("aaa"));
    EXPECT_TRUE(Aoc15::containsAtLeast3Vowels("xazegov"));
    EXPECT_TRUE(Aoc15::containsAtLeast3Vowels("aeiouaeiouaeiou"));

    EXPECT_FALSE(Aoc15::containsAtLeast3Vowels(""));
    EXPECT_FALSE(Aoc15::containsAtLeast3Vowels("x"));
    EXPECT_FALSE(Aoc15::containsAtLeast3Vowels("aa"));
    EXPECT_FALSE(Aoc15::containsAtLeast3Vowels("xxaexx"));
}

TEST(Day05_Task01_Test, ContainsOneLetterTwiceInRow)
{
    EXPECT_TRUE(Aoc15::containsOneLetterTwiceInRow("xx"));
    EXPECT_TRUE(Aoc15::containsOneLetterTwiceInRow("abcdde"));
    EXPECT_TRUE(Aoc15::containsOneLetterTwiceInRow("aabbccdd"));

    EXPECT_FALSE(Aoc15::containsOneLetterTwiceInRow(""));
    EXPECT_FALSE(Aoc15::containsOneLetterTwiceInRow("x"));
    EXPECT_FALSE(Aoc15::containsOneLetterTwiceInRow("abcde"));
}

TEST(Day05_Task01_Test, DoesntContainsTheStrings)
{
    EXPECT_TRUE(Aoc15::doesntContainsTheStrings(""));
    EXPECT_TRUE(Aoc15::doesntContainsTheStrings("ace"));

    EXPECT_FALSE(Aoc15::doesntContainsTheStrings("ab"));
    EXPECT_FALSE(Aoc15::doesntContainsTheStrings("cd"));
    EXPECT_FALSE(Aoc15::doesntContainsTheStrings("pq"));
    EXPECT_FALSE(Aoc15::doesntContainsTheStrings("xy"));
    EXPECT_FALSE(Aoc15::doesntContainsTheStrings("xxxxxabxxxx"));
}

TEST(Dayo05_Task01_Test, IsNice)
{
    EXPECT_TRUE(Aoc15::isNice("ugknbfddgicrmopn"));
    EXPECT_TRUE(Aoc15::isNice("aaa"));

    EXPECT_FALSE(Aoc15::isNice("jchzalrnumimnmhp"));
    EXPECT_FALSE(Aoc15::isNice("haegwjzuvuyypxyu"));
    EXPECT_FALSE(Aoc15::isNice("dvszwmarrgswjxmb"));
}

TEST(Day05_Task02_Test, twoPairsOfTwoLetters)
{
    EXPECT_TRUE(Aoc15::twoPairsOfTwoLetters("xyxy"));
    EXPECT_TRUE(Aoc15::twoPairsOfTwoLetters("aabcdefgaa"));
    EXPECT_TRUE(Aoc15::twoPairsOfTwoLetters("qjhvhtzxzqqjkmpb"));
    EXPECT_TRUE(Aoc15::twoPairsOfTwoLetters("uurcxstgmygtbstg"));

    EXPECT_FALSE(Aoc15::twoPairsOfTwoLetters(""));
    EXPECT_FALSE(Aoc15::twoPairsOfTwoLetters("aaa"));
    EXPECT_FALSE(Aoc15::twoPairsOfTwoLetters("abcdefgh"));
    EXPECT_FALSE(Aoc15::twoPairsOfTwoLetters("ieodomkazucvgmuy"));
}

TEST(Day05_Task02_Test, repeatedLetterWithLetterBetween)
{
    EXPECT_TRUE(Aoc15::repeatedLetterWithLetterBetween("xyx"));
    EXPECT_TRUE(Aoc15::repeatedLetterWithLetterBetween("abcdefeghi"));
    EXPECT_TRUE(Aoc15::repeatedLetterWithLetterBetween("aaa"));

    EXPECT_FALSE(Aoc15::repeatedLetterWithLetterBetween(""));
    EXPECT_FALSE(Aoc15::repeatedLetterWithLetterBetween("uurcxstgmygtbstg"));
}

TEST(Day05_Task02_Test, isNice2)
{
    EXPECT_TRUE(Aoc15::isNice2("qjhvhtzxzqqjkmpb"));
    EXPECT_TRUE(Aoc15::isNice2("xxyxx"));

    EXPECT_FALSE(Aoc15::isNice2("uurcxstgmygtbstg"));
    EXPECT_FALSE(Aoc15::isNice2("ieodomkazucvgmuy"));
}
