#include <aoc15/d05.h>

#include <algorithm>

auto containsAtLeast3Vowels(const std::string &in) -> bool
{
    const std::string vowels{"aeiou"};
    auto count{0};
    for (const char &c : in) {
	if (vowels.find(c) != std::string::npos) {
	    ++count;
	}
    	if (count == 3) {
	    return true;
	}
    }
    return false;
}

auto containsOneLetterTwiceInRow(const std::string &in) -> bool
{
    for(size_t i = 1; i < in.size(); ++i) {
        if(in.at(i - 1) == in.at(i)) {
	    return true;
	}
    }
    return false;
}

auto doesntContainsTheStrings(const std::string &in) -> bool
{
    const std::vector<std::string> strings{"ab", "cd", "pq", "xy"};
    for (const auto &s : strings) {
        if (in.find(s) != std::string::npos) {
	    return false;
	}
    }
    return true;
}

auto isNice(const std::string &in) -> bool
{
    return containsAtLeast3Vowels(in) && containsOneLetterTwiceInRow(in) && doesntContainsTheStrings(in);
}

auto twoPairsOfTwoLetters(const std::string &in) -> bool
{
    if (in.size() < 2) {
        return false;
    }
    auto top = in.size() - 2;
    for(auto i = 1U; i < top; ++i) {
        if (in.substr(i + 1).find(in.substr(i - 1, 2)) != std::string::npos) {
	    return true;
	}
    }
    return false;
}

auto repeatedLetterWithLetterBetween(const std::string &in) -> bool
{
    for (size_t i = 2; i < in.size(); ++i) {
        if (in.at(i) == in.at(i - 2)) {
	    return true;
	}
    }
    return false;
}

auto isNice2(const std::string &in) -> bool
{
    return twoPairsOfTwoLetters(in) && repeatedLetterWithLetterBetween(in);
}
