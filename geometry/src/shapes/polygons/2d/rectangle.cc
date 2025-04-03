#include "rectangle.h"
#include <vector>
#include <fstream>

Rectangle::Rectangle(const Point2D& bottomLeft, double width, double height)
    : bottomLeft(bottomLeft), width(width), height(height) {}

void Rectangle::setBottomLeft(const Point2D& bottomLeft) { this->bottomLeft = bottomLeft; }
void Rectangle::setWidth(double width) { this->width = width; }
void Rectangle::setHeight(double height) { this->height = height; }

//saving the points of the rectangle to a file for plotting

void Rectangle::savePointsToFile(const std::string& filename, bool append) {
    std::ofstream file(filename, append ? std::ios::app : std::ios::out);
    if (!file) return;

    std::vector<Point2D> points = {
        bottomLeft,
        {bottomLeft.getX() + width, bottomLeft.getY()},
        {bottomLeft.getX() + width, bottomLeft.getY() + height},
        {bottomLeft.getX(), bottomLeft.getY() + height},
        bottomLeft
    };

    for (const auto& p : points) {
        file << p.getX() << " " << p.getY() << "\n";
    }
    file << "\n\n";
    file.close();
}