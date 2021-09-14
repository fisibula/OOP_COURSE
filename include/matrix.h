//
// Created by fisibula on 28/07/21.
//

#ifndef OOP_COURSE_MATRIX_H
#define OOP_COURSE_MATRIX_H

#include <vector>
#include <ostream>

class Matrix {
    public:
        Matrix();
        Matrix(const Matrix& mat);
        Matrix(size_t rows, size_t cols, size_t channels);
        Matrix(size_t rows, size_t cols, size_t channels, int initValue);

        inline size_t getRows() const {return m_rows;}
        inline size_t getCols() const {return m_cols;}
        inline size_t getChannels() const {return m_channels;}
        inline const int& at(size_t row, size_t col, size_t channel = 0) const {
            return m_data[row * m_cols + col * m_channels + col * m_channels + channel];
        }
        inline int& at(size_t row, size_t col, size_t channel = 0) {
            return m_data[row * m_cols + col * m_channels + col * m_channels + channel];
        }

        virtual void print() const;

        Matrix add(int val) const;
        Matrix multiply(int val) const;
        Matrix subtract(int val) const;
        Matrix add(const Matrix& mat) const;
        Matrix multiply(const Matrix& mat) const;
        Matrix subtract(const Matrix& mat) const;

        Matrix operator+(const Matrix& mat) const;
        Matrix operator+(int val) const;
        Matrix operator-(const Matrix& mat) const;
        Matrix operator-(int val) const;
        Matrix operator*(const Matrix& mat) const;
        Matrix operator*(int val) const;
        Matrix& operator=(const Matrix& mat);
        friend std::ostream& operator<<(std::ostream& out, const Matrix& mat);

    protected:
        void add(Matrix& res, int val) const;
        void multiply(Matrix& res, int val) const;
        void subtract(Matrix& res, int val) const;

    protected:
        size_t m_rows;
        size_t m_cols;
        size_t m_channels;
        std::vector<int> m_data;
};

#endif //OOP_COURSE_MATRIX_H
