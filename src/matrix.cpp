//
// Created by fisibula on 28/07/21.
//

#include "matrix.h"

#include <iostream>
#include <iomanip>

Matrix::Matrix()
    : m_rows(0)
    , m_cols(0)
{}

Matrix::Matrix(const Matrix& mat)
    : m_rows(mat.m_rows)
    , m_cols(mat.m_cols)
    , m_data(mat.m_data)
{}

Matrix::Matrix(size_t rows, size_t cols, size_t channels)
    : m_rows(rows)
    , m_cols(cols)
    , m_channels(std::max(channels, 1UL))
    , m_data(rows * cols * channels)
{}

Matrix::Matrix(size_t rows, size_t cols, size_t channels, int initValue)
    : m_rows(rows)
    , m_cols(cols)
    , m_channels(std::max(channels, 1UL))
    , m_data(rows * cols * channels, initValue)
{}

void Matrix::print() const
{
    std::cout << *this << std::endl;
}

Matrix Matrix::add(int val) const
{
    Matrix res(m_rows, m_cols, m_cols, m_channels);
    add(res, val);
    return res;
}

Matrix Matrix::multiply(int val) const
{
    Matrix res(m_rows, m_cols, m_channels);
    multiply(res, val);
    return res;
}

Matrix Matrix::subtract(int val) const
{
    Matrix res(m_rows, m_cols, m_channels);
    subtract(res, val);
    return res;
}

Matrix Matrix::add(const Matrix& mat) const
{
    if (m_rows != mat.m_rows || m_cols != mat.m_cols)
        return Matrix();
    Matrix res(m_rows, m_cols, m_channels);
    for (size_t i = 0; i < m_data.size(); ++i) {
        res.m_data[i] = m_data[i] + mat.m_data[i];
    }
    return res;
}

Matrix Matrix::multiply(const Matrix &mat) const
{
    if (m_cols != mat.m_rows)
        return Matrix();
    Matrix res(m_rows, mat.m_cols,0);
    for (size_t r = 0; r < res.m_rows; ++r) {
        for (size_t c = 0; c < res.m_cols; ++c) {
            for (size_t m = 0; m < m_cols; ++m) {
                res.at(r, c) += at(r, m) * mat.at(m, c);
            }
        }
    }
    return res;
}

Matrix Matrix::subtract(const Matrix& mat) const
{
    if (m_rows != mat.m_rows || m_cols != mat.m_cols)
        return Matrix();
    Matrix res(m_rows, m_cols, m_channels);
    for (size_t i = 0; i < m_data.size(); ++i) {
        res.m_data[i] = m_data[i] - mat.m_data[i];
    }
    return res;
}

Matrix Matrix::operator+(const Matrix& mat) const
{
    return add(mat);
}
Matrix Matrix::operator+(int val) const
{
    return add(val);
}
Matrix Matrix::operator-(const Matrix& mat) const
{
    return subtract(mat);
}
Matrix Matrix::operator-(int val) const
{
    return subtract(val);
}
Matrix Matrix::operator*(const Matrix& mat) const
{
    return multiply(mat);
}
Matrix Matrix::operator*(int val) const
{
    return multiply(val);
}
Matrix& Matrix::operator=(const Matrix& mat)
{
    if (this != &mat) {
        m_rows = mat.m_rows;
        m_cols = mat.m_cols;
        m_channels = mat.m_channels;
        m_data.assign(mat.m_data.begin(), mat.m_data.end());
    }
    return *this;
}
std::ostream& operator<<(std::ostream& out, const Matrix& mat)
{
    for (size_t r = 0; r < mat.m_rows; ++r) {
        for (size_t c = 0; c < mat.m_cols; ++c) {
            std::cout << (c > 0 ? " " : "") << std::setw(2);
            out << "[";
            for (size_t ch = 0; ch < mat.m_channels; ++ch) {
                out << (ch > 0 ? ", " : "") << std::setw(3);
                out << mat.at(r, c, ch);
            }
            out << "]";
        }
        std::cout << std::endl;
    }
    return out;
}

void Matrix::add(Matrix& res, int val) const
{
    for (size_t i = 0; i < m_data.size(); ++i) {
        res.m_data[i] = m_data[i] + val;
    }
}

void Matrix::multiply(Matrix& res, int val) const
{
    for (size_t i = 0; i < m_data.size(); ++i) {
        res.m_data[i] = m_data[i] * val;
    }
}

void Matrix::subtract(Matrix& res, int val) const
{
    for (size_t i = 0; i < m_data.size(); ++i) {
        res.m_data[i] = m_data[i] - val;
    }
}