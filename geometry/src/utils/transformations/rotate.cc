#include "transformer.h"
#include "definitions.h"
#include <cmath>
#include <iostream>


std::vector<Point2D> Transformer::rotate(std::vector<Point2D> points, char axis, double angle) {
    double radians = DEG2RAD(angle);
    double cosA = cos(radians);
    double sinA = sin(radians);

    std::vector<Point2D> rotatedPoints;
    for (const auto& pt : points) {
        double x = pt.getX();
        double y = pt.getY();
        double newX = x * cosA - y * sinA;
        double newY = x * sinA + y * cosA;
        rotatedPoints.emplace_back(newX, newY);
    }
    return rotatedPoints;
}

std::vector<Point3D> Transformer::rotate(std::vector<Point3D> points, char axis, double angle) {
    double radians = DEG2RAD(angle);
    double cosA = cos(radians);
    double sinA = sin(radians);

    std::vector<Point3D> rotatedPoints;
    for (const auto& pt : points) {
        double x = pt.getX();
        double y = pt.getY();
        double z = pt.getZ();
        double newX = x, newY = y, newZ = z;

        switch (axis) {
            case 'x':
            case 'X':
                newY = y * cosA - z * sinA;
                newZ = y * sinA + z * cosA;
                break;
            case 'y':
            case 'Y':
                newX = x * cosA + z * sinA;
                newZ = -x * sinA + z * cosA;
                break;
            case 'z':
            case 'Z':
                newX = x * cosA - y * sinA;
                newY = x * sinA + y * cosA;
                break;
            default:
                std::cerr << "Invalid axis. Use x, y, or z.\n";
                break;
        }

        rotatedPoints.emplace_back(newX, newY, newZ);
    }
    return rotatedPoints;
}
