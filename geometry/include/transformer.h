#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <vector>
#include <string>
#include <iostream>
#include "point2d.h"
#include "point3d.h"

class Transformer {
public:
    // 2D transform
    static void transform(std::vector<Point2D> points, std::vector<double> params, std::string shapeType) {
        std::cout << "Select 2D transformation (1: Scale, 2: Rotate, 3: Translate): ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double factor;
                std::cout << "Enter scaling factor: ";
                std::cin >> factor;
                std::vector<double> newParams = scale(params, factor);
                break;
            }
            case 2: {
                char axis;
                double angle;
                std::cout << "Enter axis (x/y): ";
                std::cin >> axis;
                std::cout << "Enter angle in degrees: ";
                std::cin >> angle;
                std::vector<Point2D> newPoints = rotate(points, axis, angle);
                break;
            }
            case 3: {
                double dx, dy;
                std::cout << "Enter translation (dx dy): ";
                std::cin >> dx >> dy;
                std::vector<Point2D> newPoints = translate(points, dx, dy);
                break;
            }
            default:
                std::cout << "Invalid transformation type.\n";
        }
    }

    // 3D transform
    static void transform(std::vector<Point3D> points, std::vector<double> params, std::string shapeType) {
        std::cout << "Select 3D transformation (1: Scale, 2: Rotate, 3: Translate): ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double factor;
                std::cout << "Enter scaling factor: ";
                std::cin >> factor;
                std::vector<double> newParams = scale(params, factor);
                break;
            }
            case 2: {
                char axis;
                double angle;
                std::cout << "Enter axis (x/y/z): ";
                std::cin >> axis;
                std::cout << "Enter angle in degrees: ";
                std::cin >> angle;
                std::vector<Point3D> newPoints = rotate(points, axis, angle);
                break;
            }
            case 3: {
                double dx, dy, dz;
                std::cout << "Enter translation (dx dy dz): ";
                std::cin >> dx >> dy >> dz;
                std::vector<Point3D> newPoints = translate(points, dx, dy, dz);
                break;
            }
            default:
                std::cout << "Invalid transformation type.\n";
        }
    }

private:
    static std::vector<Point2D> rotate(std::vector<Point2D> points, char axis, double angle);
    static std::vector<Point2D> translate(std::vector<Point2D> points, double dx, double dy);
    static std::vector<double> scale(std::vector<double> params, double factor);
    static std::vector<Point3D> rotate(std::vector<Point3D> points, char axis, double angle);
    static std::vector<Point3D> translate(std::vector<Point3D> points, double dx, double dy, double dz);
};

#endif
