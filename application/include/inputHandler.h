#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include "definitions.h"

class InputHandler {
public:
    // Input for single points
    static Point2D getInput(Point2D);  
    static Point3D getInput(Point3D);

    // Input for static-sized arrays
    static TwoPointsArray2D getInput(const TwoPointsArray2D&);
    static TwoPointsArray3D getInput(const TwoPointsArray3D&);
    static ThreePointsArray2D getInput(const ThreePointsArray2D&);
    static ThreePointsArray3D getInput(const ThreePointsArray3D&);

    // Input for dynamic-sized arrays
    static PointArray2D getInput(const PointArray2D&, int numPoints);
    static PointArray3D getInput(const PointArray3D&, int numPoints);
};

#endif  
