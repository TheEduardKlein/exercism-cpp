#include "atbash_cipher.h"
#include <iostream>
#include <cctype>

namespace atbash_cipher {

    char shift(char c) {

        if (std::isdigit(c)) return c;
        if (std::isupper(c))
            c = std::tolower(c);

        int cur_index = c - 'a'; // indexes a-z 0-25
        int new_index = (25 - cur_index); 

        return new_index + 'a';
    }


    std::string encode(std::string s) {

        std::string encryption{""};
        int count{1};
        for (char c : s) {
            if (c == ' ' || c == '!' || c == '.' || c == ',') continue;
            encryption.push_back(shift(c));
            if (count % 5 == 0) encryption.push_back(' ');
            ++count;
        }

        if (encryption.back() == ' ') encryption.pop_back();
        return encryption;
    }


    std::string decode(std::string s) {
        std::string decryption{""};
        for (char c : s) {
            if (c == ' ') continue;
            decryption.push_back(shift(c));
        }
        return decryption;
    }
}  // namespace atbash_cipher
