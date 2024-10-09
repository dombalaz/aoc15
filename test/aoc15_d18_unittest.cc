#include <aoc15/d18.h>
#include <gtest/gtest.h>

TEST(Day18_Part1_Test, state1)
{
    std::vector<std::string> in{
        ".#.#.#",
        "...##.",
        "#....#",
        "..#...",
        "#.#..#",
        "####.."
    };
    ASSERT_EQ(Aoc15::countOn(in), 15);

    std::vector<std::string> s1{
        "..##..",
        "..##.#",
        "...##.",
        "......",
        "#.....",
        "#.##.."
    };
    ASSERT_EQ(Aoc15::countOn(s1), 11);
    in = Aoc15::nextState(in);
    ASSERT_EQ(in, s1);

    std::vector<std::string> s2{
        "..###.",
        "......",
        "..###.",
        "......",
        ".#....",
        ".#...."
    };
    ASSERT_EQ(Aoc15::countOn(s2), 8);
    in = Aoc15::nextState(in);
    ASSERT_EQ(in, s2);

    std::vector<std::string> s3{
        "...#..",
        "......",
        "...#..",
        "..##..",
        "......",
        "......"
    };
    ASSERT_EQ(Aoc15::countOn(s3), 4);
    in = Aoc15::nextState(in);
    ASSERT_EQ(in, s3);

    std::vector<std::string> s4{
        "......",
        "......",
        "..##..",
        "..##..",
        "......",
        "......"
    };
    ASSERT_EQ(Aoc15::countOn(s4), 4);
    in = Aoc15::nextState(in);
    ASSERT_EQ(in, s4);
}

TEST(Day18_Part2_Test, state2)
{
    std::vector<std::string> in{
        "##.#.#",
        "...##.",
        "#....#",
        "..#...",
        "#.#..#",
        "####.#"
    };
    ASSERT_EQ(Aoc15::countOn(in), 17);

    std::vector<std::string> s1{
        "#.##.#",
        "####.#",
        "...##.",
        "......",
        "#...#.",
        "#.####"
    };
    ASSERT_EQ(Aoc15::countOn(s1), 18);
    in = Aoc15::nextState2(in);
    ASSERT_EQ(in, s1);

    std::vector<std::string> s2{
        "#..#.#",
        "#....#",
        ".#.##.",
        "...##.",
        ".#..##",
        "##.###"
    };
    ASSERT_EQ(Aoc15::countOn(s2), 18);
    in = Aoc15::nextState2(in);
    ASSERT_EQ(in, s2);

    std::vector<std::string> s3{
        "#...##",
        "####.#",
        "..##.#",
        "......",
        "##....",
        "####.#"
    };
    ASSERT_EQ(Aoc15::countOn(s3), 18);
    in = Aoc15::nextState2(in);
    ASSERT_EQ(in, s3);

    std::vector<std::string> s4{
        "#.####",
        "#....#",
        "...#..",
        ".##...",
        "#.....",
        "#.#..#"
    };
    ASSERT_EQ(Aoc15::countOn(s4), 14);
    in = Aoc15::nextState2(in);
    ASSERT_EQ(in, s4);

    std::vector<std::string> s5{
        "##.###",
        ".##..#",
        ".##...",
        ".##...",
        "#.#...",
        "##...#"
    };
    ASSERT_EQ(Aoc15::countOn(s5), 17);
    in = Aoc15::nextState2(in);
    ASSERT_EQ(in, s5);
}
