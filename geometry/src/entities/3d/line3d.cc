#include "line3d.h"

// Constructor
Line3D::Line3D(const Point3D& start, const Point3D& end) : start(start), end(end) {}

// Getters
Point3D Line3D::getStart() const { return start; }
Point3D Line3D::getEnd() const { return end; }

// Setters
void Line3D::setStart(const Point3D& start) { this->start = start; }
void Line3D::setEnd(const Point3D& end) { this->end = end; }
