#include <aoc15/d06.h>
#include <gtest/gtest.h>

#include <algorithm>

constexpr auto SmallGridSize{5};

TEST(Day06_Task01_Test, CreateLightsGrid)
{
    auto lg = Aoc15::createLightsGrid(Aoc15::LightsGridSize, Aoc15::LightsGridSize);

    EXPECT_EQ(lg.size(), Aoc15::LightsGridSize);
    for (const auto &row : lg) {
        EXPECT_EQ(row.size(), Aoc15::LightsGridSize);
        EXPECT_TRUE(std::all_of(row.begin(), row.end(), [](const auto &val) { return val == false; }));
    }

    lg = Aoc15::createLightsGrid(Aoc15::LightsGridSize, Aoc15::LightsGridSize, true);
    for (const auto &row : lg) {
        EXPECT_TRUE(std::all_of(row.begin(), row.end(), [](const auto &val) { return val == true; }));
    }
}

TEST(Day06_Task01_Test, TurnLightsOn)
{
    Aoc15::LightsGrid expectedLg = { 
        {true, true, true, false, false}, 
        {true, true, true, false, false},
        {true, true, true, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false}
    };
    auto lg = Aoc15::createLightsGrid(5, 5);
    Aoc15::turnLightsOn(lg, {0, 0}, {2, 2});
    EXPECT_EQ(lg, expectedLg);
    Aoc15::turnLightsOn(lg, {0, 0}, {4, 0});
    expectedLg[0][3] = true;
    expectedLg[0][4] = true;
    EXPECT_EQ(lg, expectedLg);
}

TEST(Day06_Task01_Test, CountLightsOn)
{
    auto lg = Aoc15::createLightsGrid(SmallGridSize, SmallGridSize);
    EXPECT_EQ(Aoc15::countLightsOn(lg), 0);
    lg[0][0] = true;
    EXPECT_EQ(Aoc15::countLightsOn(lg), 1);
    lg[1][0] = true;
    EXPECT_EQ(Aoc15::countLightsOn(lg), 2);
    lg[0][0] = false;
    EXPECT_EQ(Aoc15::countLightsOn(lg), 1);
    EXPECT_EQ(Aoc15::countLightsOn(Aoc15::createLightsGrid(SmallGridSize, SmallGridSize, true)), 25);
}

TEST(Day06_Task01_Test, TurnLightsOff)
{
    Aoc15::LightsGrid expectedLg = { 
        {true, true, true, false, false}, 
        {true, true, true, false, false},
        {true, true, true, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false}
    };
    auto lg = Aoc15::createLightsGrid(SmallGridSize, SmallGridSize, true);
    Aoc15::turnLightsOff(lg, {0, 3}, {4, 4});
    Aoc15::turnLightsOff(lg, {3, 0}, {4, 4});
    EXPECT_EQ(lg, expectedLg);
}

TEST(Day06_Task01_Test, ToggleLights)
{
    Aoc15::LightsGrid expectedLg = { 
        {true, true, true, false, false}, 
        {true, true, true, false, false},
        {true, true, true, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false}
    };
    auto lg = Aoc15::createLightsGrid(SmallGridSize, SmallGridSize);
    Aoc15::toggleLights(lg, {0, 0}, {2, 2});
    EXPECT_EQ(lg, expectedLg);
    Aoc15::toggleLights(lg, {0, 0}, {4, 2});
    Aoc15::toggleLights(lg, {3, 0}, {4, 2});
    Aoc15::toggleLights(lg, {0, 0}, {2, 2});
    EXPECT_EQ(lg, expectedLg);
}

TEST(Day06_Task02_Test, TotalBrigthness)
{
    Aoc15::BLightsGrid blg = {
        { 1, 2, 1 },
        { 1, 2, 1 },
        { 0, 2, 1 }
    };

    EXPECT_EQ(Aoc15::totalBrightness(blg), 11);
    EXPECT_EQ(Aoc15::totalBrightness(Aoc15::createBLightsGrid(SmallGridSize, SmallGridSize)), 0);
    EXPECT_EQ(Aoc15::totalBrightness(Aoc15::createBLightsGrid(SmallGridSize, SmallGridSize, 10)), 250);
}

TEST(Day06_Task_02_Test, TurnBLightsOn)
{
    Aoc15::BLightsGrid expected = {
        { 1, 2, 1 },
        { 1, 2, 1 },
        { 0, 2, 1 }
    };
    auto blg = Aoc15::createBLightsGrid(3, 3);
    Aoc15::turnLightsOn(blg, {0, 0}, {2, 1});
    Aoc15::turnLightsOn(blg, {1, 0}, {1, 2});
    Aoc15::turnLightsOn(blg, {1, 2}, {2, 2});
    EXPECT_EQ(blg, expected);
    auto testMax = Aoc15::createBLightsGrid(1, 1, std::numeric_limits<std::uint32_t>::max());
    expected = testMax;
    Aoc15::turnLightsOn(testMax, {0, 0}, {0, 0});
    EXPECT_EQ(testMax, expected);
}

TEST(Day06_Task_02_Test, TurnBLightsOff)
{
    Aoc15::BLightsGrid blg = {
        { 1, 2, 1 },
        { 1, 2, 1 },
        { 0, 2, 1 }
    };
    Aoc15::turnLightsOff(blg, {1, 2}, {2, 2});
    Aoc15::turnLightsOff(blg, {1, 0}, {1, 2});
    Aoc15::turnLightsOff(blg, {0, 0}, {2, 1});
    EXPECT_EQ(blg, Aoc15::createBLightsGrid(3, 3));
    Aoc15::turnLightsOff(blg, {0, 0}, {0, 0});
    EXPECT_EQ(blg, Aoc15::createBLightsGrid(3, 3));
}

TEST(Day06_Task_02_Test, ToggleBLightsOff)
{
    Aoc15::BLightsGrid expected = {
        { 2, 4, 2 },
        { 2, 4, 2 },
        { 0, 4, 2 }
    };
    auto blg = Aoc15::createBLightsGrid(3, 3);
    Aoc15::toggleLights(blg, {0, 0}, {2, 1});
    Aoc15::toggleLights(blg, {1, 0}, {1, 2});
    Aoc15::toggleLights(blg, {1, 2}, {2, 2});
    EXPECT_EQ(blg, expected);
}
