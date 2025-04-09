#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <vector>
#include <string>
#include "point2d.h"
#include "point3d.h"

//transformations
#include "scale.hpp"
#include "rotate.hpp"
#include "translate.hpp"

class Transformer {
public:
    static void transform(std::vector<Point2D> points, std::vector<double> params, std::string shapeType);
    static void transform(std::vector<Point3D> points, std::vector<double> params, std::string shapeType);

private:
    static std::vector<Point2D> rotate(std::vector<Point2D> points, char axis, double angle);
    static std::vector<Point2D> translate(std::vector<Point2D> points, double dx, double dy);
    static std::vector<double> scale(std::vector<double> params, double factor);
    static std::vector<Point3D> rotate(std::vector<Point3D> points, char axis, double angle);
    static std::vector<Point3D> translate(std::vector<Point3D> points, double dx, double dy, double dz);
};

#endif
