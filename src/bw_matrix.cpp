//
// Created by fisibula on 3/08/21.
//

#include "bw_matrix.h"

#include <iomanip>
#include <iostream>

BWMatrix::BWMatrix()
: Matrix(0, 0, 3)
{}

BWMatrix::BWMatrix(const BWMatrix& mat)
: Matrix(mat)
{}

BWMatrix::BWMatrix(size_t rows, size_t cols)
: Matrix(rows, cols, 3)
{}

BWMatrix::BWMatrix(size_t rows, size_t cols, int initVal)
: Matrix(rows, cols, 3, initVal)
{}

void BWMatrix::print() const
{
    std::cout << *this << std::endl;
}

BWMatrix& BWMatrix::operator=(const BWMatrix& mat)
{
    Matrix::operator=(mat);
    return *this;
}

BWMatrix BWMatrix::add(int val) const
{
    BWMatrix res(m_rows, m_cols);
    Matrix::add(res, val);
    return res;
}
BWMatrix BWMatrix::multiply(int val) const
{
    BWMatrix res(m_rows, m_cols);
    Matrix::multiply(res, val);
    return res;
}
BWMatrix BWMatrix::subtract(int val) const
{
    BWMatrix res(m_rows, m_cols);
    Matrix::multiply(res, val);
    return res;
}

BWMatrix BWMatrix::operator+(int val) const
{
    return add(val);
}

BWMatrix BWMatrix::operator*(int val) const
{
    return multiply(val);
}

BWMatrix BWMatrix::operator-(int val) const
{
    return subtract(val);
}

std::ostream& operator<<(std::ostream& out, const BWMatrix& mat)
{
    for (size_t r = 0; r < mat.m_rows; ++r) {
        for (size_t c = 0; c < mat.m_cols; ++c) {
            std::cout << (c > 0 ? " " : "   ") << std::setw(2);
            out << "[";
            out << mat.at(r, c);
            out << "]";
        }
        std::cout << std::endl;
    }
    return out;
}