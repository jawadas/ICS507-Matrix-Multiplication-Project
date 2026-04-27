#include "algorithms.hpp"

#include <stdexcept>

Matrix multiplyParStrassen(const Matrix& a, const Matrix& b, int baseCase, int threads) {
    if (!sameDimensions(a, b)) {
        throw std::invalid_argument("matrices must have the same dimensions");
    }
    if (baseCase <= 0) {
        throw std::invalid_argument("base case must be positive");
    }
    if (threads <= 0) {
        throw std::invalid_argument("threads must be positive");
    }

    // Contributor 2: replace this baseline call with OpenMP task-based Strassen recursion.
    return multiplySequential(a, b);
}
