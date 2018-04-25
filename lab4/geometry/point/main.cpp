//
// Created by ficon on 20.03.18.
//

#include <iostream>
#include "Point.h"
#include "Point3D.h"

using namespace geometry;
int main(){

    Point3D punkt3D(1,2,3);
    Point3D punkt3D_2(1,2,4);
    Point punkt(1,2);

    std::cout << punkt.Distance(punkt3D) << std::endl;
    std::cout << punkt3D.Distance(punkt3D_2) << std::endl;
    return 0;
}