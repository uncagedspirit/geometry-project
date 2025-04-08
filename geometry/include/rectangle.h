#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "point2d.h"

class Rectangle : public Shape2D {
private:
    Point2D bottomLeft;
    double length, width;

public:
    Rectangle() : bottomLeft(Point2D()), length(0), width(0) {}  // Default constructor
    Rectangle(const Point2D& bottomLeft, double length, double width);

    void setBottomLeft(const Point2D& bottomLeft);
    void setLength(double length);
    void setWidth(double width);

    void savePointsToFile(const std::string& filename, bool append = false) override;

    // Transformation support
    std::vector<Point2D> getPoints2D() const override;
    std::vector<double> getParams() const override;
    std::string getType() const override;
};

#endif
