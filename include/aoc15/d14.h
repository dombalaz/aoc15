#pragma once

#include <string>
#include <vector>

class Reindeer
{
public:
    Reindeer() = default;

    Reindeer(std::string name, std::uint64_t speed, std::uint64_t moveTime, std::uint64_t restTime);

    [[nodiscard]] auto name() const -> const std::string &;

    [[nodiscard]] auto speed() const -> std::uint64_t;

    [[nodiscard]] auto moveTime() const -> std::uint64_t;

    [[nodiscard]] auto restTime() const -> std::uint64_t;
private:
    std::string m_name;
    std::uint64_t m_speed{};
    std::uint64_t m_moveTime{};
    std::uint64_t m_restTime{};
};

auto operator==(const Reindeer &l, const Reindeer &r) -> bool;

auto operator!=(const Reindeer &l, const Reindeer &r) -> bool;

auto createReindeers(const std::vector<std::string> &v) -> std::vector<Reindeer>;

auto winningDistance(const std::vector<Reindeer> &v, std::uint64_t s) -> std::uint64_t;

auto winningPoints(const std::vector<Reindeer> &v, std::uint64_t s) -> std::uint64_t;
