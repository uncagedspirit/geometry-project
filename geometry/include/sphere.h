#ifndef SPHERE_H
#define SPHERE_H

#include "shape.h"
#include "point3d.h"

class Sphere : public Shape {
private:
    Point3D center;
    double radius;

public:
    Sphere() : center(Point3D()), radius(0) {}
    Sphere(const Point3D& center, double radius);

    void savePointsToFile(const std::string& filename, bool append = false) override;
    
    // Transformation support
    std::vector<Point3D> getPoints() const override;
    std::vector<double> getParams() const override;
    std::string getType() const override;
};


#endif
