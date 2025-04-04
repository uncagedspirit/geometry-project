#ifndef CUBE_H
#define CUBE_H

#include "cuboid.h"

class Cube : public Cuboid {
public:
    Cube() : Cuboid(Point3D(), 0, 0, 0) {}  // default
    Cube(const Point3D& bottomLeftFront, double side)
        : Cuboid(bottomLeftFront, side, side, side) {}

    void savePointsToFile(const std::string& filename, bool append = false) override;
};

#endif
