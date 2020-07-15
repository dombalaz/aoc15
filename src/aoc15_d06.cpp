#include <aoc15/d06.h>

#include <fstream>
#include <iostream>
#include <regex>

auto constexpr binName{"aoc15_d06"};
auto constexpr inputLink{"httsp://adventofcode.com/2015/day/6/input"};

void printHelp();

void solveTaskOne(std::ifstream &f);

int main(int argc, char **argv)
{
    if(argc != 2) {
        printHelp();
        return EXIT_FAILURE;
    }
    std::ifstream f(argv[1]);
    if (!f.is_open()) {
        std::cerr << binName << ": Failed to open the file." << std::endl;
        return EXIT_FAILURE;
    }

    solveTaskOne(f);

    f.close();

    return EXIT_SUCCESS;
}

void printHelp()
{
    std::cout << "Usage: " << binName << " FILE" << std::endl;
    std::cout << "Compute aoc15 day six challenge." << std::endl;
    std::cout << std::endl;

    std::cout << "Make sure your input file is correct." << std::endl;
    std::cout << inputLink << std::endl;
}

void solveTaskOne(std::ifstream &f)
{
    std::string l;
    std::regex regex("(turn on|toggle|turn off) ([0-9]*),([0-9]*) through ([0-9]*),([0-9]*)");
    std::smatch match;
    auto lg = createLightsGrid(LightsGridSize, LightsGridSize);
    while (std::getline(f, l)) {
        std::regex_match(l, match, regex);
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
	}
    std::cout << binName << ": Solution to day six task one is " << countLightsOn(lg)
        << std::endl;
}

