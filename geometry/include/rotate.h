#ifndef ROTATE_H
#define ROTATE_H

#include <vector>
#include "point2d.h"
#include "point3d.h"

std::vector<Point2D> rotate2D(std::vector<Point2D> points, char axis, double angle);
std::vector<Point3D> rotate3D(std::vector<Point3D> points, char axis, double angle);

#endif