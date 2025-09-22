#pragma once
#include <string>

namespace atbash_cipher {

    
    char shift(char c);

    std::string encode(std::string s);

    std::string decode(std::string s);

}  // namespace atbash_cipher
