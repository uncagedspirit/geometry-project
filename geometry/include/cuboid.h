#ifndef CUBOID_H
#define CUBOID_H

#include "shape.h"
#include "point3d.h"
#include <vector>
#include <string>

class Cuboid : public Shape3D {
private:
    Point3D bottomLeftFront;
    double length, width, height;

public:
    Cuboid() : bottomLeftFront(Point3D()), length(0), width(0), height(0) {}
    Cuboid(const Point3D& bottomLeftFront, double length, double width, double height);

    void savePointsToFile(const std::string& filename, bool append = false) override;

    // Transformation support
    std::vector<Point3D> getPoints3D() const override;
    std::vector<double> getParams() const override;
    std::string getType() const override;
};

#endif
