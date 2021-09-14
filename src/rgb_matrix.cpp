//
// Created by fisibula on 2/08/21.
//
#include "rgb_matrix.h"

#include <iomanip>
#include <iostream>

RGBMatrix::RGBMatrix()
    : Matrix(0, 0, 3)
{}

RGBMatrix::RGBMatrix(const RGBMatrix& mat)
    : Matrix(mat)
{}

RGBMatrix::RGBMatrix(size_t rows, size_t cols)
    : Matrix(rows, cols, 3)
{}

RGBMatrix::RGBMatrix(size_t rows, size_t cols, int initVal)
    : Matrix(rows, cols, 3, initVal)
{}

void RGBMatrix::print() const
{
    std::cout << *this << std::endl;
}

RGBMatrix& RGBMatrix::operator=(const RGBMatrix& mat)
{
    Matrix::operator=(mat);
    return *this;
}

RGBMatrix RGBMatrix::add(int val) const
{
    RGBMatrix res(m_rows, m_cols);
    Matrix::add(res, val);
    return res;
}
RGBMatrix RGBMatrix::multiply(int val) const
{
    RGBMatrix res(m_rows, m_cols);
    Matrix::multiply(res, val);
    return res;
}
RGBMatrix RGBMatrix::subtract(int val) const
{
    RGBMatrix res(m_rows, m_cols);
    Matrix::multiply(res, val);
    return res;
}

RGBMatrix RGBMatrix::operator+(int val) const
{
    return add(val);
}

RGBMatrix RGBMatrix::operator*(int val) const
{
    return multiply(val);
}

RGBMatrix RGBMatrix::operator-(int val) const
{
    return subtract(val);
}

std::ostream& operator<<(std::ostream& out, const RGBMatrix& mat)
{
    static const std::vector<std::string> names = {"r", "g", "b"};
    for (size_t r = 0; r < mat.m_rows; ++r) {
        for (size_t c = 0; c < mat.m_cols; ++c) {
            std::cout << (c > 0 ? " " : "   ") << std::setw(2);
            out << "[";
            for (size_t ch = 0; ch < mat.m_channels; ++ch) {
                out << (ch > 0 ? ", " : "") << std::setw(3);
                out << names[ch] << ": " << mat.at(r, c, ch);
            }
            out << "]";
        }
        std::cout << std::endl;
    }
    return out;
}