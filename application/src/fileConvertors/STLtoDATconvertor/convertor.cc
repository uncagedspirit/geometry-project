#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Vec3 {
    float x, y, z;
};

std::vector<Vec3> points;

void readSTL(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    Vec3 vertex;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string word;
        ss >> word;
        if (word == "vertex") {
            ss >> vertex.x >> vertex.y >> vertex.z;
            points.push_back(vertex);
        }
    }
}

void writeDAT(const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& p : points) {
        file << p.x << " " << p.y << " " << p.z << "\n";
    }
}

int main() {
    std::string stlFile = "model.stl";
    std::string datFile = "model.dat";

    readSTL(stlFile);
    writeDAT(datFile);

    std::cout << "Conversion completed: " << datFile << "\n";
    return 0;
}
