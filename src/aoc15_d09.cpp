#include <aoc15/d09.h>

#include <fstream>
#include <iostream>
#include <vector>

auto constexpr binName{"aoc15_d09"};
auto constexpr inputLink{"httsp://adventofcode.com/2015/day/9/input"};

void printHelp();

void solvePartOne(const std::vector<std::string> &v);

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

    return EXIT_SUCCESS;
}

void printHelp()
{
    std::cout << "Usage: " << binName << " FILE" << std::endl;
    std::cout << "Compute aoc15 day nine challenge." << std::endl;
    std::cout << std::endl;

    std::cout << "Make sure your input file is correct." << std::endl;
    std::cout << inputLink << std::endl;
}

void solvePartOne(const std::vector<std::string> &v)
{
    std::cout << binName << ": Solution to day nine part one is " << shortestDistance(v)
        << std::endl;
}
