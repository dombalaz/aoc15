#include <aoc15/d12.h>
#include <gtest/gtest.h>

TEST(Day12_Part1_Test, sumNumbersInJson)
{
    EXPECT_EQ(sumNumbersInJson("[]"), 0);
    EXPECT_EQ(sumNumbersInJson("{}"), 0);
    EXPECT_EQ(sumNumbersInJson("[1,2,3]"), 6);
    EXPECT_EQ(sumNumbersInJson(R"({"a":2,"b":4})"), 6);
    EXPECT_EQ(sumNumbersInJson(R"([[[3]]])"), 3);
    EXPECT_EQ(sumNumbersInJson(R"({"a":{"b":4},"c":-1})"), 3);
    EXPECT_EQ(sumNumbersInJson(R"({"a":[-1,1]})"), 0);
    EXPECT_EQ(sumNumbersInJson(R"([-1,{"a":1}])"), 0);
}

TEST(Day12_Part2_Test, sumNumbersInJson)
{
    EXPECT_EQ(sumNumbersInJson2(R"([1,{"c":"red","b":2},3])"), 4);
    EXPECT_EQ(sumNumbersInJson2(R"([1,2,3])"), 6);
    EXPECT_EQ(sumNumbersInJson2(R"({"d":"red","e":[1,2,3,4],"f":5})"), 0);
    EXPECT_EQ(sumNumbersInJson2(R"([1,"red",5])"), 6);
}
