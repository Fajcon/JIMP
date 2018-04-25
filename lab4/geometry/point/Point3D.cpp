//
// Created by ficon on 19.04.18.
//

#include "Point3D.h"
namespace geometry{

    Point3D::Point3D() {

    }

    Point3D::Point3D(double x, double y, double z) {
        std::cout << "Konstruktor parametrowy Point3D" << std::endl;
        x_ = x;
        y_ = y;
        z_ = z;

    }

    double Point3D::distance(const Point3D &other) const {
        return sqrt(pow(getX_() - other.getX_(), 2) + pow(getY_() - other.getY_(), 2)
                    + pow(getZ_() - other.getZ_(), 2));
    }

    double Point3D::getX_() const {
        return x_;
    }

    void Point3D::setX_(double x_) {
        Point3D::x_ = x_;
    }

    double Point3D::getY_() const {
        return y_;
    }

    void Point3D::setY_(double y_) {
        Point3D::y_ = y_;
    }

    double Point3D::getZ_() const {
        return z_;
    }

    void Point3D::setZ_(double z_) {
        Point3D::z_ = z_;
    }
}