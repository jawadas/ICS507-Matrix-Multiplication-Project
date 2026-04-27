#include "algorithms.hpp"

#include <stdexcept>

Matrix multiplyStrassen(const Matrix& a, const Matrix& b, int baseCase) {
    if (!sameDimensions(a, b)) {
        throw std::invalid_argument("matrices must have the same dimensions");
    }
    if (baseCase <= 0) {
        throw std::invalid_argument("base case must be positive");
    }

    // Contributor 2: replace this baseline call with sequential Strassen recursion.
    return multiplySequential(a, b);
}
