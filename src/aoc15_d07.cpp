#include <aoc15/d07.h>

#include <fstream>
#include <iostream>
#include <regex>

auto constexpr binName{"aoc15_d07"};
auto constexpr inputLink{"httsp://adventofcode.com/2015/day/7/input"};

void printHelp();

void solveTaskOneTwo(std::ifstream &f);

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

    solveTaskOneTwo(f);

    f.close();

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

void solveTaskOneTwo(std::ifstream &f)
{
    std::string l;
    std::regex regex("([a-z0-9A-Z ]*) -> ([a-z]*)");
    std::smatch match;
    Circuit c;
    while (std::getline(f, l)) {
        std::regex_match(l, match, regex);
        c.insert({match[2], match[1]});
	}
    auto c2 = c;
    auto res = signalOnWire("a", c);
    std::cout << binName << ": Solution to day seven task one is " << res
        << std::endl;
    c2["b"] = std::to_string(res);
    std::cout << binName << ": Solution to day seven task two is " << signalOnWire("a", c2)
        << std::endl;
}

