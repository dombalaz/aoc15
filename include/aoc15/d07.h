#ifndef AOC15_D07_H
#define AOC15_D07_H

#include <map>
#include <string>

using Circuit = std::map<std::string, std::string>;

auto signalOnWire(const std::string &wire, Circuit &c) -> std::uint16_t;

#endif // AOC15_D07_H
