#include "raindrops.h"
#include <string>

namespace raindrops {

// is divisible by 3, add "Pling" to the result.
// is divisible by 5, add "Plang" to the result.
// is divisible by 7, add "Plong" to the result.
// is not divisible by 3, 5, or 7, the result should be the number as a string.

std::string convert(int x) {

    std::string result{};

    if ( x % 3 == 0) result.append("Pling");
    if ( x % 5 == 0) result.append("Plang");
    if ( x % 7 == 0) result.append("Plong");

    if (result != "") return result;

    return std::to_string(x);

}


}  // namespace raindrops
