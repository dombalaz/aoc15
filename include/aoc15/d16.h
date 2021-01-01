#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

using uint = std::uint32_t;

/**
 * I use map with pair of values. Thepair contains number and compare function.
 * The compare function was introduced because of the second task.
 * I was then able to use same algorithm to get result, it just uses different
 * compare functions (like std::less).
 *
 * This is also place for improvement, because also input for aunts contains
 * these functions but it doesn't have to.
 */
using MfcsamCompounds = std::unordered_map<std::string, std::pair<uint, std::function<bool(uint, uint)>>>;

const MfcsamCompounds sample{
    {"children", {3, std::equal_to()}},
    {"cats", {7, std::equal_to()}},
    {"samoyeds", {2, std::equal_to()}},
    {"pomeranians", {3, std::equal_to()}},
    {"akitas", {0, std::equal_to()}},
    {"vizslas", {0, std::equal_to()}},
    {"goldfish", {5, std::equal_to()}},
    {"trees", {3, std::equal_to()}},
    {"cars", {2, std::equal_to()}},
    {"perfumes", {1, std::equal_to()}}
};

const MfcsamCompounds sample2{
    {"children", {3, std::equal_to()}},
    {"cats", {7, std::less()}},
    {"samoyeds", {2, std::equal_to()}},
    {"pomeranians", {3, std::greater()}},
    {"akitas", {0, std::equal_to()}},
    {"vizslas", {0, std::equal_to()}},
    {"goldfish", {5, std::greater()}},
    {"trees", {3, std::less()}},
    {"cars", {2, std::equal_to()}},
    {"perfumes", {1, std::equal_to()}}
};

auto createMfcsamCompoundsSample(const std::string &in) -> MfcsamCompounds;

auto createMfcsamCompoundsSamples(const std::vector<std::string> &in) -> std::vector<MfcsamCompounds>;

auto auntNumber(const MfcsamCompounds &sample, const std::vector<MfcsamCompounds> &aunts) -> size_t;