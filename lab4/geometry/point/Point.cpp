//
// Created by ficon on 20.03.18.
//
//Definicja znajduje się w pliku Point.cpp
#include <cmath>
#include <iostream>
#include <iomanip>
#include "Point.h"

using ::std::istream;
using ::std::ws;


namespace geometry {
    using ::std::ostream;
    using ::std::cout;
    using ::std::endl;
    using ::std::pow;
    using ::std::sqrt;

/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora
    Point::Point() : x_(0), y_(0) {
        cout << "Konstruktor bezparametrowy" << endl;
    }

    Point::Point(double x, double y) {
        cout << "Konstruktor parametrowy" << endl;
        x_ = x;
        y_ = y;
    }

    Point::~Point() {
        cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
        cout << endl;
    }

    double Point::Distance(const Point &other) const {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
    }

    void Point::ToString(ostream *out) const {
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    double Point::GetX() const {
        return x_;
    }

    double Point::GetY() const {
        return y_;
    }

    void Point::SetX(double x) {
        x_=x;
    }

    void Point::SetY(double y) {
        y_=y;

    }

    //Helper functions:
    void CheckNextChar(char c, istream* is) {
        int next_char = is->peek();
        //if (next_char != c) {
        //    throw runtime_error("invalid character");
        //}
        is->ignore();
    }

    void IgnoreWhitespace(istream* is) {
        (*is) >> ws;
    }

    double ReadNumber(istream* is) {
        double d;
        (*is) >> d;
        return d;
    }

    istream& operator>>(istream & input, Point& p){
        CheckNextChar('(', &input);
        p.SetX(ReadNumber(&input));
        CheckNextChar(',', &input);
        IgnoreWhitespace(&input);
        p.SetY(ReadNumber(&input));
        CheckNextChar(')', &input);
        return input;      // Umożliwia cin >> a >> b >> c;
    }

    ostream& operator<<(ostream & output, Point& point){

        output << "("<<point.GetX()<<","<<point.GetY()<<")";


        return output;
    }



}