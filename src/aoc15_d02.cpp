#include <aoc15/d02.h>

#include <fstream>
#include <iostream>

auto constexpr binName{"aoc15_d02"};
auto constexpr inputLink{"httsp://adventofcode.com/2015/day/2/input"};

void printHelp();

void solveTaskOne(std::ifstream &f);

void solveTaskTwo(std::ifstream &f);

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

    f.clear();
    f.seekg(0);

    solveTaskTwo(f);

    f.close();

    return EXIT_SUCCESS;
}

void printHelp()
{
    std::cout << "Usage: " << binName << " FILE" << std::endl;
    std::cout << "Compute aoc15 day two challenge." << std::endl;
    std::cout << std::endl;

    std::cout << "Make sure your input file is correct." << std::endl;
    std::cout << inputLink << std::endl;
}

void solveTaskOne(std::ifstream &f)
{
    std::string l;
    std::uint32_t r{0};
    while (std::getline(f, l)) {
        auto i = l.find('x');
        auto x = std::stoul(l.substr(0, i));
        l = l.substr(i + 1);
        i = l.find('x');
        auto y = std::stoul(l.substr(0, i));
        auto z = std::stoul(l.substr(i + 1));
        r += paperForGift(x, y, z);
    }
    std::cout << binName << ": Solution to day two task one is " << r 
        << std::endl;
}

void solveTaskTwo(std::ifstream &f)
{
    std::string l;
    uint r{0};
    while (std::getline(f, l)) {
        auto i = l.find('x');
        auto x = std::stoul(l.substr(0, i));
        l = l.substr(i + 1);
        i = l.find('x');
        auto y = std::stoul(l.substr(0, i));
        auto z = std::stoul(l.substr(i + 1));
        r += ribbonForGift(x, y, z);
    }
    std::cout << binName << ": Solution to day two task two is " << r 
        << std::endl;
}
