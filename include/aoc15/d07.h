#ifndef AOC15_D07_H
#define AOC15_D07_H

#include <map>
#include <string>

using Circuit = std::map<std::string, std::string>;

std::uint16_t signalOnWire(const std::string &wire, Circuit &c);

#endif // AOC15_D07_H
