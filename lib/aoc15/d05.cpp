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
    for(auto i = 1; i < in.size(); ++i) {
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
