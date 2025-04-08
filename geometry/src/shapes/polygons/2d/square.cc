#include "square.h"

Square::Square(const Point2D& bottomLeft, double side)
    : Rectangle(bottomLeft, side, side) {}


std::vector<Point2D> Cube::getPoints() const {
    return { getPoints() };  
}

std::vector<double> Cube::getParams() const {
    return { getParams()[0] };  
}

std::string Cube::getType() const {
    return "Cube";
}
