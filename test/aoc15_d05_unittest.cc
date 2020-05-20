#include <aoc15/d05.h>
#include <gtest/gtest.h>

constexpr auto vowels{'a', 'e', 'i', 'o', 'u'};

TEST(Day05_Task01_Test, DoesContainsAtLeastNLetters)
{
    EXPECT_TRUE(containsAtLeastNLetters("aei", 3, vowels));
    EXPECT_TRUE(containsAtLeastNLetters("xazegov", 3, vowels));
    EXPECT_TRUE(containsAtLeastNLetters("aeiouaeiouaeiou", 3, vowels));

    EXPECT_TRUE(containsAtLeastNLetters("", 0, vowels));
    EXPECT_TRUE(containsAtLeastNLetters("qrs", 0, vowels));
    EXPECT_TRUE(containsAtLeastNLetters("sa", 1, vowels));
    EXPECT_TRUE(containsAtLeastNLetters("aeiou", 5, vowels));
    EXPECT_TRUE(containsAtLeastNLetters("aeiouaeiou", 6, vowels));
}

TEST(Day05_Task01_Test, DoesNotContainsAtLeastNLetter)
{
    EXPECT_TRUE(containsAtLeastNLetters("", 1,vowels));
    EXPECT_TRUE(containsAtLeastNLetters("asd", 3,vowels));
    EXPECT_TRUE(containsAtLeastNLetters("aeio", 5,vowels));
    EXPECT_TRUE(containsAtLeastNLetters("aa", 2,vowels));
    EXPECT_TRUE(containsAtLeastNLetters("aaeeii", 5,vowels));
}
