#include <aoc15/d07.h>
#include <gtest/gtest.h>

TEST(Day02_Task01_Test, SignalOnWire)
{
    Aoc15::Circuit c = {
        {"x", "123"},
        {"y", "456"},
        {"d", "x AND y"},
        {"e", "x OR y"},
        {"f", "x LSHIFT 2"},
        {"g", "y RSHIFT 2"},
        {"h", "NOT x"},
        {"i", "NOT y"},
        {"j", "i"},
        {"k", "123 AND y"}
    };

    EXPECT_EQ(Aoc15::signalOnWire("x", c), 123);
    EXPECT_EQ(Aoc15::signalOnWire("y", c), 456);
    EXPECT_EQ(Aoc15::signalOnWire("d", c), 72);
    EXPECT_EQ(Aoc15::signalOnWire("e", c), 507);
    EXPECT_EQ(Aoc15::signalOnWire("f", c), 492);
    EXPECT_EQ(Aoc15::signalOnWire("g", c), 114);
    EXPECT_EQ(Aoc15::signalOnWire("h", c), 65412);
    EXPECT_EQ(Aoc15::signalOnWire("i", c), 65079);
    EXPECT_EQ(Aoc15::signalOnWire("j", c), Aoc15::signalOnWire("i", c));
    EXPECT_EQ(Aoc15::signalOnWire("k", c), 72);
}
