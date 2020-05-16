#include <aoc15/d01.h>

#include <fstream>
#include <iostream>

auto constexpr binName{"aoc15_d01"};
auto constexpr inputLink{"https://adventofcode.com/2015/day/1/input"};

void printHelp();

void solveTaskOne(const std::string &in);

void solveTaskTwo(const std::string &in);

int main(int argc, char **argv)
{
    if(argc != 2) {
        printHelp();
        return EXIT_FAILURE;
    }
    std::ifstream f{argv[1], std::ifstream::in};
    if (!f.is_open()) {
        std::cerr << binName << ": Failed to open the file." << std::endl;
        return EXIT_FAILURE;
    }
    std::string l;
    std::getline(f, l);
    f.close();

    solveTaskOne(l);
    solveTaskTwo(l);
    return EXIT_SUCCESS;
}

void printHelp()
{
    std::cout << "Usage: " << binName << " <FILE>" << std::endl;
    std::cout << "Compute aoc15 day one challenge." << std::endl;
    std::cout << std::endl;

    std::cout << "Make sure your input file is correct." << std::endl;
    std::cout << inputLink << std::endl;
}

void solveTaskOne(const std::string &in)
{
    std::cout << binName << ": Solution to day one task one is "
        << getFloor(in) << "." << std::endl;
}

void solveTaskTwo(const std::string &in)
{
    std::cout << binName << ": Solution to day one task one is " 
        << getIndexOfFirstBasement(in) << "." << std::endl;
}
