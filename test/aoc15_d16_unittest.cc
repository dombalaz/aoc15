#include <aoc15/d16.h>
#include <gtest/gtest.h>

TEST(Day16_Part1_Test, auntNumber)
{
    Aoc15::MfcsamCompounds compounds{{
        {"children", {1, std::equal_to()}},
        {"cats", {2, std::equal_to()}}}
    };
    std::vector<Aoc15::MfcsamCompounds> in{
        {{{"children", {1, std::equal_to()}}, {"cats", {2, std::equal_to()}}}}
    };

    EXPECT_EQ(Aoc15::auntNumber(compounds, in), 0);

    std::vector<Aoc15::MfcsamCompounds> in2 = {
        {{{"children", {2, std::equal_to()}}, {"cats", {3, std::equal_to()}}}},
        {{{"children", {2, std::equal_to()}}}},
        {{{"cats", {2, std::equal_to()}}}}
    };
    EXPECT_EQ(Aoc15::auntNumber(compounds, in2), 2);
}

TEST(Day16_Part2_Test, auntNumber)
{
    Aoc15::MfcsamCompounds compounds{{
        {"children", {1, std::equal_to()}},
        {"cats", {2, std::greater()}}}
    };
    std::vector<Aoc15::MfcsamCompounds> in2 = {
        {{{"children", {2, std::equal_to()}}, {"cats", {3, std::equal_to()}}}},
        {{{"children", {2, std::equal_to()}}}},
        {{{"cats", {2, std::equal_to()}}}},
        {{{"cats", {1, std::equal_to()}}}}
    };
    EXPECT_EQ(Aoc15::auntNumber(compounds, in2), 3);
}