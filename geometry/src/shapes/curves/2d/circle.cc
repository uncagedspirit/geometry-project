#include "circle.h"
#include <fstream>
#include <cmath>

#include "definitions.h"

Circle::Circle(const Point2D& center, double radius) : center(center), radius(radius) {}

Point2D Circle::getCenter() const { return center; }
double Circle::getRadius() const { return radius; }

void Circle::setCenter(const Point2D& center) { this->center = center; }
void Circle::setRadius(double radius) { this->radius = radius; }


void Circle::savePointsToFile(const std::string& filename, bool append) {
    std::ofstream file(filename, append ? std::ios::app : std::ios::out);
    if (!file) return;

    int numPoints = 100;
    for (int i = 0; i < numPoints; ++i) {
        double theta = 2 * PI * i / numPoints;
        double x = center.getX() + radius * cos(theta);
        double y = center.getY() + radius * sin(theta);
        file << x << " " << y << "\n";
    }
    file.close();
}


std::vector<Point2D> Circle::getPoints2D() const {
    return { center };
}

std::vector<double> Circle::getParams() const {
    return { radius };
}

std::string Circle::getType() const {
    return "Circle";
}
