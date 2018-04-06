//
// Created by ficon on 05.04.18.
//

#include "Matrix.h"
#include <vector>

namespace algebra {

    Matrix::Matrix() {

    }

    Matrix::Matrix(int x, int y) {
        n_x_ = x;
        n_y_ = y;

        for (int i = 0; i < n_y_; ++i) {
            matrix_.emplace_back(std::vector<std::complex<double>>());
            for (int j = 0; j < n_x_; ++j) {
                matrix_[i].push_back(std::complex<double>());
            }
        }
    }

    Matrix::Matrix(const char *) {

    }

    Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>>) {

    }


    Matrix::~Matrix() {

    }

    Matrix Matrix::Add(const Matrix m2) const {

        Matrix result(this->n_x_, m2.n_y_);

        if (this->n_y_== m2.n_y_ && this->n_x_ == m2.n_x_) {
            for (int i = 0; i < m2.n_y_; ++i) {
                for (int j = 0; j < m2.n_x_; ++j) {
                    result.matrix_[i][j] = this->matrix_[i][j] + m2.matrix_[i][j];
                }
            }

            return Matrix();
        }
    }

    Matrix Matrix::Sub(const Matrix) {
        return Matrix();
    }

    Matrix Matrix::Mul(const Matrix) {
        return Matrix();
    }

    Matrix Matrix::Div(const Matrix) {
        return Matrix();
    }

    Matrix Matrix::Pow(int n) {
        return Matrix();
    }

    std::pair<size_t, size_t> Matrix::Size() {
        return std::make_pair(n_x_, n_y_);
    }

    std::string Matrix::Print() const{
        std::string result;
        for (int i = 0; i < this->n_y_; ++i) {
            for (int j = 0; j < this->n_x_; ++j) {
                std::string s;
                this->matrix_[i][j];
                result += ;
            }

        }
        return result;
    }

}
