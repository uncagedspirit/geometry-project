#ifndef CYLINDER_H
#define CYLINDER_H

#include "shape.h"
#include "point3d.h"

class Cylinder : public Shape3D {
private:
    Point3D baseCenter;
    double radius, height;

public:
    Cylinder() : baseCenter(Point3D()), radius(0), height(0) {}
    Cylinder(const Point3D& baseCenter, double radius, double height);

    void savePointsToFile(const std::string& filename, bool append = false) override;

    std::vector<Point3D> getPoints3D() const override;
    std::vector<double> getParams() const override;
    std::string getType() const override;
};

#endif
