#include <aoc15/d12.h>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace Aoc15
{
auto sumNumbersInJson(const nlohmann::json &in) -> std::uint64_t;

auto sumNumbersInJson2(const nlohmann::json &in) -> std::uint64_t;
}

auto Aoc15::solveD12P1(std::string_view in) -> std::uint64_t
{
    return sumNumbersInJson(json::parse(in));
}

auto Aoc15::solveD12P2(std::string_view in) -> std::uint64_t
{
    return sumNumbersInJson2(json::parse(in));
}

auto Aoc15::sumNumbersInJson(const json &in) -> std::uint64_t
{
    auto r = 0U;
    for (const auto &i : in) {
        if (i.is_array() || i.is_object()) {
            r += sumNumbersInJson(i);
        } else if (i.is_number()) {
            r += i.get<std::uint64_t>();
        }
    }
    return r;
}

auto Aoc15::sumNumbersInJson2(const json &in) -> std::uint64_t
{
    auto r = 0U;
    for (const auto &i : in) {
        if (i.is_array() || i.is_object()) {
            r += sumNumbersInJson2(i);
        } else if (i.is_number()) {
            r += i.get<std::uint64_t>();
        } else if (i.is_string() && i.get<std::string>() == "red" && in.is_object()) {
            return 0U;
        }
    }
    return r;
}
