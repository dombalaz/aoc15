#include <aoc15/d04.h>
#include <openssl/md5.h>
#include <climits>
#include <iomanip>

int miningNumber(const std::string &key, size_t leadingZeroes)
{
    unsigned char out[MD5_DIGEST_LENGTH]{};
    for(auto i = 0; i < INT_MAX; ++i) {
        auto in{key + std::to_string(i)};
        MD5(reinterpret_cast<const unsigned char *>(in.c_str()), in.size(), out);

        std::stringstream ss;
        for(auto j = 0; j < MD5_DIGEST_LENGTH; ++j) {
            ss << std::setfill('0') << std::setw(2) << std::hex;
            ss << static_cast<size_t>(out[j]);
        }
        auto cmpstr{ss.str().substr(0, leadingZeroes)};
        if(cmpstr == std::string(leadingZeroes, '0')) {
            return i;
        }
    }

    return -1;
}
