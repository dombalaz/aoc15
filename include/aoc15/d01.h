#ifndef AOC15_D01_H
#define AOC15_D01_H

#include <string>

/*
 * Get floor that Santa was taken to.
 */
int getFloor(const std::string &in);


/*
 * Get index of character that causes Santa to first enter basement.
 * 
 * If basement is not reached, returns -1.
 */
int getIndexOfFirstBasement(const std::string &in);

#endif // AOC15_D01_H

