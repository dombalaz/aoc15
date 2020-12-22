#pragma once

#include <map>
#include <string>

using Circuit = std::map<std::string, std::string>;

auto signalOnWire(const std::string &wire, Circuit &c) -> std::uint16_t;
