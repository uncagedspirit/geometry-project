#include "transformer.h"
#include <iostream>
#include <map>
#include <functional>
#include "circle.h"
#include "rectangle.h"
#include "sphere.h"
#include "cube.h"

static std::map<std::string, std::function<Shape*(const std::vector<Point2D>&, const std::vector<double>&)>> shape2DCreators = {
    { "Circle", [](const std::vector<Point2D>& pts, const std::vector<double>& p) { return new Circle(pts[0], p[0]); } },
    { "Rectangle", [](const std::vector<Point2D>& pts, const std::vector<double>& p) { return new Rectangle(pts[0], p[0], p[1]); } }
};

static std::map<std::string, std::function<Shape*(const std::vector<Point3D>&, const std::vector<double>&)>> shape3DCreators = {
    { "Sphere", [](const std::vector<Point3D>& pts, const std::vector<double>& p) { return new Sphere(pts[0], p[0]); } },
    { "Cube", [](const std::vector<Point3D>& pts, const std::vector<double>& p) { return new Cube(pts[0], p[0]); } }
};

Shape* Transformer::transform(std::vector<Point2D> points, std::vector<double> params, std::string shapeType) {
    std::vector<Point2D> updatedPoints = points;
    std::vector<double> updatedParams = params;

    std::cout << "Select 2D transformation (1: Scale, 2: Rotate, 3: Translate): ";
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: {
            double factor;
            std::cout << "Enter scaling factor: ";
            std::cin >> factor;
            updatedParams = scale(params, factor);
            break;
        }
        case 2: {
            char axis;
            double angle;
            std::cout << "Enter axis (x/y): ";
            std::cin >> axis;
            std::cout << "Enter angle in degrees: ";
            std::cin >> angle;
            updatedPoints = rotate(points, axis, angle);
            break;
        }
        case 3: {
            double dx, dy;
            std::cout << "Enter translation (dx dy): ";
            std::cin >> dx >> dy;
            updatedPoints = translate(points, dx, dy);
            break;
        }
        default:
            std::cout << "Invalid transformation type.\n";
    }

    return createShape2D(shapeType, updatedPoints, updatedParams);
}

Shape* Transformer::transform(std::vector<Point3D> points, std::vector<double> params, std::string shapeType) {
    std::vector<Point3D> updatedPoints = points;
    std::vector<double> updatedParams = params;

    std::cout << "Select 3D transformation (1: Scale, 2: Rotate, 3: Translate): ";
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: {
            double factor;
            std::cout << "Enter scaling factor: ";
            std::cin >> factor;
            updatedParams = scale(params, factor);
            break;
        }
        case 2: {
            char axis;
            double angle;
            std::cout << "Enter axis (x/y/z): ";
            std::cin >> axis;
            std::cout << "Enter angle in degrees: ";
            std::cin >> angle;
            updatedPoints = rotate(points, axis, angle);
            break;
        }
        case 3: {
            double dx, dy, dz;
            std::cout << "Enter translation (dx dy dz): ";
            std::cin >> dx >> dy >> dz;
            updatedPoints = translate(points, dx, dy, dz);
            break;
        }
        default:
            std::cout << "Invalid transformation type.\n";
    }

    return createShape3D(shapeType, updatedPoints, updatedParams);
}

Shape* Transformer::createShape2D(const std::string& type, const std::vector<Point2D>& points, const std::vector<double>& params) {
    auto it = shape2DCreators.find(type);
    return (it != shape2DCreators.end()) ? it->second(points, params) : nullptr;
}

Shape* Transformer::createShape3D(const std::string& type, const std::vector<Point3D>& points, const std::vector<double>& params) {
    auto it = shape3DCreators.find(type);
    return (it != shape3DCreators.end()) ? it->second(points, params) : nullptr;
}
