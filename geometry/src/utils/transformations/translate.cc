/*
common translate logic for each shape, using the translate matrix
use A loop for points which would input each point and transform it

return a new shape to the savepointstofile function of the shape

*/

//dummy code for testing change later

#include <iostream>
#include "transformer.h"

std::vector<Point2D> Transformer::translate(std::vector<Point2D> points, double dx, double dy) {
    std::cout << "[Dummy] Translating 2D by dx=" << dx << ", dy=" << dy << "\n";
    return points;
}

std::vector<Point3D> Transformer::translate(std::vector<Point3D> points, double dx, double dy, double dz) {
    std::cout << "[Dummy] Translating 3D by dx=" << dx << ", dy=" << dy << ", dz=" << dz << "\n";
    return points;
}
