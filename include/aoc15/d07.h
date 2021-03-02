#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace Aoc15
{
using Circuit = std::map<std::string, std::string>;

constexpr auto wire{"a"};

constexpr auto overrideWire{"b"};

auto solveD7P1(const std::vector<std::string> &in) -> std::uint16_t;

auto solveD7P2(const std::vector<std::string> &in) -> std::uint16_t;

auto createCircuit(const std::vector<std::string> &in) -> Circuit;

auto signalOnWire(const std::string &wire, Circuit &c) -> std::uint16_t;
}
