//
// Created by fisibula on 2/08/21.
//

#ifndef OOP_COURSE_RGB_MATRIX_H
#define OOP_COURSE_RGB_MATRIX_H

#include "matrix.h"

class RGBMatrix : public Matrix
        {
        public:
            RGBMatrix();
            RGBMatrix(const RGBMatrix& mat);
            RGBMatrix(size_t rows, size_t cols);
            RGBMatrix(size_t rows, size_t cols, int initVal);

            void print() const override;

            RGBMatrix add(int val) const;
            RGBMatrix multiply(int val) const;
            RGBMatrix subtract(int val) const;

            RGBMatrix operator+(int val) const;
            RGBMatrix operator*(int val) const;
            RGBMatrix operator-(int val) const;
            RGBMatrix& operator=(const RGBMatrix& mat);
            friend std::ostream& operator<<(std::ostream& out, const RGBMatrix& mat);
        };

#endif //OOP_COURSE_RGB_MATRIX_H
