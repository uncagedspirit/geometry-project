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
typedef std::vector<Point2D> PointVector2D;

//dynamic sized points vector for 3d
typedef std::vector<Point3D> PointVector3D;

//geometry definitions
#define PI 3.14159265358979323846

#define DEG2RAD(angleDegrees) ((angleDegrees) * M_PI / 180.0)

#endif