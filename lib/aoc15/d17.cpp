#include <aoc15/d17.h>

#include <algorithm>

auto combinationsToTopSum(const std::vector<std::string> &nums, uint sum) -> uint
{
    std::vector<uint> v;
    v.reserve(nums.size());
    std::transform(nums.begin(), nums.end(), std::back_inserter(v), [](const auto &v) { return std::stoul(v); });
    std::sort(v.begin(), v.end(), std::greater());
    return combinationsToTopSum(v, sum, v.size());
}

auto combinationsToTopSum(const std::vector<uint> &nums, uint sum, uint counter) -> uint
{
    if (nums.empty() || counter == 0) {
        return 0;
    }
    auto r{0U};
    for (auto it{nums.begin()}; it != nums.end(); ++it) {
        const auto &num{*it};
        if (num > sum) {
            continue;
        }
        if (num == sum) {
            ++r;
            continue;
        }
        r += combinationsToTopSum(std::vector<uint>{it + 1, nums.end()}, sum - num, counter - 1);
    }

    return r;
}

auto combinationsWithMinToTopSum(const std::vector<std::string> &nums, uint sum) -> uint
{
    std::vector<uint> v;
    v.reserve(nums.size());
    std::transform(nums.begin(), nums.end(), std::back_inserter(v), [](const auto &v) { return std::stoul(v); });
    std::sort(v.begin(), v.end(), std::greater());
    return combinationsWithMinToTopSum(v, sum);
}

auto combinationsWithMinToTopSum(const std::vector<uint> &nums, uint sum) -> uint
{
    auto r{0U};
    for (auto i{0U}; i < nums.size(); ++i) {
        r = combinationsToTopSum(nums, sum, i);
        if (r != 0) {
            break;
        }
    }
    return r;
}
