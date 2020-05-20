#include <aoc15/d04.h>

#include <fstream>
#include <iostream>

auto constexpr binName{"aoc15_d04"};
auto constexpr inputLink{"httsp://adventofcode.com/2015/day/4/input"};

void printHelp();

void solveTaskOne(const std::string &l);

void solveTaskTwo(const std::string &l);

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
    std::getline(f, l);
    f.close();

    solveTaskOne(l);
    solveTaskTwo(l);

    return EXIT_SUCCESS;
}

void printHelp()
{
    std::cout << "Usage: " << binName << " FILE" << std::endl;
    std::cout << "Compute aoc15 day four challenge." << std::endl;
    std::cout << std::endl;

    std::cout << "Make sure your input file is correct." << std::endl;
    std::cout << inputLink << std::endl;
}

void solveTaskOne(const std::string &l)
{
    auto r = miningNumber(l, 5);
    std::cout << binName << ": ";
    std::cout << "Solution to day 4 task one is " << r << std::endl;
}

void solveTaskTwo(const std::string &l)
{
    auto r = miningNumber(l, 6);
    std::cout << binName << ": ";
    std::cout << "Solution to day 4 task two is " << r << std::endl;
}
