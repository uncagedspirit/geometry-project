#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <cmath>

struct Vec3 {
    float x, y, z;
};

std::vector<Vec3> vertices;
std::vector<std::array<int, 3>> faces;

Vec3 computeNormal(const Vec3& a, const Vec3& b, const Vec3& c) {
    Vec3 u {b.x - a.x, b.y - a.y, b.z - a.z};
    Vec3 v {c.x - a.x, c.y - a.y, c.z - a.z};
    Vec3 normal {
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    };
    float length = std::sqrt(normal.x*normal.x + normal.y*normal.y + normal.z*normal.z);
    if (length > 0) {
        normal.x /= length;
        normal.y /= length;
        normal.z /= length;
    }
    return normal;
}

void readOBJ(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        ss >> type;
        if (type == "v") {
            Vec3 v;
            ss >> v.x >> v.y >> v.z;
            vertices.push_back(v);
        } else if (type == "f") {
            std::array<int, 3> face;
            for (int i = 0; i < 3; ++i) {
                std::string vertex;
                ss >> vertex;
                std::stringstream vs(vertex);
                std::string indexStr;
                getline(vs, indexStr, '/');
                face[i] = std::stoi(indexStr) - 1;
            }
            faces.push_back(face);
        }
    }
}

void writeSTL(const std::string& filename) {
    std::ofstream file(filename);
    file << "solid model\n";
    for (auto& face : faces) {
        Vec3 a = vertices[face[0]];
        Vec3 b = vertices[face[1]];
        Vec3 c = vertices[face[2]];
        Vec3 normal = computeNormal(a, b, c);
        file << "  facet normal " << normal.x << " " << normal.y << " " << normal.z << "\n";
        file << "    outer loop\n";
        file << "      vertex " << a.x << " " << a.y << " " << a.z << "\n";
        file << "      vertex " << b.x << " " << b.y << " " << b.z << "\n";
        file << "      vertex " << c.x << " " << c.y << " " << c.z << "\n";
        file << "    endloop\n";
        file << "  endfacet\n";
    }
    file << "endsolid model\n";
}

int main() {
    std::string objFile = "city.obj";
    std::string stlFile = "model.stl";

    readOBJ(objFile);
    writeSTL(stlFile);

    std::cout << "Conversion completed: " << stlFile << "\n";
    return 0;
}
