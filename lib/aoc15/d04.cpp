#include <aoc15/d04.h>

#include <array>
#include <climits>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <openssl/md5.h>

auto Aoc15::solveD4P1(std::string_view in) -> std::uint32_t
{
    return solveD4(in, D4P1Number);
}

auto Aoc15::solveD4P2(std::string_view in) -> std::uint32_t
{
    return solveD4(in, D4P2Number);
}

auto Aoc15::solveD4(std::string_view in, std::uint32_t leadingZeroes) -> std::uint32_t
{
    std::array<unsigned char, MD5_DIGEST_LENGTH> out{};
    for(auto i{0U}; i < UINT_MAX; ++i) {
        auto tmp{std::string(in) + std::to_string(i)};
        std::basic_string<unsigned char> in(tmp.begin(), tmp.end());
        MD5(in.data(), in.size(), out.data());

        std::stringstream ss;
        for(unsigned char j : out) {
            ss << std::setfill('0') << std::setw(2) << std::hex;
            ss << static_cast<std::uint32_t>(j);
        }

        auto cmpstr{ss.str().substr(0, leadingZeroes)};
        if(cmpstr == std::string(leadingZeroes, '0')) {
            return i;
        }
    }

    throw std::logic_error{"could not find collision"};
}
