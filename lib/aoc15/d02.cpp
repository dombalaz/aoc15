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

    if (a < b && a < c) {
        return a;
    } else if (b < c && b < a) {
        return b;
    } else {
        return c;
    }
}
