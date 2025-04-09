#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <vector>
#include "point2d.h"
#include "point3d.h"

std::vector<Point2D> translate2D(std::vector<Point2D> points, double dx, double dy);
std::vector<Point3D> translate3D(std::vector<Point3D> points, double dx, double dy, double dz);

#endif
