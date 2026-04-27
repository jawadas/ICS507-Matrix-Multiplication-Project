#pragma once

#include <cstddef>
#include <vector>

class Matrix {
public:
    Matrix() = default;
    explicit Matrix(std::size_t dimension, long initialValue = 0);

    std::size_t size() const;
    bool empty() const;

    long& operator()(std::size_t row, std::size_t column);
    long operator()(std::size_t row, std::size_t column) const;

    const std::vector<long>& values() const;
    std::vector<long>& values();

private:
    std::size_t dimension_ = 0;
    std::vector<long> values_;
};

bool sameDimensions(const Matrix& left, const Matrix& right);
bool matricesEqual(const Matrix& left, const Matrix& right);
bool isPowerOfTwo(std::size_t value);
