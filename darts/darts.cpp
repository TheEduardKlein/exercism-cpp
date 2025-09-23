#include "darts.h"
#include <cmath>

namespace darts {

int score (double x, double y) {

    double r = std::hypot(x, y);

    if (r > 10) return 0;
    if (r > 5) return 1;
    if (r > 1) return 5;
    return 10;

}

}  // namespace darts
