#include "point3d.h"
#include <iostream>

// Constructor
Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

// Getters
double Point3D::getX() const { return x; }
double Point3D::getY() const { return y; }
double Point3D::getZ() const { return z; }

// Setters
void Point3D::setX(double x) { this->x = x; }
void Point3D::setY(double y) { this->y = y; }
void Point3D::setZ(double z) { this->z = z; }


