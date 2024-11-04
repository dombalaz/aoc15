#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>

namespace Aoc15
{

using ReplacementsT = std::unordered_map<std::string, std::vector<std::string>>;

auto createReplacements(const std::vector<std::string>& in) -> ReplacementsT;

auto countDistinctMolecules(const ReplacementsT& replacements, std::string_view in) -> int;

auto countMoleculesGenerations(const ReplacementsT& replacements, const std::string& in) -> int;

auto solveD19P1(const std::vector<std::string>& in) -> int;

auto solveD19P2(const std::vector<std::string>& in) -> int;

} // namespace Aoc15