#pragma once

#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Aoc15
{
/**
 * I use map with pair of values. Thepair contains number and compare function.
 * The compare function was introduced because of the second task.
 * I was then able to use same algorithm to get result, it just uses different
 * compare functions (like std::less).
 *
 * This is also place for improvement, because also input for aunts contains
 * these functions but it doesn't have to.
 */
using MfcsamCompounds = std::unordered_map<std::string, std::pair<std::uint32_t, std::function<bool(std::uint32_t, std::uint32_t)>>>;

auto solveD16P1(const std::vector<std::string>& in) -> std::int64_t;

auto solveD16P2(const std::vector<std::string>& in) -> std::int64_t;

auto createMfcsamCompoundsSample(const std::string &in) -> MfcsamCompounds;

auto createMfcsamCompoundsSamples(const std::vector<std::string> &in) -> std::vector<MfcsamCompounds>;

auto auntNumber(const MfcsamCompounds &sample, const std::vector<MfcsamCompounds> &aunts) -> size_t;
} // namespace Aoc15