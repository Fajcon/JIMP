//
// Created by ficon on 19.04.18.
//

#ifndef JIMP_EXERCISES_POINT3D_H
#define JIMP_EXERCISES_POINT3D_H

#include <cmath>
#include <iostream>
#include "Point.h"

namespace geometry {
    class Point3D : public Point {
    public:
        Point3D();

        double getX_() const;

        void setX_(double x_);

        double getY_() const;

        void setY_(double y_);

        double getZ_() const;

        void setZ_(double z_);

        Point3D(double x, double y, double z);
        
        double distance(const Point3D &other) const;

    private:
        double x_, y_, z_;

    };
}


#endif //JIMP_EXERCISES_POINT3D_H
