#include "trinary.h"
#include <cmath>

namespace trinary {

int to_decimal(std::string s) {

    int result{};
    int count{};

    for (auto i = s.rbegin(); i != s.rend(); ++i) {
        
        if ( !std::isdigit(*i) ) return 0;

        result += (*i - '0') * std::pow(3, count);
        ++count;
    }
    return result;
}

}  // namespace trinary
