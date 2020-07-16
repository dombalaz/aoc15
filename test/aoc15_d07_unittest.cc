#include <aoc15/d07.h>
#include <gtest/gtest.h>

TEST(Day02_Task01_Test, SignalOnWire)
{
    Circuit c = {
        {"x", "123"},
        {"y", "456"},
        {"d", "x AND y"},
        {"e", "x OR y"},
        {"f", "x LSHIFT 2"},
        {"g", "y RSHIFT 2"},
        {"h", "NOT x"},
        {"i", "NOT y"}
    };

    EXPECT_EQ(signalOnWire("x", c), 123);
    EXPECT_EQ(signalOnWire("y", c), 456);
    EXPECT_EQ(signalOnWire("d", c), 72);
    EXPECT_EQ(signalOnWire("e", c), 507);
    EXPECT_EQ(signalOnWire("f", c), 492);
    EXPECT_EQ(signalOnWire("g", c), 114);
    EXPECT_EQ(signalOnWire("h", c), 65412);
    EXPECT_EQ(signalOnWire("i", c), 65079);
}
