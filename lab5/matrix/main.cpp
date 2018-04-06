//
// Created by ficon on 05.04.18.
//

#include <iostream>
#include "Matrix.h"

namespace algebra{
int main() {

    Matrix m1;
    Matrix m2;

    std::cout << "Macierz pierwsza: " << m1.Print() << std::endl;
    std::cout << "Macierz druga: " << m2.Print() << std::endl;
    
    std::cout << "Dodawanie" << (m1.Add(m2)).Print() << std::endl;
    std::cout << "Odejmowanie" << (m1.Sub(m2)).Print() << std::endl;
    std::cout << "Mnożenie" << (m1.Mul(m2)).Print() << std::endl;/*
    std::cout << "Dzielenie" << (m1.Div(m2)).Print() << std::endl;
    std::cout << "Potęgowanie" << (m1.Pow(2)).Print() << std::endl;
    std::cout << "Potęgowanie" << (m2.Pow(2)).Print() << std::endl;*/

    return 0;
}
}