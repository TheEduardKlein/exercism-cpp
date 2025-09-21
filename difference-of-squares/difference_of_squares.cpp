#include "difference_of_squares.h"
#include <cmath>

namespace difference_of_squares {

    int square_of_sum(int x) {
        
        int sum{};

        for (int i{1}; i <= x; ++i) 
            sum += i;

        return std::pow(sum, 2);
    }

    int sum_of_squares(int y) {

        int result{};

        for (int i{1}; i<= y; ++i)
            result += std::pow(i, 2);

        return result;
    }
    
    int difference(int z) {
        return square_of_sum(z) - sum_of_squares(z);
    }   

}  // namespace difference_of_squares
