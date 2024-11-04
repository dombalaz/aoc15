#include <aoc15/d19.h>
#include <exception>
#include <stack>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>
#include <iostream>

namespace Aoc15
{

auto createReplacements(const std::vector<std::string>& in) -> ReplacementsT
{
    ReplacementsT r;
    for (const auto& s : in) {
        std::string from = s.substr(0, s.find(' '));
        std::string to = s.substr(s.find_last_of(' ') + 1);
        r[from].push_back(to);
    }
    return r;
}

auto generateDistinctMolecules(const ReplacementsT& replacements, std::string_view in) -> std::unordered_set<std::string>
{
    std::unordered_set<std::string> createdMolecules;
    for (auto i{0U}; i < in.size(); ++i) {
        for (const auto& replacement : replacements) {
            if (!in.substr(i).starts_with(replacement.first)) {
                continue;
            }
            auto start{std::string(in.substr(0, i))};
            auto end{std::string(in.substr(i + replacement.first.size()))};
            for (const auto& replace : replacement.second) {
                createdMolecules.insert(start + replace + end);
            }
        }
    }
    return createdMolecules;
}

auto countDistinctMolecules(const ReplacementsT& replacements, std::string_view in) -> int
{
    return generateDistinctMolecules(replacements, in).size();
}

auto dfsMolecules(const ReplacementsT& replacements, std::string_view in, std::string_view target, int count) -> int
{
    if (in.size() > target.size()) {
        return 0;
    }
    for (auto i{0U}; i < in.size(); ++i) {
        for (const auto& replacement : replacements) {
            if (!in.substr(i).starts_with(replacement.first)) {
                continue;
            }
            auto start{std::string(in.substr(0, i))};
            auto end{std::string(in.substr(i + replacement.first.size()))};
            for (const auto& replace : replacement.second) {
                std::string s = start + replace + end;
                if (s == target) {
                    return count;
                }
                auto dfs = dfsMolecules(replacements, start + replace + end, target, count + 1);
                if (dfs != 0) { 
                    return dfs;
                }
            }
        }
    }
    return 0;
}

auto countMoleculesGenerations(const ReplacementsT& replacements, const std::string& in) -> int
{
    auto newReplacements = replacements;
    int count{};
    std::string tmp = in;
    std::string newTmp = tmp;
    std::stack<std::string> stack;
    stack.push(newTmp);
    int replacementxount{};
    while (tmp != "e") {
        bool stopFlag{};
        int replacementLiveCount{};
        for (size_t i{}; i < tmp.size(); ++i) {
            for (const auto& replacement : replacements) {
                for (const auto& replacement2 : replacement.second) {
                    std::cout << "DEBG: " << tmp << "-" << replacement2 << '-' << i << '\n';
                    if (!tmp.substr(i).starts_with(replacement2)) {
                        continue;
                    }
                    if (replacementLiveCount < replacementxount) {
                        ++replacementLiveCount;
                        continue;
                    }
                    ++replacementxount;
                    auto start{std::string(tmp.substr(0, i))};
                    auto end{std::string(tmp.substr(i + replacement2.size()))};
                    newTmp = start + replacement.first + end;
                    if (replacement.first == "e" && newTmp != "e") {
                        newTmp = tmp;
                        continue;
                    }
                    stack.push(newTmp);
                    std::cout << "start: '" << start << "' rep: '" << replacement.first << "' end: '" << end << "'\n";
                    std::cout << "old str:" << tmp << ", newTmp:" << newTmp << ", count: " << count << '\n';
                    stopFlag = true;
                    ++count;
                    break;
                }
                if (stopFlag) {
                    break;
                }
            }
            if (stopFlag) { 
                break;
            }
        }
        stopFlag = false;
        if (newTmp == tmp) {
            stack.pop();
            tmp = stack.top();
            newTmp = stack.top();
            ++replacementxount;
            continue;
        }
        tmp = newTmp;
    }

    return count;


    /*
    std::unordered_set<std::string> molecules{"e"};
    auto count = 1;
    return dfsMolecules(replacements, "e", in, 1);

    while (true) {
        std::unordered_set<std::string> tmp;
        for (const auto& molecule : molecules) {
            auto tmp2 = generateDistinctMolecules(replacements, molecule);
            tmp.insert(tmp2.begin(), tmp2.end());
        }
        if (tmp.contains(in)) {
            return count;
        }
        ++count;
        //std::cout << count << ":" << tmp.begin()->size() << '\n';
        molecules = std::move(tmp);
    }
    return 0;
    */
}

auto solveD19P1(const std::vector<std::string>& in) -> int
{
    auto tmp{in};
    std::string s = tmp.back();
    tmp.pop_back();
    tmp.pop_back();
    auto rep{createReplacements(tmp)};
    return countDistinctMolecules(rep, s);
}

auto solveD19P2(const std::vector<std::string>& in) -> int
{
    auto tmp{in};
    std::string s = tmp.back();
    tmp.pop_back();
    tmp.pop_back();
    //std::cout << "size:" << s.size() << '\n';
    auto rep{createReplacements(tmp)};
    return countMoleculesGenerations(rep, s);
}

} // namespace Aoc15