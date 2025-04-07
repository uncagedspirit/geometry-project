#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <array>  // ✅ required for std::array

struct Vec3 {
    float x, y, z;

    bool operator<(const Vec3& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
};

std::vector<Vec3> vertices;
std::vector<std::array<int, 3>> faces;
std::map<Vec3, int> vertexMap;

int getVertexIndex(const Vec3& v) {
    if (vertexMap.count(v)) return vertexMap[v];
    vertices.push_back(v);
    int idx = vertices.size();
    vertexMap[v] = idx;
    return idx;
}

void readSTL(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open STL file: " << filename << "\n";
        return;
    }

    std::string line;
    Vec3 v[3];
    int count = 0;

    while (getline(file, line)) {
        if (line.find("vertex") != std::string::npos) {
            std::stringstream ss(line);
            std::string temp;
            ss >> temp >> v[count].x >> v[count].y >> v[count].z;
            count++;
            if (count == 3) {
                std::array<int, 3> face = {
                    getVertexIndex(v[0]),
                    getVertexIndex(v[1]),
                    getVertexIndex(v[2])
                };
                faces.push_back(face);
                count = 0;
            }
        }
    }
}

void writeOBJ(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to write OBJ file: " << filename << "\n";
        return;
    }

    std::cout << "Vertices: " << vertices.size() << ", Faces: " << faces.size() << "\n";

    for (const auto& v : vertices)
        file << "v " << v.x << " " << v.y << " " << v.z << "\n";
    for (const auto& f : faces)
        file << "f " << f[0] << " " << f[1] << " " << f[2] << "\n";
}


int main() {
    std::string stlFile = "model.stl";
    std::string objFile = "model.obj";

    readSTL(stlFile);
    writeOBJ(objFile);

    std::cout << "Converted STL to OBJ: " << objFile << "\n";
    return 0;
}
