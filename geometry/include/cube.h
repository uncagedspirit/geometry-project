#ifndef CUBE_H
#define CUBE_H

#include "cuboid.h"

class Cube : public Cuboid {
public:
    Cube() : Cuboid(Point3D(), 0, 0, 0) {}
    Cube(const Point3D& bottomLeftFront, double side)
        : Cuboid(bottomLeftFront, side, side, side) {}

        
    void savePointsToFile(const std::string& filename, bool append = false) override;

    std::vector<Point3D> getPoints() const override;
    std::vector<double> getParams() const override;
    std::string getType() const override;
};

#endif
