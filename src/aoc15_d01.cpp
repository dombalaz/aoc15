#include <aoc15/d01.h>

#include <fstream>
#include <iostream>

auto constexpr printName{"aoc15_d01: "};

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
        std::cerr << printName << "Failed to open the file." << std::endl;
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
    std::cout << "Usage: aoc15-d01 <FILE>" << std::endl;
    std::cout << "Compute aoc15 day one challenge." << std::endl;
    std::cout << std::endl;

    std::cout << "Make sure your input file is correct." << std::endl;
    std::cout << "https://adventofcode.com/2015/day/1/input" << std::endl;
}

void solveTaskOne(const std::string &in)
{
    std::cout << printName << "Solution to day one task one is "
        << getFloor(in) << "." << std::endl;
}

void solveTaskTwo(const std::string &in)
{
    std::cout << printName << "Solution to day one task one is " 
        << getIndexOfFirstBasement(in) << "." << std::endl;
}
