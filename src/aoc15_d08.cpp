#include <aoc15/d08.h>

#include <fstream>
#include <iostream>
#include <vector>

auto constexpr binName{"aoc15_d08"};
auto constexpr inputLink{"httsp://adventofcode.com/2015/day/8/input"};

void printHelp();

void solvePartOne(std::vector<std::string> &v);

void solvePartTwo(std::vector<std::string> &v);

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

    std::string l;
    std::vector<std::string> v;
    while (std::getline(f, l)) {
        v.push_back(l);
	}
    f.close();

    solvePartOne(v);
    solvePartTwo(v);

    return EXIT_SUCCESS;
}

void printHelp()
{
    std::cout << "Usage: " << binName << " FILE" << std::endl;
    std::cout << "Compute aoc15 day seven challenge." << std::endl;
    std::cout << std::endl;

    std::cout << "Make sure your input file is correct." << std::endl;
    std::cout << inputLink << std::endl;
}

void solvePartOne(std::vector<std::string> &v)
{
    auto memoryChars{0u};
    auto totalChars{0u};
    for (auto i = 0u; i < v.size(); ++i) {
        memoryChars += countCharacters(v.at(i));
        totalChars += v.at(i).size();
    }
    std::cout << binName << ": Solution to day eight part one is " << totalChars - memoryChars
        << std::endl;
}

void solvePartTwo(std::vector<std::string> &v)
{
    auto totalEncodedChars{0u};
    auto totalChars{0u};
    for (auto i = 0u; i < v.size(); ++i) {
        totalEncodedChars += countEncodedChars(v.at(i));
        totalChars += v.at(i).size();
    }
    std::cout << binName << ": Solution to day eight part two is " << totalEncodedChars - totalChars
        << std::endl;
}
