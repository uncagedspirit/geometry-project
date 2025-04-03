#include "square.h"

Square::Square(const Point2D& bottomLeft, double side)
    : Rectangle(bottomLeft, side, side) {}
