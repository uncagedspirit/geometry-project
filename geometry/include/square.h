#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle {
public:
    Square() : Rectangle(Point2D(), 0, 0) {}  // Default constructor
    Square(const Point2D& bottomLeft, double side);

    std::vector<Point2D> getPoints() const override;
    std::vector<double> getParams() const override;
    std::string getType() const override;
};

#endif
