#include <aoc15/d14.h>
#include <gtest/gtest.h>

const std::vector<std::string> v
{
    "Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds.",
    "Dancer can fly 16 km/s for 11 seconds, but then must rest for 162 seconds."
};

TEST(Day14_Part1_Test, createReindeers)
{
    auto r = Aoc15::createReindeers(v);
    ASSERT_EQ(r.size(), 2);
    Aoc15::Reindeer comet{"Comet", 14, 10, 127};
    Aoc15::Reindeer dancer{"Dancer", 16, 11, 162};
    EXPECT_EQ(r.at(0), comet);
    EXPECT_EQ(r.at(1), dancer);
}

TEST(Day14_Part1_Test, winningDistance)
{
    auto r = Aoc15::createReindeers(v);
    EXPECT_EQ(Aoc15::winningDistance(r, 1000), 1120);
}


TEST(Day14_Part1_Test, basic)
{
    std::vector<Aoc15::Reindeer> reindeers{Aoc15::Reindeer("Commet", 1, 1, 1)};
    EXPECT_EQ(Aoc15::winningDistance(reindeers, 0), 0);
    EXPECT_EQ(Aoc15::winningDistance(reindeers, 1), 1);
    EXPECT_EQ(Aoc15::winningDistance(reindeers, 2), 1);

    reindeers = {Aoc15::Reindeer("Comet", 1, 2, 1)};
    EXPECT_EQ(Aoc15::winningDistance(reindeers, 4), 3);
}

TEST(Day14_Part2_Test, winningPoints)
{
    auto r = Aoc15::createReindeers(v);
    EXPECT_EQ(Aoc15::winningPoints(r, 1000), 689);
}
