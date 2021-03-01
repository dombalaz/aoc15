#include <fstream>
#include <iostream>
#include <regex>
#include <set>
#include <vector>

#include <aoc15/aoc15.h>

void solve1(const std::vector<std::string> &in);

void solve2(const std::vector<std::string> &in);

void solve3(const std::vector<std::string> &in);

void solve4(const std::vector<std::string> &in);

void solve5(const std::vector<std::string> &in);

void solve6(const std::vector<std::string> &in);

void solve7(const std::vector<std::string> &in);

void solve8(const std::vector<std::string> &in);

void solve9(const std::vector<std::string> &in);

void solve10(const std::vector<std::string> &in);

void solve11(const std::vector<std::string> &in);

void solve12(const std::vector<std::string> &in);

void solve13(const std::vector<std::string> &in);

void solve14(const std::vector<std::string> &in);

void solve15(const std::vector<std::string> &in);

void solve16(const std::vector<std::string> &in);

void solve17(const std::vector<std::string> &in);

const static std::vector<std::function<void(std::vector<std::string>)>> Functions{
    solve1,
    solve2,
    solve3,
    solve4,
    solve5,
    solve6,
    solve7,
    solve8,
    solve9,
    solve10,
    solve11,
    solve12,
    solve13,
    solve14,
    solve15,
    solve16,
    solve17
};

auto main(int argc, char **argv) -> int
{
    if (argc != 3) {
        std::cerr << "Wrong number of arguments." << std::endl;
        return EXIT_FAILURE;
    }

    // TODO(Dominik Balaz): Fix by introducing gsl::span.
    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    auto d = std::stoul(argv[1]);

    // TODO(Dominik Balaz): Fix by introducing gsl::span.
    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    std::ifstream f{argv[2], std::ifstream::in};
    if (!f.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return EXIT_FAILURE;
    }

    std::string l;
    std::vector<std::string> input;
    while (std::getline(f, l)) {
        input.push_back(l);
    }
    f.close();

    if (input.empty()) {
        std::cerr << "Input is empty." << std::endl;
        return EXIT_FAILURE;
    }
    if (d > Functions.size() || d == 0) {
        std::cerr << "The day " << d << " is not solved yet or is invalid." << std::endl;
        return EXIT_FAILURE;
    }

    Functions[d - 1](input);

    return EXIT_SUCCESS;
}

void solve1(const std::vector<std::string> &in)
{
    std::cout << "1_1: " << getFloor(in.front()) << std::endl;
    std::cout << "1_2: " << getIndexOfFirstBasement(in.front()) << std::endl;
}

void solve2(const std::vector<std::string> &in)
{
    auto r1 = 0U;
    auto r2 = 0U;
    const std::regex regex{"([0-9]+)x([0-9]+)x([0-9]+)"};
    std::smatch match;
    for (const auto &s : in) {
        std::regex_match(s, match, regex);
        auto x = std::stoul(match[1]);
        auto y = std::stoul(match[2]);
        auto z = std::stoul(match[3]);
        r1 += paperForGift(x, y, z);
        r2 += ribbonForGift(x, y, z);
    }
    std::cout << "2_1: " << r1 << std::endl;
    std::cout << "2_2: " << r2 << std::endl;
}

void solve3(const std::vector<std::string> &in)
{
    std::cout << "3_1: " << visitedHousesBySanta(in.front()) << std::endl;
    std::cout << "3_2: " << visitedHousesBySantaAndRobot(in.front()) << std::endl;
}

void solve4(const std::vector<std::string> &in)
{
    constexpr auto TaskOneZeroes{5U};
    constexpr auto TaskTwoZeroes{6U};

    std::cout << "4_1: " << miningNumber(in.front(), TaskOneZeroes) << std::endl;
    std::cout << "4_2: " << miningNumber(in.front(), TaskTwoZeroes) << std::endl;
}

void solve5(const std::vector<std::string> &in)
{
    auto r1 = 0U;
    auto r2 = 0U;
    for (const auto &s : in) {
        if (isNice(s)) {
            ++r1;
        }
        if (isNice2(s)) {
            ++r2;
        }
    }
    std::cout << "5_1: " << r1 << std::endl;
    std::cout << "5_2: " << r2 << std::endl;
}

void solve6(const std::vector<std::string> &in)
{
    constexpr auto InstructionIndex{1U};
    constexpr auto FirstPointXIndex{2U};
    constexpr auto FirstPointYIndex{3U};
    constexpr auto SecondPointXIndex{4U};
    constexpr auto SecondPointYIndex{5U};

    std::regex regex("(turn on|toggle|turn off) ([0-9]*),([0-9]*) through ([0-9]*),([0-9]*)");
    std::smatch match;
    auto lg = createLightsGrid(LightsGridSize, LightsGridSize);
    auto blg = createBLightsGrid(LightsGridSize, LightsGridSize);
    for (const auto &s : in) {
        std::regex_match(s, match, regex);
        LightInstruction li{LightInstruction::On};
        if(match[InstructionIndex] == "turn on") {
            li = LightInstruction::On;
        } else if (match[1] == "turn off") {
            li = LightInstruction::Off;
        } else { 
            li = LightInstruction::Toggle;
        }
        Point from{std::stoul(match[FirstPointXIndex]), std::stoul(match[FirstPointYIndex])};
        Point to{std::stoul(match[SecondPointXIndex]), std::stoul(match[SecondPointYIndex])};
        doLights(li, lg, from, to);
        doLights(li, blg, from, to);
    }
    std::cout << "6_1: " << countLightsOn(lg) << std::endl;
    std::cout << "6_2: " << totalBrightness(blg) << std::endl;
}

void solve7(const std::vector<std::string> &in)
{
    std::regex regex("([a-z0-9A-Z ]*) -> ([a-z]*)");
    std::smatch match;
    Circuit c1;
    for (const auto &s : in) {
        std::regex_match(s, match, regex);
        c1.insert({match[2], match[1]});
    }
    auto c2 = c1;
    auto r1 = signalOnWire("a", c1);
    c2["b"] = std::to_string(r1);
    std::cout << "7_1: " << r1 << std::endl;
    std::cout << "7_2: " << signalOnWire("a", c2) << std::endl;
}

void solve8(const std::vector<std::string> &in)
{
    auto memoryChars{0U};
    auto totalEncodedChars{0U};
    auto totalChars{0U};
    for (const auto &s : in) {
        memoryChars += countCharacters(s);
        totalEncodedChars += countEncodedChars(s);
        totalChars += s.size();
    }
    std::cout << "8_1: " << totalChars - memoryChars << std::endl;
    std::cout << "8_2: " << totalEncodedChars - totalChars << std::endl;
}

void solve9(const std::vector<std::string> &in)
{
    std::cout << "9_1: " << shortestDistance(in) << std::endl;
    std::cout << "9_2: " << longestDistance(in) << std::endl;
}

void solve10(const std::vector<std::string> &in)
{
    constexpr auto fortyTimes {40U};
    constexpr auto fiftyTimes {50U};
    auto s = in.front();
    for (size_t i = 0; i < fortyTimes; ++i) {
        s = lookAndSay(s);
    }
    std::cout << "10_1: " << s.size() << std::endl;
    for (size_t i = fortyTimes; i < fiftyTimes; ++i) {
        s = lookAndSay(s);
    }
    std::cout << "10_2: " << s.size() << std::endl;
}

void solve11(const std::vector<std::string> &in)
{
    auto r = nextValidPass(in.front());
    std::cout << "11_1: " << r << std::endl;
    std::cout << "11_2: " << nextValidPass(r) << std::endl;
}

void solve12(const std::vector<std::string> &in)
{
    std::cout << "12_1: " << sumNumbersInJson(in.at(0)) << std::endl;
    std::cout << "12_2: " << sumNumbersInJson2(in.at(0)) << std::endl;
}

void solve13(const std::vector<std::string> &in)
{
    auto m = createPeopleHappinessMap(in);
    std::cout << "13_1: " << optimalHappiness(m) << std::endl;

    std::set<std::string> s;
    for (const auto &kv : m) {
        s.insert(kv.first.first);
    }
    const std::string me{"XXX"};
    for (const auto &v : s) {
        m.emplace(Key{v, me}, 0);
        m.emplace(Key{me, v}, 0);
    }
    std::cout << "13_2: " << optimalHappiness(m) << std::endl;
}

void solve14(const std::vector<std::string> &in)
{
    auto v = createReindeers(in);
    constexpr auto time{2503U};
    std::cout << "14_1: " << winningDistance(v, time) << std::endl;
    std::cout << "14_2: " << winningPoints(v, time) << std::endl;
}

void solve15(const std::vector<std::string> &in)
{
    constexpr auto targetCalories{500U};
    auto v = createIngredients(in);
    std::cout << "15_1: " <<  highestScoringCookie(v) << std::endl;
    std::cout << "15_2: " <<  highestScoringCookie(v, targetCalories) << std::endl;
}

void solve16(const std::vector<std::string> &in)
{
    // Here we return index in vector so we need to increment the result.
    auto samples{createMfcsamCompoundsSamples(in)};
    std::cout << "16_1: " << auntNumber(sample, samples) + 1 << "\n";

    std::cout << "16_2: " << auntNumber(sample2, samples) + 1 << "\n";
}

void solve17(const std::vector<std::string> &in)
{
    constexpr auto topSum{150U};
    std::cout << "17_1: " << combinationsToTopSum(in, topSum) << "\n";
    std::cout << "17_2: " << combinationsWithMinToTopSum(in, topSum) << "\n";
}
