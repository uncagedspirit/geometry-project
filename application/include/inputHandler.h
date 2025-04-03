#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include "definitions.h"
#include "circle.h"
#include "rectangle.h"

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
    static PointVector2D getInput(const PointVector2D&, int numPoints);
    static PointVector3D getInput(const PointVector3D&, int numPoints);

    //2d shapes
    static Circle getInput(Circle);
    static Rectangle getInput(Rectangle);
};

#endif  
