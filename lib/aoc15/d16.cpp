#include <aoc15/d16.h>

#include <regex>

std::regex regex{"([a-z]+): ([0-9]+)*"};

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