#include "cube.h"

void Cube::savePointsToFile(const std::string& filename, bool append) {
    Cuboid::savePointsToFile(filename, append);
}


std::vector<Point3D> Cube::getPoints3D() const {
    return { getPoints3D() };  
}

std::vector<double> Cube::getParams() const {
    return { getParams()[0] };  
}

std::string Cube::getType() const {
    return "Cube";
}
