#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <vector>
#include <array>

#include "point2d.h"
#include "point3d.h"

//static size points array for 2d points
typedef std::array<Point2D, 2> TwoPointsArray2D;
typedef std::array<Point2D, 3> ThreePointsArray2D;

//static size points array for 3d points
typedef std::array<Point3D, 2> TwoPointsArray3D;
typedef std::array<Point3D, 3> ThreePointsArray3D;

//dynamic sized points vector for 2d
typedef std::vector<Point2D> PointArray2D;

//dynamic sized points vector for 3d
typedef std::vector<Point3D> PointArray3D;

