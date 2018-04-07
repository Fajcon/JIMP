//
// Created by ficon on 05.04.18.
//

#include "Matrix.h"

namespace algebra {

    Matrix::Matrix() {

    }

    Matrix::Matrix(int x, int y) {
        n_x_ = x;
        n_y_ = y;

        for (int i = 0; i < n_y_; ++i) {
            matrix_.emplace_back(std::vector<std::complex<double>>());
            for (int j = 0; j < n_x_; ++j) {
                matrix_[i].emplace_back(std::complex<double>());
            }
        }
    }

    Matrix::Matrix(const char *){

    }

    Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> new_matrix) {
        n_y_ = new_matrix.size();
        n_x_ = (*new_matrix.begin()).size();
        if (n_y_ < 1 || n_x_ < 1) {
            n_y_ = 0;
            n_x_ = 0;
            return;
        }
        for (int i = 0; i < n_y_; ++i) {
            matrix_.emplace_back();
            for (int j = 0; j < n_x_; ++j) {
                matrix_[i].emplace_back(std::complex<double>());
            }
        }
        std::initializer_list<std::vector<std::complex<double>>>::iterator it;
        int i = 0;
        for (it = new_matrix.begin(); it != new_matrix.end(); it++) {
            for (int j = 0; j < n_y_; j++) {
                matrix_[i][j] = (*it)[j];
            }
            i++;
        }
    }

   Matrix::~Matrix() {

    }

    Matrix Matrix::Add(const Matrix m2) const {

        if (this->n_y_== m2.n_y_ && this->n_x_ == m2.n_x_) {
            Matrix result = Matrix(this->n_x_, this->n_y_);
            for (int i = 0; i < n_y_; ++i) {
                for (int j = 0; j < n_x_; ++j) {
                    result.matrix_[i][j] = this->matrix_[i][j] + m2.matrix_[i][j];
                }
            }
            return result;
        }
    }

    Matrix Matrix::Sub(const Matrix m2) {
        if (this->n_y_== m2.n_y_ && this->n_x_ == m2.n_x_) {
            Matrix result = Matrix(this->n_x_, this->n_y_);
            for (int i = 0; i < n_y_; ++i) {
                for (int j = 0; j < n_x_; ++j) {
                    result.matrix_[i][j] = this->matrix_[i][j] - m2.matrix_[i][j];
                }
            }
            return result;
        }
    }

    Matrix Matrix::Mul(const Matrix &m2) {

       if (this->n_x_ == m2.n_y_) {
            Matrix result = Matrix(m2.n_x_, this->n_y_);
            for (int i = 0; i < n_y_; i++)
                for (int j = 0; j < m2.n_x_; j++) {
                    result.matrix_[i][j] = std::complex<double>(0, 0);
                    for (int k = 0; k < n_x_; k++) {
                        result.matrix_[i][j] += matrix_[i][k] * m2.matrix_[k][j];
                    }
                }
            return result;
       } else return Matrix();
    }

    Matrix Matrix::Mul(std::complex<double> n) {

        Matrix result = Matrix(this->n_x_, this->n_y_);

        for (int i = 0; i < n_y_; i++) {
            for (int j = 0; j < n_x_; j++) {
                result.matrix_[i][j] = this->matrix_[i][j] * n;
            }
        }
        return result;
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
        std::ostringstream result;
        result<<"[";
        for (int i = 0; i < n_y_; ++i) {
            for (int j = 0; j < n_x_; ++j) {
                result << this->matrix_[i][j].real()<<"i"<< this->matrix_[i][j].imag();
                if(j == n_x_-1 && i != n_y_-1) {
                    result << "; ";

                }
                else if((j == n_x_-1) && (i = n_y_ -1)){
                    result << "]";
                }
                else{
                    result << ", ";
                }
            }
        }
        return result.str();
    }

}
