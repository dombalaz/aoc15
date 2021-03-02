#include <aoc15/d05.h>

#include <algorithm>

auto Aoc15::solveD5P1(const std::vector<std::string> &in) -> std::uint32_t
{
    return solveD5(in, isNice);
}

auto Aoc15::solveD5P2(const std::vector<std::string> &in) -> std::uint32_t
{
    return solveD5(in, isNice2);
}

auto Aoc15::solveD5(const std::vector<std::string> &in, std::function<bool(std::string_view)> fun) -> std::uint32_t
{
    auto r{0U};
    for (const auto &s : in) {
        if (fun(s)) {
            ++r;
        }
    }
    return r;
}

auto Aoc15::containsAtLeast3Vowels(std::string_view in) -> bool
{
    const std::string_view vowels{"aeiou"};
    auto count{0};
    for (const char &c : in) {
        if (vowels.find(c) != std::string_view::npos) {
            ++count;
        }
            if (count == 3) {
            return true;
        }
    }
    return false;
}

auto Aoc15::containsOneLetterTwiceInRow(std::string_view in) -> bool
{
    for(size_t i = 1; i < in.size(); ++i) {
        if(in.at(i - 1) == in.at(i)) {
	    return true;
	}
    }
    return false;
}

auto Aoc15::doesntContainsTheStrings(std::string_view in) -> bool
{
    const std::vector<std::string_view> strings{"ab", "cd", "pq", "xy"};
    for (const auto &s : strings) {
        if (in.find(s) != std::string_view::npos) {
	    return false;
	}
    }
    return true;
}

auto Aoc15::isNice(std::string_view in) -> bool
{
    return containsAtLeast3Vowels(in) && containsOneLetterTwiceInRow(in) && doesntContainsTheStrings(in);
}

auto Aoc15::twoPairsOfTwoLetters(std::string_view in) -> bool
{
    if (in.size() < 2) {
        return false;
    }
    auto top = in.size() - 2;
    for(auto i = 1U; i < top; ++i) {
        if (in.substr(i + 1).find(in.substr(i - 1, 2)) != std::string_view::npos) {
	        return true;
	    }
    }
    return false;
}

auto Aoc15::repeatedLetterWithLetterBetween(std::string_view in) -> bool
{
    for (size_t i = 2; i < in.size(); ++i) {
        if (in.at(i) == in.at(i - 2)) {
	    return true;
	}
    }
    return false;
}

auto Aoc15::isNice2(std::string_view in) -> bool
{
    return twoPairsOfTwoLetters(in) && repeatedLetterWithLetterBetween(in);
}
