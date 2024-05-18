#pragma once
#include <array>

//alias to handle custom size matrices and handle int and float 
template<typename T, size_t W>
using row_t = std::array<T, W>;

template<size_t W, size_t H, typename T>
using array_t =  std::array<row_t<T, W>, H>;


template <int W, int H, typename T> class Matrix {
private:
    array_t<W, H, T> data;

public:
    Matrix(const array_t<W, H, T>& input) : data(input) {}
    Matrix(){
        for(auto& row : data)
        {
            row.fill(0);
        }
    }

    void print() const {
        for (const auto& row : data) {
            for (T value : row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix add(const Matrix& other) const {
        if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
            std::cerr << "Matrices must have the same dimensions for addition." << std::endl;
            return *this;
        }
        array_t<W, H, T> result;
        for (size_t i = 0; i < data.size(); ++i) {
            row_t<T, W> row;
            for (size_t j = 0; j < data[i].size(); ++j) {
                row[j] = data[i][j] + other.data[i][j];
            }
            result[i] = row;
        }
        return Matrix(result);
    }

    // Multiply two matrices
    Matrix multiply(const Matrix& other) const {
        if (data[0].size() != other.data.size()) {
            std::cerr << "Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication." << std::endl;
            return *this;
        }
        array_t<W, H, T> result;
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < other.data[0].size(); ++j) {
                for (size_t k = 0; k < other.data.size(); ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return Matrix(result);
    }

    // Transpose the matrix
    Matrix transpose() const {
        array_t<W, H, T> result;
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                result[j][i] = data[i][j];
            }
        }
        return Matrix(result);
    }

    // Compute the inverse of a 2x2 matrix
    Matrix inverse2x2() const {
        if (data.size() != 2 || data[0].size() != 2) {
            std::cerr << "Inverse can only be computed for 2x2 matrices." << std::endl;
            return *this;
        }
        double det = data[0][0] * data[1][1] - data[0][1] * data[1][0];
        if (det == 0) {
            std::cerr << "Matrix is singular, cannot compute inverse." << std::endl;
            return *this;
        }
        double invDet = 1.0 / det;
        array_t<W, H, T> result;
        result[0][0] = data[1][1] * invDet;
        result[0][1] = -data[0][1] * invDet;
        result[1][0] = -data[1][0] * invDet;
        result[1][1] = data[0][0] * invDet;
        return Matrix(result);
    }
    Matrix inverse3x3() const {
        if (data.size() != 3 || data[0].size() != 3) {
            std::cerr << "Inverse can only be computed for 3x3 matrices." << std::endl;
            return *this;
        }
        double det = data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1])
                   - data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0])
                   + data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
        if (det == 0) {
            std::cerr << "Matrix is singular, cannot compute inverse." << std::endl;
            return *this;
        }
        double invDet = 1.0 / det;
        array_t<W, H, T> result;
        result[0][0] =  (data[1][1] * data[2][2] - data[1][2] * data[2][1]) * invDet;
        result[0][1] = -(data[0][1] * data[2][2] - data[0][2] * data[2][1]) * invDet;
        result[0][2] =  (data[0][1] * data[1][2] - data[0][2] * data[1][1]) * invDet;
        result[1][0] = -(data[1][0] * data[2][2] - data[1][2] * data[2][0]) * invDet;
        result[1][1] =  (data[0][0] * data[2][2] - data[0][2] * data[2][0]) * invDet;
        result[1][2] = -(data[0][0] * data[1][2] - data[0][2] * data[1][0]) * invDet;
        result[2][0] =  (data[1][0] * data[2][1] - data[1][1] * data[2][0]) * invDet;
        result[2][1] = -(data[0][0] * data[2][1] - data[0][1] * data[2][0]) * invDet;
        result[2][2] =  (data[0][0] * data[1][1] - data[0][1] * data[1][0]) * invDet;
        return Matrix(result);
    }
};

//template instantiation 
template class Matrix<2, 2, int>;
template class Matrix<3, 3, int>;
template class Matrix<2, 2, float>;
template class Matrix<3, 3, float>;

// aliases for quality of life
using Matrix2x2 = Matrix<2, 2, int>;
using Matrix3x3 = Matrix<3, 3, int>;
using fMatrix2x2 = Matrix<2, 2, float>;
using fMatrix3x3 = Matrix<3, 3, float>;
