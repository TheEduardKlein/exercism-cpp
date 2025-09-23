#include "luhn.h"

#include <cctype>

namespace luhn {

bool valid (std::string s) {

    if (s.length() <= 1) return false;

    int count {1};
    int sum_all_digits{};
    
    for (auto i = s.rbegin(); i != s.rend(); ++i) {
        if (*i == ' ') continue;
        if (!std::isdigit(*i)) return false;
        if (count % 2 != 0) {
            sum_all_digits += *i - '0'; //* to c
            ++count;
            continue;
        }
        ++count;

        int num = *i - '0';
        int twice = num * 2;
        
        if (twice > 9) twice -= 9;
        
        sum_all_digits += twice;
    }
    
    if (count <= 2) return false;

    return (sum_all_digits % 10 == 0);

}

}  // namespace luhn
