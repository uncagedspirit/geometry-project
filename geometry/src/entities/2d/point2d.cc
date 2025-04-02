#include "point2d.h"

// Constructor
Point2D::Point2D(double x, double y) : x(x), y(y) {}

// Getters
double Point2D::getX() const { return x; }
double Point2D::getY() const { return y; }

// Setters
void Point2D::setX(double x) { this->x = x; }
void Point2D::setY(double y) { this->y = y; }
