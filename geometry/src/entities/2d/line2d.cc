#include "line2d.h"

// Constructor
Line2D::Line2D(const Point2D& start, const Point2D& end) : start(start), end(end) {}

// Getters
Point2D Line2D::getStart() const { return start; }
Point2D Line2D::getEnd() const { return end; }

// Setters
void Line2D::setStart(const Point2D& start) { this->start = start; }
void Line2D::setEnd(const Point2D& end) { this->end = end; }
