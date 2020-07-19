#ifndef AOC15_D09_H
#define AOC15_D09_H

#include <string>
#include <vector>

class CityDistance
{
public:
    CityDistance(std::string one, std::string two, size_t distance);

    const std::string &one() const;

    const std::string &two() const;

    size_t distance() const;
private:
    std::string m_one;
    std::string m_two;
    size_t m_distance{0};
};

//bool operator==(const CityDistance &lhs, const CityDistance &rhs);

size_t shortestDistance(const std::vector<std::string> &v);

#endif // AOC15_D09_H
