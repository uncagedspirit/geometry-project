#ifndef LINE2D_H
#define LINE2D_H

#include "point2d.h"

class Line2D {
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
};

#endif
