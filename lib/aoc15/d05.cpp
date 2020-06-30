#include <aoc15/d05.h>

#include <algorithm>

bool containsAtLeast3Vowels(const std::string &in)
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

bool containsOneLetterTwiceInRow(const std::string &in)
{
    for(size_t i = 1; i < in.size(); ++i) {
        if(in.at(i - 1) == in.at(i)) {
	    return true;
	}
    }
    return false;
}

bool doesntContainsTheStrings(const std::string &in)
{
    const std::vector<std::string> strings{"ab", "cd", "pq", "xy"};
    for (const auto &s : strings) {
        if (in.find(s) != std::string::npos) {
	    return false;
	}
    }
    return true;
}

bool isNice(const std::string &in)
{
    return containsAtLeast3Vowels(in) && containsOneLetterTwiceInRow(in) && doesntContainsTheStrings(in);
}

bool twoPairsOfTwoLetters(const std::string &in)
{
    int top = in.size() - 2;
    for(int i = 1; i < top; ++i) {
        if (in.substr(i + 1).find(in.substr(i - 1, 2)) != std::string::npos) {
	    return true;
	}
    }
    return false;
}

bool repeatedLetterWithLetterBetween(const std::string &in)
{
    for (size_t i = 2; i < in.size(); ++i) {
        if (in.at(i) == in.at(i - 2)) {
	    return true;
	}
    }
    return false;
}

bool isNice2(const std::string &in)
{
    return twoPairsOfTwoLetters(in) && repeatedLetterWithLetterBetween(in);
}
