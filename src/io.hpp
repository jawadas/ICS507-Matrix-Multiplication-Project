#pragma once

#include "matrix.hpp"

#include <filesystem>
#include <string>

struct MatrixInput {
    std::filesystem::path path;
    std::string stem;
    Matrix a;
    Matrix b;
};

MatrixInput readInputFile(const std::filesystem::path& inputPath);

std::filesystem::path makeOutputPath(
    const std::filesystem::path& outputDirectory,
    const std::string& inputStem,
    std::size_t dimension,
    const std::string& kind,
    const std::string& method);

void writeMatrixFile(
    const std::filesystem::path& outputDirectory,
    const std::string& inputStem,
    const std::string& method,
    const Matrix& matrix);

void writeInfoFile(
    const std::filesystem::path& outputDirectory,
    const std::string& inputStem,
    std::size_t dimension,
    const std::string& method,
    const std::string& formattedTime,
    int coresUsed);
