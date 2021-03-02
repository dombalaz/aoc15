#include <aoc15/d07.h>

#include <iostream>
#include <regex>


auto Aoc15::solveD7P1(const std::vector<std::string> &in) -> std::uint16_t
{
    auto c{createCircuit(in)};
    return signalOnWire(wire, c);
}

auto Aoc15::solveD7P2(const std::vector<std::string> &in) -> std::uint16_t
{
    auto c{createCircuit(in)};
    auto c2{c};
    auto signal{signalOnWire(wire, c)};
    c2[overrideWire] = std::to_string(signal);
    return signalOnWire(wire, c2);
}

auto Aoc15::createCircuit(const std::vector<std::string> &in) -> Circuit
{
    std::regex regex("([a-z0-9A-Z ]*) -> ([a-z]*)");
    std::smatch match;
    Circuit c;
    for (const auto &s : in) {
        std::regex_match(s, match, regex);
        c.insert({match[2], match[1]});
    }
    return c;
}

auto Aoc15::signalOnWire(const std::string &wire, Circuit &c) -> std::uint16_t
{
    // Wire can be number so it is not present in map and therefore return it.
    if (c.find(wire) == c.end()) {
        return std::stoul(wire);
    }

    std::smatch match;
    std::regex reg{"([0-9]*|[a-z]*)[ ]?(AND|OR|LSHIFT|RSHIFT|NOT) ([0-9]+|[a-z]+)|[0-9]+|[a-z]+"};
    std::regex_match(c[wire], match, reg);
    std::uint16_t res{};

    if(match[2] == "AND") {
        res = signalOnWire(match[1], c) & signalOnWire(match[3], c);
    } else if (match[2] == "OR") {
        res = signalOnWire(match[1], c) | signalOnWire(match[3], c);
    } else if (match[2] == "LSHIFT") {
        res = signalOnWire(match[1], c) << std::stoul(match[3]);
    } else if (match[2] == "RSHIFT") {
        res = signalOnWire(match[1], c) >> std::stoul(match[3]);
    } else if (match[2] == "NOT") {
        res = ~signalOnWire(match[3], c);
    } else {
        try {
            res = std::stoul(match[0]);
        } catch(const std::invalid_argument &ex) {
            res = signalOnWire(match[0], c);
        }
    }

    c[wire] = std::to_string(res);

    return res;
}
