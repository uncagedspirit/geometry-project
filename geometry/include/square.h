#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle {
public:
    Square() : Rectangle(Point2D(), 0, 0) {}  // Default constructor
    Square(const Point2D& bottomLeft, double side);
};

#endif
