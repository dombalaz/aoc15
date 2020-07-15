#include <aoc15/d06.h>
#include <gtest/gtest.h>

constexpr auto SmallGridSize{5};

TEST(Day06_Task01_Test, CreateLightsGrid)
{
    auto lg = createLightsGrid(LightsGridSize, LightsGridSize);

    EXPECT_EQ(lg.size(), LightsGridSize);
    for (const auto &row : lg) {
        EXPECT_EQ(row.size(), LightsGridSize);
        EXPECT_TRUE(std::all_of(row.begin(), row.end(), [](const auto &val) { return val == false; }));
    }

    lg = createLightsGrid(LightsGridSize, LightsGridSize, true);
    for (const auto &row : lg) {
        EXPECT_TRUE(std::all_of(row.begin(), row.end(), [](const auto &val) { return val == true; }));
    }
}

TEST(Day06_Task01_Test, TurnLightsOn)
{
    LightsGrid expectedLg = { 
        {true, true, true, false, false}, 
        {true, true, true, false, false},
        {true, true, true, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false}
    };
    auto lg = createLightsGrid(5, 5);
    turnLightsOn(lg, {0, 0}, {2, 2});
    EXPECT_EQ(lg, expectedLg);
    turnLightsOn(lg, {0, 0}, {4, 0});
    expectedLg[0][3] = true;
    expectedLg[0][4] = true;
    EXPECT_EQ(lg, expectedLg);
}

TEST(Day06_Task01_Test, CountLightsOn)
{
    auto lg = createLightsGrid(SmallGridSize, SmallGridSize);
    EXPECT_EQ(countLightsOn(lg), 0);
    lg[0][0] = true;
    EXPECT_EQ(countLightsOn(lg), 1);
    lg[1][0] = true;
    EXPECT_EQ(countLightsOn(lg), 2);
    lg[0][0] = false;
    EXPECT_EQ(countLightsOn(lg), 1);
    EXPECT_EQ(countLightsOn(createLightsGrid(SmallGridSize, SmallGridSize, true)), 25);
}

TEST(Day06_Task01_Test, TurnLightsOff)
{
    LightsGrid expectedLg = { 
        {true, true, true, false, false}, 
        {true, true, true, false, false},
        {true, true, true, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false}
    };
    auto lg = createLightsGrid(SmallGridSize, SmallGridSize, true);
    turnLightsOff(lg, {0, 3}, {4, 4});
    turnLightsOff(lg, {3, 0}, {4, 4});
    EXPECT_EQ(lg, expectedLg);
}

TEST(Day06_Task01_Test, ToggleLights)
{
    LightsGrid expectedLg = { 
        {true, true, true, false, false}, 
        {true, true, true, false, false},
        {true, true, true, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false}
    };
    auto lg = createLightsGrid(SmallGridSize, SmallGridSize);
    toggleLights(lg, {0, 0}, {2, 2});
    EXPECT_EQ(lg, expectedLg);
    toggleLights(lg, {0, 0}, {4, 2});
    toggleLights(lg, {3, 0}, {4, 2});
    toggleLights(lg, {0, 0}, {2, 2});
    EXPECT_EQ(lg, expectedLg);
}
