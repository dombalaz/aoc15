#include <aoc15/d16.h>

#include <regex>

namespace Aoc15
{
std::regex regex{"([a-z]+): ([0-9]+)*"};

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

auto solveD16P1(const std::vector<std::string>& in) -> std::int64_t
{
    auto samples{createMfcsamCompoundsSamples(in)};
    return auntNumber(sample, samples) + 1;
}

auto solveD16P2(const std::vector<std::string>& in) -> std::int64_t
{
    auto samples{createMfcsamCompoundsSamples(in)};
    return auntNumber(sample2, samples) + 1;
}

auto createMfcsamCompoundsSample(const std::string &in) -> MfcsamCompounds
{
    MfcsamCompounds r;
    for (auto it{std::sregex_iterator(in.begin(), in.end(), regex)}; it != std::sregex_iterator(); ++it) {
        std::smatch match = *it;
        r[match[1]] = {std::stoul(match[2]), std::equal_to()};
    }
    return r;
}

auto createMfcsamCompoundsSamples(const std::vector<std::string> &in) -> std::vector<MfcsamCompounds>
{
    std::vector<MfcsamCompounds> r;
    r.reserve(in.size());
    std::transform(in.begin(), in.end(), std::back_inserter(r), [](const auto &v) { return createMfcsamCompoundsSample(v); });
    return r;
}

auto auntNumber(const MfcsamCompounds &sample, const std::vector<MfcsamCompounds> &aunts) -> size_t
{
    for (auto i{0U}; i < aunts.size(); ++i) {
        const auto &aunt{aunts[i]};

        bool found{true};
        for (const auto &[k, v] : aunt) {
            if (!sample.at(k).second(sample.at(k).first,  v.first)) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }

    return aunts.size();
}
} // namespace Aoc15