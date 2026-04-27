#include "algorithms.hpp"

#include <stdexcept>

Matrix multiplyParMatrixMult(const Matrix& a, const Matrix& b, int threads) {
    if (!sameDimensions(a, b)) {
        throw std::invalid_argument("matrices must have the same dimensions");
    }
    if (threads <= 0) {
        throw std::invalid_argument("threads must be positive");
    }

    const std::size_t n = a.size();
    Matrix c(n);

#ifdef _OPENMP
#pragma omp parallel for collapse(2) schedule(static) num_threads(threads)
#endif
    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = 0; j < n; ++j) {
            long sum = 0;
            for (std::size_t k = 0; k < n; ++k) {
                sum += a(i, k) * b(k, j);
            }
            c(i, j) = sum;
        }
    }

    return c;
}
