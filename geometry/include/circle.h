#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "point2d.h"

#include <vector>

class Circle : public Shape {
private:
    Point2D center;
    double radius;

public:
    Circle() : center(Point2D()), radius(0) {}  // Default constructor
    Circle(const Point2D& center, double radius);

    Point2D getCenter() const;
    double getRadius() const;

    void setCenter(const Point2D& center);
    void setRadius(double radius);

    void savePointsToFile(const std::string& filename, bool append = false) override;
};

#endif
