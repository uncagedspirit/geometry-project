#include "rectangle.h"
#include <vector>
#include <fstream>

Rectangle::Rectangle(const Point2D& bottomLeft, double length, double width)
    : bottomLeft(bottomLeft), length(length), width(width) {}

void Rectangle::setBottomLeft(const Point2D& bottomLeft) { this->bottomLeft = bottomLeft; }
void Rectangle::setLength(double length) { this->length = length; }
void Rectangle::setWidth(double width) { this->width = width; }

//saving the points of the rectangle to a file for plotting

void Rectangle::savePointsToFile(const std::string& filename, bool append) {
    std::ofstream file(filename, append ? std::ios::app : std::ios::out);
    if (!file) return;

    std::vector<Point2D> points = {
        bottomLeft,
        {bottomLeft.getX() + length, bottomLeft.getY()},
        {bottomLeft.getX() + length, bottomLeft.getY() + width},
        {bottomLeft.getX(), bottomLeft.getY() + width},
        bottomLeft
    };

    for (const auto& p : points) {
        file << p.getX() << " " << p.getY() << "\n";
    }
    file << "\n\n";
    file.close();
}


std::vector<Point2D> Rectangle::getPoints2D() const {
    return { bottomLeft };
}

std::vector<double> Rectangle::getParams() const {
    return { length, width };
}

std::string Rectangle::getType() const {
    return "Rectangle";
}