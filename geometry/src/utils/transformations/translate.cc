#include "transformer.h"
#include <iostream>

std::vector<Point2D> Transformer::translate(std::vector<Point2D> points, double dx, double dy) {
    std::vector<Point2D> translatedPoints;
    for (const auto& pt : points) {
        translatedPoints.emplace_back(pt.getX() + dx, pt.getY() + dy);
    }
    return translatedPoints;
}

std::vector<Point3D> Transformer::translate(std::vector<Point3D> points, double dx, double dy, double dz) {
    std::vector<Point3D> translatedPoints;
    for (const auto& pt : points) {
        translatedPoints.emplace_back(pt.getX() + dx, pt.getY() + dy, pt.getZ() + dz);
    }
    return translatedPoints;
}
