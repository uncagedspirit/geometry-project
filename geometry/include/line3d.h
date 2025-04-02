#ifndef LINE3D_H
#define LINE3D_H

#include "point3d.h"

class Line3D {
private:
    Point3D start, end;

public:
    // Constructor
    Line3D(const Point3D& start = Point3D(), const Point3D& end = Point3D());

    // Getters
    Point3D getStart() const;
    Point3D getEnd() const;

    // Setters
    void setStart(const Point3D& start);
    void setEnd(const Point3D& end);
};

#endif
