cmake_minimum_required(VERSION 3.16)

project(ICSMatrixMultiplication LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenMP REQUIRED)

add_executable(matrix_mult
    src/main.cpp
    src/matrix.cpp
    src/io.cpp
    src/sequential.cpp
    src/par_matrix_mult.cpp
    src/strassen.cpp
    src/par_strassen.cpp
)

target_include_directories(matrix_mult PRIVATE src)

target_link_libraries(matrix_mult PRIVATE OpenMP::OpenMP_CXX)
