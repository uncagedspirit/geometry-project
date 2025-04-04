#include "cube.h"

void Cube::savePointsToFile(const std::string& filename, bool append) {
    Cuboid::savePointsToFile(filename, append);  // reuse cuboid logic
}
