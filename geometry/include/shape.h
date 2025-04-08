#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <vector>
#include "point2d.h"
#include "point3d.h"

// 🔹 Base abstract class
class Shape {
public:
    virtual ~Shape() = default;

    virtual void savePointsToFile(const std::string& filename, bool append = false) = 0;

    virtual std::vector<double> getParams() const = 0;
    virtual std::string getType() const = 0;
};

class Shape2D : public Shape {
public:
    virtual std::vector<Point2D> getPoints() const = 0;
};

class Shape3D : public Shape {
public:
    virtual std::vector<Point3D> getPoints() const = 0;
};

#endif
