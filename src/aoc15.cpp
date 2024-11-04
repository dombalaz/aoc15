#include "aoc15/d09.h"
#include "aoc15/d12.h"
#include "aoc15/d13.h"
#include "aoc15/d14.h"
#include "aoc15/d15.h"
#include <fstream>
#include <iostream>
#include <vector>

#include <aoc15/aoc15.h>

void solve1(const std::vector<std::string> &in);

void solve2(const std::vector<std::string> &in);

void solve3(const std::vector<std::string> &in);

void solve4(const std::vector<std::string> &in);

void solve5(const std::vector<std::string> &in);

void solve6(const std::vector<std::string> &in);

void solve7(const std::vector<std::string> &in);

void solve8(const std::vector<std::string> &in);

void solve9(const std::vector<std::string> &in);

void solve10(const std::vector<std::string> &in);

void solve11(const std::vector<std::string> &in);

void solve12(const std::vector<std::string> &in);

void solve13(const std::vector<std::string> &in);

void solve14(const std::vector<std::string> &in);

void solve15(const std::vector<std::string> &in);

void solve16(const std::vector<std::string> &in);

void solve17(const std::vector<std::string> &in);

void solve18(const std::vector<std::string> &in);

void solve19(const std::vector<std::string> &in);

const static std::vector<std::function<void(std::vector<std::string>)>> Functions{
    solve1,
    solve2,
    solve3,
    solve4,
    solve5,
    solve6,
    solve7,
    solve8,
    solve9,
    solve10,
    solve11,
    solve12,
    solve13,
    solve14,
    solve15,
    solve16,
    solve17,
    solve18,
    solve19
};

auto main(int argc, char **argv) -> int
{
    if (argc != 3) {
        std::cerr << "Wrong number of arguments." << std::endl;
        return EXIT_FAILURE;
    }

    // TODO(Dominik Balaz): Fix by introducing gsl::span.
    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    auto d = std::stoul(argv[1]);

    // TODO(Dominik Balaz): Fix by introducing gsl::span.
    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    std::ifstream f{argv[2], std::ifstream::in};
    if (!f.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return EXIT_FAILURE;
    }

    std::string l;
    std::vector<std::string> input;
    while (std::getline(f, l)) {
        input.push_back(l);
    }
    f.close();

    if (input.empty()) {
        std::cerr << "Input is empty." << std::endl;
        return EXIT_FAILURE;
    }
    if (d > Functions.size() || d == 0) {
        std::cerr << "The day " << d << " is not solved yet or is invalid." << std::endl;
        return EXIT_FAILURE;
    }

    Functions[d - 1](input);

    return EXIT_SUCCESS;
}

void solve1(const std::vector<std::string> &in)
{
    std::cout << "1_1: " << Aoc15::solveD1P1(in.front()) << std::endl;
    std::cout << "1_2: " << Aoc15::solveD1P2(in.front()) << std::endl;
}

void solve2(const std::vector<std::string> &in)
{
    std::cout << "2_1: " << Aoc15::solveD2P1(in) << std::endl;
    std::cout << "2_2: " << Aoc15::solveD2P2(in) << std::endl;
}

void solve3(const std::vector<std::string> &in)
{
    std::cout << "3_1: " << Aoc15::solveD3P1(in.front()) << std::endl;
    std::cout << "3_2: " << Aoc15::solveD3P2(in.front()) << std::endl;
}

void solve4(const std::vector<std::string> &in)
{
    std::cout << "4_1: " << Aoc15::solveD4P1(in.front()) << std::endl;
    std::cout << "4_2: " << Aoc15::solveD4P2(in.front()) << std::endl;
}

void solve5(const std::vector<std::string> &in)
{
    std::cout << "5_1: " << Aoc15::solveD5P1(in) << std::endl;
    std::cout << "5_2: " << Aoc15::solveD5P2(in) << std::endl;
}

void solve6(const std::vector<std::string> &in)
{
    std::cout << "6_1: " << Aoc15::solveD6P1(in) << std::endl;
    std::cout << "6_2: " << Aoc15::solveD6P2(in) << std::endl;
}

void solve7(const std::vector<std::string> &in)
{
    std::cout << "7_1: " << Aoc15::solveD7P1(in) << std::endl;
    std::cout << "7_2: " << Aoc15::solveD7P2(in) << std::endl;
}

void solve8(const std::vector<std::string> &in)
{
    std::cout << "8_1: " << Aoc15::solveD8P1(in) << std::endl;
    std::cout << "8_2: " << Aoc15::solveD8P2(in) << std::endl;
}

void solve9(const std::vector<std::string> &in)
{
    std::cout << "9_1: " << Aoc15::solveD9P1(in) << std::endl;
    std::cout << "9_2: " << Aoc15::solveD9P2(in) << std::endl;
}

void solve10(const std::vector<std::string> &in)
{
    std::cout << "10_1: " << Aoc15::solveD10P1(in.front()) << std::endl;
    std::cout << "10_2: " << Aoc15::solveD10P2(in.front()) << std::endl;

}

void solve11(const std::vector<std::string> &in)
{
    std::cout << "11_1: " << Aoc15::solveD11P1(in.front()) << std::endl;
    std::cout << "11_2: " << Aoc15::solveD11P2(in.front()) << std::endl;
}

void solve12(const std::vector<std::string> &in)
{
    std::cout << "12_1: " << Aoc15::solveD12P1(in.front()) << std::endl;
    std::cout << "12_2: " << Aoc15::solveD12P2(in.front()) << std::endl;
}

void solve13(const std::vector<std::string> &in)
{
    std::cout << "13_1: " << Aoc15::solveD13P1(in) << std::endl;
    std::cout << "13_2: " << Aoc15::solveD13P2(in) << std::endl;
}

void solve14(const std::vector<std::string> &in)
{
    std::cout << "14_1: " << Aoc15::solveD14P1(in) << std::endl;
    std::cout << "14_2: " << Aoc15::solveD14P2(in) << std::endl;
}

void solve15(const std::vector<std::string> &in)
{
    std::cout << "15_1: " <<  Aoc15::solveD15P1(in) << std::endl;
    std::cout << "15_2: " <<  Aoc15::solveD15P2(in) << std::endl;
}

void solve16(const std::vector<std::string> &in)
{
    std::cout << "16_1: " <<  Aoc15::solveD16P1(in) << std::endl;
    std::cout << "16_2: " <<  Aoc15::solveD16P2(in) << std::endl;
}

void solve17(const std::vector<std::string> &in)
{
    std::cout << "17_1: " <<  Aoc15::solveD17P1(in) << std::endl;
    std::cout << "17_2: " <<  Aoc15::solveD17P2(in) << std::endl;
}

void solve18(const std::vector<std::string> &in)
{
    std::cout << "18_1: " <<  Aoc15::solveD18P1(in) << std::endl;
    std::cout << "18_2: " <<  Aoc15::solveD18P2(in) << std::endl;
}

void solve19(const std::vector<std::string> &in)
{
    std::cout << "19_1: " <<  Aoc15::solveD19P1(in) << std::endl;
    std::cout << "19_2: " <<  Aoc15::solveD19P2(in) << std::endl;
}