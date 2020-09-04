#include <aoc15/d04.h>
#include <climits>
#include <iomanip>
#include <openssl/md5.h>
#include <vector>

auto miningNumber(const std::string &key, size_t leadingZeroes) -> int
{
    std::array<unsigned char, MD5_DIGEST_LENGTH> out{};
    for(auto i = 0; i < INT_MAX; ++i) {
        auto tmp{key + std::to_string(i)};
        std::basic_string<unsigned char> in(tmp.begin(), tmp.end());
        MD5(in.data(), in.size(), out.data());

        std::stringstream ss;
        for(unsigned char j : out) {
            ss << std::setfill('0') << std::setw(2) << std::hex;
            ss << static_cast<size_t>(j);
        }
        auto cmpstr{ss.str().substr(0, leadingZeroes)};
        if(cmpstr == std::string(leadingZeroes, '0')) {
            return i;
        }
    }

    return -1;
}
