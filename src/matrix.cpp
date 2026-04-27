#include "matrix.hpp"

#include <stdexcept>

Matrix::Matrix(std::size_t dimension, long initialValue)
    : dimension_(dimension),
      values_(dimension * dimension, initialValue) {}

std::size_t Matrix::size() const {
    return dimension_;
}

bool Matrix::empty() const {
    return dimension_ == 0;
}

long& Matrix::operator()(std::size_t row, std::size_t column) {
    if (row >= dimension_ || column >= dimension_) {
        throw std::out_of_range("matrix index out of range");
    }
    return values_[row * dimension_ + column];
}

long Matrix::operator()(std::size_t row, std::size_t column) const {
    if (row >= dimension_ || column >= dimension_) {
        throw std::out_of_range("matrix index out of range");
    }
    return values_[row * dimension_ + column];
}

const std::vector<long>& Matrix::values() const {
    return values_;
}

std::vector<long>& Matrix::values() {
    return values_;
}

bool sameDimensions(const Matrix& left, const Matrix& right) {
    return left.size() == right.size();
}

bool matricesEqual(const Matrix& left, const Matrix& right) {
    return sameDimensions(left, right) && left.values() == right.values();
}

bool isPowerOfTwo(std::size_t value) {
    return value != 0 && (value & (value - 1)) == 0;
}
