#include <aoc15/d14.h>
#include <gtest/gtest.h>

const std::vector<std::string> v
{
    "Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds.",
    "Dancer can fly 16 km/s for 11 seconds, but then must rest for 162 seconds."
};

TEST(Day14_Part1_Test, createReindeers)
{
    auto r = createReindeers(v);
    ASSERT_EQ(r.size(), 2);
    Reindeer comet{"Comet", 14, 10, 127};
    Reindeer dancer{"Dancer", 16, 11, 162};
    EXPECT_EQ(r.at(0), comet);
    EXPECT_EQ(r.at(1), dancer);
}

TEST(Day14_Part1_Test, winningDistance)
{
    auto r = createReindeers(v);
    EXPECT_EQ(winningDistance(r, 1000), 1120);
}


TEST(Day14_Part1_Test, basic)
{
    std::vector<Reindeer> reindeers{Reindeer("Commet", 1, 1, 1)};
    EXPECT_EQ(winningDistance(reindeers, 0), 0);
    EXPECT_EQ(winningDistance(reindeers, 1), 1);
    EXPECT_EQ(winningDistance(reindeers, 2), 1);

    reindeers = {Reindeer("Comet", 1, 2, 1)};
    EXPECT_EQ(winningDistance(reindeers, 4), 3);
}

TEST(Day14_Part2_Test, winningPoints)
{
    auto r = createReindeers(v);
    EXPECT_EQ(winningPoints(r, 1000), 689);
}
