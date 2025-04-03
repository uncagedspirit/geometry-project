#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "point2d.h"

class Rectangle : public Shape {
private:
    Point2D bottomLeft;
    double width, height;

public:
    Rectangle() : bottomLeft(Point2D()), width(0), height(0) {}  // Default constructor
    Rectangle(const Point2D& bottomLeft, double width, double height);

    void setBottomLeft(const Point2D& bottomLeft);
    void setWidth(double width);
    void setHeight(double height);

    void savePointsToFile(const std::string& filename, bool append = false) override;
};

#endif
