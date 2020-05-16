#include <aoc15/d02.h>

uint paperForGift(uint x, uint y, uint z)
{
    return 2 * (x * y + x * z + y * z) + areaOfSmallest(x, y, z);
}

uint areaOfSmallest(uint x, uint y, uint z)
{
    uint a = x * y;
    uint b = x * z;
    uint c = y * z;

    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}
