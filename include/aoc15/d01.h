#ifndef AOC15_D01_H
#define AOC15_D01_H

#include <string>

/*
 * Get floor that Santa was taken to.
 */
auto getFloor(const std::string &in) -> int;


/*
 * Get index of character that causes Santa to first enter basement.
 * 
 * If basement is not reached, returns -1.
 */
auto getIndexOfFirstBasement(const std::string &in) -> int;

#endif // AOC15_D01_H

