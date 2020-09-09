#include <aoc15/d02.h>

#include <algorithm>

auto paperForGift(uint x, uint y, uint z) -> uint
{
    return 2 * (x * y + x * z + y * z) + areaOfSmallest(x, y, z);
}

auto areaOfSmallest(uint x, uint y, uint z) -> uint
{
    return std::min({x * y, x * z, y * z});
}

auto ribbonForGift(uint x, uint y, uint z) -> uint
{
    return 2 * (x + y + z - std::max({x, y, z})) + x * y * z;
}
