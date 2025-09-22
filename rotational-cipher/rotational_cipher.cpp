#include "rotational_cipher.h"
#include <cctype>

namespace rotational_cipher {

std::string rotate(std::string s, int k) {

    for (char& c : s) 
        shift(c, k);

    return s;
}

//only shift if the character is alphabetical, choose upper or lower
void shift (char& c, int k) {
    
    if (std::isalpha(c)) {
        if (std::islower(c)) 
            c = (c - 'a' + k) % 26 + 'a';
        if (std::isupper(c))
            c = (c - 'A' + k) % 26 + 'A';
    }
    return;
}

}  // namespace rotational_cipher
