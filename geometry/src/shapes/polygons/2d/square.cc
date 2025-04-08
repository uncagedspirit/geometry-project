#include "square.h"

Square::Square(const Point2D& bottomLeft, double side)
    : Rectangle(bottomLeft, side, side) {}


std::vector<Point2D> Square::getPoints2D() const {
    return { getPoints2D()[0] };  
}

std::vector<double> Square::getParams() const {
    return { getParams()[0] };  
}

std::string Square::getType() const {
    return "Square";
}
