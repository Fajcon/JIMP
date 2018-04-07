//
// Created by ficon on 05.04.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <vector>
#include <complex>
#include <iostream>

namespace algebra {

    class Matrix {

    public:
        Matrix();

        Matrix(std::initializer_list<std::vector<std::complex<double>>> new_matrix);

        Matrix(int x, int y);

        Matrix(const char *);

        ~Matrix();

        Matrix Add(const Matrix) const;

        Matrix Sub(const Matrix);

        Matrix Mul(const Matrix &m2);

        Matrix Mul(std::complex<double>);

        Matrix Div(const Matrix);

        Matrix Pow(int n);

        std::pair<size_t, size_t> Size();

        std::string Print() const;




    private:
        int n_x_;
        int n_y_;

        std::vector<std::vector<std::complex<double>>> matrix_;
    };

}
#endif //JIMP_EXERCISES_MATRIX_H
