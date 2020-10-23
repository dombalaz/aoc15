#ifndef AOC15_D12_H
#define AOC15_D12_H

#include <string>

#include <nlohmann/json_fwd.hpp>

auto sumNumbersInJson(const std::string &in) -> std::uint64_t;

auto sumNumbersInJson(const nlohmann::json &in) -> std::uint64_t;

auto sumNumbersInJson2(const std::string &in) -> std::uint64_t;

auto sumNumbersInJson2(const nlohmann::json &in) -> std::uint64_t;

#endif // AOC15_D12_H
