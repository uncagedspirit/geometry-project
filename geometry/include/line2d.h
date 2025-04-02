#ifndef LINE2D_H
#define LINE2D_H

#include "shape.h"
#include "point2d.h"
#include <fstream>

class Line2D : public Shape {
private:
    Point2D start, end;

public:
    // Constructor
    Line2D(const Point2D& start = Point2D(), const Point2D& end = Point2D());

    // Getters
    Point2D getStart() const;
    Point2D getEnd() const;

    // Setters
    void setStart(const Point2D& start);
    void setEnd(const Point2D& end);

    // Override the savePointsToFile method from shape class
    void savePointsToFile(const std::string& filename, bool append = false) override;
};

#endif
