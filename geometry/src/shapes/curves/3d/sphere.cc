#include "sphere.h"
#include <fstream>
#include <cmath>

#define PI 3.141592653589793

Sphere::Sphere(const Point3D& center, double radius)
    : center(center), radius(radius) {}

void Sphere::savePointsToFile(const std::string& filename, bool append) {
    std::ofstream file(filename, append ? std::ios::app : std::ios::out);
    if (!file) return;

    int latSteps = 20, lonSteps = 20;
    for (int i = 0; i <= latSteps; ++i) {
        double theta = PI * i / latSteps;
        for (int j = 0; j <= lonSteps; ++j) {
            double phi = 2 * PI * j / lonSteps;
            double x = center.getX() + radius * sin(theta) * cos(phi);
            double y = center.getY() + radius * sin(theta) * sin(phi);
            double z = center.getZ() + radius * cos(theta);
            file << x << " " << y << " " << z << "\n";
        }
        file << "\n";
    }

    file.close();
}

std::vector<Point3D> Sphere::getPoints3D() const {
    return { center };
}

std::vector<double> Sphere::getParams() const {
    return { radius };
}

std::string Sphere::getType() const {
    return "Sphere";
}
