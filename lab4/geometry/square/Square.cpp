//
// Created by ficon on 20.03.18.
//

#include "Square.h"

namespace geometry{


    Square::Square(Point a, Point b, Point c, Point d) {
        a_ = a;
        b_ = b;
        c_ = c;
        d_ = d;
    }

    double Square::Circumference() const {

        if(a_.Distance(b_)==c_.Distance(d_) && a_.Distance(c_)==b_.Distance(d_)){
            return 4 * a_.Distance(b_);
        }
        else{
            return 0.0;
        }
    }

    double Square::Area() const {
        if(a_.Distance(b_)==c_.Distance(d_)&& a_.Distance(c_)==b_.Distance(d_)){
            return a_.Distance(b_)*a_.Distance(b_);
        }
        else{
            return 0.0;
        }
    }

}
