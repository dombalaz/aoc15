#include <aoc15/d02.h>

#include <algorithm>

uint paperForGift(uint x, uint y, uint z)
{
    return 2 * (x * y + x * z + y * z) + areaOfSmallest(x, y, z);
}

uint areaOfSmallest(uint x, uint y, uint z)
{
    return std::min({x * y, x * z, y * z});
}

uint ribbonForGift(uint x, uint y, uint z)
{
    return 2 * (x + y + z - std::max({x, y, z})) + x * y * z;
}
