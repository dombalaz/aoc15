#include <aoc15/d05.h>

#include <fstream>
#include <iostream>

auto constexpr binName{"aoc15_d05"};
auto constexpr inputLink{"httsp://adventofcode.com/2015/day/5/input"};

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
    std::cout << "Compute aoc15 day five challenge." << std::endl;
    std::cout << std::endl;

    std::cout << "Make sure your input file is correct." << std::endl;
    std::cout << inputLink << std::endl;
}

void solveTaskOne(std::ifstream &f)
{
    std::string l;
    std::uint32_t r{0};
    while (std::getline(f, l)) {
        if (isNice(l)) {
	    ++r;
	}
    }
    std::cout << binName << ": Solution to day five task one is " << r
	    << std::endl;
}

