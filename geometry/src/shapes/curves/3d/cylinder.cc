#include "cylinder.h"
#include <fstream>
#include <cmath>

#define PI 3.141592653589793

Cylinder::Cylinder(const Point3D& baseCenter, double radius, double height)
    : baseCenter(baseCenter), radius(radius), height(height) {}

void Cylinder::savePointsToFile(const std::string& filename, bool append) {
    std::ofstream file(filename, append ? std::ios::app : std::ios::out);
    if (!file) return;

    int numPoints = 100;
    for (int i = 0; i < numPoints; ++i) {
        double theta = 2 * PI * i / numPoints;
        double x = baseCenter.getX() + radius * cos(theta);
        double y = baseCenter.getY() + radius * sin(theta);
        double z1 = baseCenter.getZ();
        double z2 = baseCenter.getZ() + height;
        file << x << " " << y << " " << z1 << "\n";
        file << x << " " << y << " " << z2 << "\n";
    }

    file.close();
}


std::vector<Point3D> Cylinder::getPoints3D() const {
    return { baseCenter };
}

std::vector<double> Cylinder::getParams() const {
    return { radius, height };
}

std::string Cylinder::getType() const {
    return "Cylinder";
}
