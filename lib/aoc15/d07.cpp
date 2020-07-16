#include <aoc15/d07.h>

#include <regex>
#include <iostream>

const std::regex regex("([0-9]*|[a-z]*)[ ]?(AND|OR|LSHIFT|RSHIFT|NOT) ([0-9]+|[a-z]+)|[0-9]+|[a-z]+");

std::uint16_t signalOnWire(const std::string &wire, Circuit &c)
{
    // Wire can be number so it is not present in map and therefore return it.
    if (c.find(wire) == c.end()) {
        return std::stoul(wire);
    }

    std::smatch match;
    std::regex_match(c[wire], match, regex);
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
