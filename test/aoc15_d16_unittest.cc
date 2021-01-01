#include <aoc15/d16.h>
#include <gtest/gtest.h>

TEST(Day16_Part1_Test, auntNumber)
{
    MfcsamCompounds compounds{{
        {"children", {1, std::equal_to()}},
        {"cats", {2, std::equal_to()}}}
    };
    std::vector<MfcsamCompounds> in{
        {{{"children", {1, std::equal_to()}}, {"cats", {2, std::equal_to()}}}}
    };

    EXPECT_EQ(auntNumber(compounds, in), 0);

    std::vector<MfcsamCompounds> in2 = {
        {{{"children", {2, std::equal_to()}}, {"cats", {3, std::equal_to()}}}},
        {{{"children", {2, std::equal_to()}}}},
        {{{"cats", {2, std::equal_to()}}}}
    };
    EXPECT_EQ(auntNumber(compounds, in2), 2);
}

TEST(Day16_Part2_Test, auntNumber)
{
    MfcsamCompounds compounds{{
        {"children", {1, std::equal_to()}},
        {"cats", {2, std::greater()}}}
    };
    std::vector<MfcsamCompounds> in2 = {
        {{{"children", {2, std::equal_to()}}, {"cats", {3, std::equal_to()}}}},
        {{{"children", {2, std::equal_to()}}}},
        {{{"cats", {2, std::equal_to()}}}},
        {{{"cats", {1, std::equal_to()}}}}
    };
    EXPECT_EQ(auntNumber(compounds, in2), 3);
}