#ifndef CUBOID_H
#define CUBOID_H

#include "shape.h"
#include "point3d.h"

class Cuboid : public Shape {
private:
    Point3D bottomLeftFront;
    double length, width, height;

public:
    Cuboid() : bottomLeftFront(Point3D()), length(0), width(0), height(0) {}  // Default constructor
    Cuboid(const Point3D& bottomLeftFront, double length, double width, double height);


    void savePointsToFile(const std::string& filename, bool append = false) override;
};

#endif
