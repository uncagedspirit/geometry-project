#ifndef CYLINDER_H
#define CYLINDER_H

#include "shape.h"
#include "point3d.h"

class Cylinder : public Shape {
private:
    Point3D baseCenter;
    double radius, height;

public:
    Cylinder() : baseCenter(Point3D()), radius(0), height(0) {}
    Cylinder(const Point3D& baseCenter, double radius, double height);

    void savePointsToFile(const std::string& filename, bool append = false) override;
};

#endif
