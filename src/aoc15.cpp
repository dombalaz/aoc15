#include <fstream>
#include <iostream>
#include <vector>
#include <regex>

#include <aoc15/aoc15.h>

void solve1(const std::string &in);

void solve2(const std::vector<std::string> &in);

void solve3(const std::string &in);

void solve4(const std::string &in);

void solve5(const std::vector<std::string> &in);

void solve6(const std::vector<std::string> &in);

void solve7(const std::vector<std::string> &in);

void solve8(const std::vector<std::string> &in);

void solve9(const std::vector<std::string> &in);

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "Wrong number of arguments." << std::endl;
        return EXIT_FAILURE;
    }

    auto d = std::stoul(argv[1]);

    std::ifstream f{argv[2], std::ifstream::in};
    if (!f.is_open()) {
        return EXIT_FAILURE;
    }

    std::string l;
    std::vector<std::string> input;
    while (std::getline(f, l)) {
        input.push_back(l);
    }
    f.close();

    switch (d) {
    case 1:
        solve1(input.front());
        break;
    case 2:
        solve2(input);
        break;
    case 3:
        solve3(input.front());
        break;
    case 4:
        solve4(input.front());
        break;
    case 5:
        solve5(input);
        break;
    case 6:
        solve6(input);
        break;
    case 7:
        solve7(input);
        break;
    case 8:
        solve8(input);
        break;
    case 9:
        solve9(input);
        break;
    default:
        std::cerr << "Wrong day number." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void solve1(const std::string &in)
{
    std::cout << "1_1: " << getFloor(in) << std::endl;
    std::cout << "1_2: " << getIndexOfFirstBasement(in) << std::endl;
}

void solve2(const std::vector<std::string> &in)
{
    auto r1 = 0u;
    auto r2 = 0u;
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

void solve3(const std::string &in)
{
    std::cout << "3_1: " << visitedHousesBySanta(in) << std::endl;
    std::cout << "3_2: " << visitedHousesBySantaAndRobot(in) << std::endl;
}

void solve4(const std::string &in)
{
    std::cout << "4_1: " << miningNumber(in, 5) << std::endl;
    std::cout << "4_2: " << miningNumber(in, 6) << std::endl;
}

void solve5(const std::vector<std::string> &in)
{
    auto r1 = 0u;
    auto r2 = 0u;
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
    std::regex regex("(turn on|toggle|turn off) ([0-9]*),([0-9]*) through ([0-9]*),([0-9]*)");
    std::smatch match;
    auto lg = createLightsGrid(LightsGridSize, LightsGridSize);
    auto blg = createBLightsGrid(LightsGridSize, LightsGridSize);
    for (const auto &s : in) {
        std::regex_match(s, match, regex);
        LightInstruction li{LightInstruction::On};
        if(match[1] == "turn on") {
            li = LightInstruction::On;
        } else if (match[1] == "turn off") {
            li = LightInstruction::Off;
        } else { 
            li = LightInstruction::Toggle;
        }
        Point from{std::stoul(match[2]), std::stoul(match[3])};
        Point to{std::stoul(match[4]), std::stoul(match[5])};
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
    auto memoryChars{0u};
    auto totalEncodedChars{0u};
    auto totalChars{0u};
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

