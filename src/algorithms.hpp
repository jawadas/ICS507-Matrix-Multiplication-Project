#pragma once

#include "matrix.hpp"

Matrix multiplySequential(const Matrix& a, const Matrix& b);
Matrix multiplyParMatrixMult(const Matrix& a, const Matrix& b, int threads);
Matrix multiplyStrassen(const Matrix& a, const Matrix& b, int baseCase);
Matrix multiplyParStrassen(const Matrix& a, const Matrix& b, int baseCase, int threads);
