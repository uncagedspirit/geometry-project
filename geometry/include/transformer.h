#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <vector>
#include <string>
#include "point2d.h"
#include "point3d.h"
#include "shape.h"

// transformation functions
#include "scale.h"
#include "rotate.h"
#include "translate.h"

class Transformer {
public:
    static Shape* transform(std::vector<Point2D> points, std::vector<double> params, std::string shapeType);
    static Shape* transform(std::vector<Point3D> points, std::vector<double> params, std::string shapeType);

private:
    static std::vector<Point2D> rotate(std::vector<Point2D> points, char axis, double angle);
    static std::vector<Point3D> rotate(std::vector<Point3D> points, char axis, double angle);
    static std::vector<Point2D> translate(std::vector<Point2D> points, double dx, double dy);
    static std::vector<Point3D> translate(std::vector<Point3D> points, double dx, double dy, double dz);
    static std::vector<double> scale(std::vector<double> params, double factor);

    static Shape* createShape2D(const std::string& type, const std::vector<Point2D>& points, const std::vector<double>& params);
    static Shape* createShape3D(const std::string& type, const std::vector<Point3D>& points, const std::vector<double>& params);
};

#endif
