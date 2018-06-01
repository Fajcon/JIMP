//
// Created by ficon on 22.05.18.
//
#include "FactoryMethod.h"
int main() {
     int a = 10;
     int b = 5;
     int c = factoryMethod::Add(a, b);
     std::cout << c;
     return 0;
}
