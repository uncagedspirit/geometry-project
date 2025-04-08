#include "cuboid.h"
#include <fstream>
#include <vector>

Cuboid::Cuboid(const Point3D& bottomLeftFront, double length, double width, double height)
    : bottomLeftFront(bottomLeftFront), length(length), width(width), height(height) {}
    

void Cuboid::savePointsToFile(const std::string& filename, bool append) {
    std::ofstream file(filename, append ? std::ios::app : std::ios::out);
    if (!file) return;

    std::vector<Point3D> vertices = {
        bottomLeftFront,
        {bottomLeftFront.getX() + length, bottomLeftFront.getY(), bottomLeftFront.getZ()},
        {bottomLeftFront.getX() + length, bottomLeftFront.getY() + width, bottomLeftFront.getZ()},
        {bottomLeftFront.getX(), bottomLeftFront.getY() + width, bottomLeftFront.getZ()},

        {bottomLeftFront.getX(), bottomLeftFront.getY(), bottomLeftFront.getZ() + height},
        {bottomLeftFront.getX() + length, bottomLeftFront.getY(), bottomLeftFront.getZ() + height},
        {bottomLeftFront.getX() + length, bottomLeftFront.getY() + width, bottomLeftFront.getZ() + height},
        {bottomLeftFront.getX(), bottomLeftFront.getY() + width, bottomLeftFront.getZ() + height}
    };

    for (const auto& p : vertices) {
        file << p.getX() << " " << p.getY() << " " << p.getZ() << "\n";
    }

    file << "\n\n";
    file.close();
}


std::vector<Point3D> Cuboid::getPoints3D() const {
    return { bottomLeftFront };
}

std::vector<double> Cuboid::getParams() const {
    return { length, width, height };
}

std::string Cuboid::getType() const {
    return "Cuboid";
}
