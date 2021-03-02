#include <aoc15/d14.h>

#include <regex>
#include <unordered_map>

namespace Aoc15
{
Reindeer::Reindeer(std::string name, std::uint64_t speed, std::uint64_t moveTime, std::uint64_t restTime) :
    m_name{std::move(name)}, m_speed{speed}, m_moveTime{moveTime}, m_restTime{restTime}
{}

auto Reindeer::name() const -> const std::string &
{
    return m_name;
}

auto Reindeer::speed() const -> std::uint64_t
{
    return m_speed;
}

auto Reindeer::moveTime() const -> std::uint64_t
{
    return m_moveTime;
}

auto Reindeer::restTime() const -> std::uint64_t
{
    return m_restTime;
}

auto operator==(const Reindeer &l, const Reindeer &r) -> bool
{
    return l.name() == r.name()
        && l.speed() == r.speed()
        && l.moveTime() == r.moveTime()
        && l.restTime() == r.restTime();
}

auto operator!=(const Reindeer &l, const Reindeer &r) -> bool
{
    return !(l == r);
}

auto solveD14P1(const std::vector<std::string>& in) -> std::int64_t
{
    auto v = createReindeers(in);
    constexpr auto time{2503U};
    return winningDistance(v, time);
}

auto solveD14P2(const std::vector<std::string>& in) -> std::int64_t
{
    auto v = createReindeers(in);
    constexpr auto time{2503U};
    return winningPoints(v, time);
}

auto createReindeers(const std::vector<std::string> &v) -> std::vector<Reindeer>
{
    std::regex rx{"([a-zA-Z]+) can fly ([0-9]+) km/s for ([0-9]+) seconds, but then must rest for ([0-9]+) seconds."};
    std::smatch match;
    std::vector<Reindeer> r;
    for (const auto &s : v) {
        std::regex_match(s, match, rx);
        r.emplace_back(match[1], std::stoul(match[2]), std::stoul(match[3]), std::stoul(match[4]));
    }
    return r;
}

auto winningDistance(const std::vector<Reindeer> &v, std::uint64_t s) -> std::uint64_t
{
    auto r{0U};
    for (const auto &i : v) {
        auto t{0U};
        auto c{s / (i.moveTime() + i.restTime())};
        if (c != 0) {
            t += c * i.moveTime() * i.speed();
        }
        c = s % (i.moveTime() + i.restTime());
        if (c != 0) {
            t += (i.moveTime() > c ? c : i.moveTime()) * i.speed();
        }
        if (r < t) {
            r = t;
        }
    }
    return r;
}

auto winningPoints(const std::vector<Reindeer> &v, std::uint64_t s) -> std::uint64_t
{
    if (v.empty()) {
        return {};
    }
    std::unordered_map<std::string, std::uint64_t> reindeersPoints;
    for (const auto &i : v) {
        reindeersPoints.emplace(i.name(), 0U);
    }
    std::unordered_map<std::string, std::uint64_t> reindeersRoundDistance = reindeersPoints;
    for (auto i = 1U; i <= s; ++i) {
        for (const auto &reindeer : v) {
            reindeersRoundDistance.at(reindeer.name()) = winningDistance({reindeer}, i);
        }

        auto maxDistance{(*std::max_element(reindeersRoundDistance.begin(), reindeersRoundDistance.end(), [](const auto &l, const auto &r) { return l.second < r.second; })).second};

        for (const auto &kv : reindeersRoundDistance) {
            if (maxDistance == kv.second) {
                ++reindeersPoints.at(kv.first);
            }
        }
    }

    return (*std::max_element(reindeersPoints.begin(), reindeersPoints.end(), [](const auto &l, const auto &r) { return l.second < r.second; })).second;
}
} // namespace Aoc15