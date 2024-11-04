#include <aoc15/d19.h>
#include <gtest/gtest.h>

TEST(Day19_Part1_Test, countDistinctMolecules)
{
    auto reps = Aoc15::createReplacements({
        "H => HO",
        "H => OH",
        "O => HH"
    });
    ASSERT_EQ(reps.size(), 2);
    ASSERT_EQ(reps["H"].size(), 2);
    ASSERT_EQ(reps["O"].size(), 1);
    ASSERT_EQ(Aoc15::countDistinctMolecules(reps, "HOH"), 4);
    ASSERT_EQ(Aoc15::countDistinctMolecules(reps, "HOHOHO"), 7);
}

TEST(Day19_Part1_Test, countMoleculesMultipleChars)
{
    auto reps = Aoc15::createReplacements({
        "He => HeO",
        "He => OHe",
        "O => HeHe"
    });
    ASSERT_EQ(reps.size(), 2);
    ASSERT_EQ(reps["He"].size(), 2);
    ASSERT_EQ(reps["O"].size(), 1);
    ASSERT_EQ(Aoc15::countDistinctMolecules(reps, "HeOHe"), 4);
    ASSERT_EQ(Aoc15::countDistinctMolecules(reps, "HeOHeOHeO"), 7);
}
TEST(Day19_Part2_Test, state2)
{
    auto reps = Aoc15::createReplacements({
        "e => H",
        "e => O",
        "H => HO",
        "H => OH",
        "O => HH"
    });
    ASSERT_EQ(Aoc15::countMoleculesGenerations(reps, "HOH"), 3);
    ASSERT_EQ(Aoc15::countMoleculesGenerations(reps, "HOHOHO"), 6);
}
