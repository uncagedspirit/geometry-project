#include "inputHandler.h"  

//for 2D point
Point2D InputHandler::getInput(Point2D) {  
    double x, y;
    std::cout << "Enter x and y coordinates: ";
    std::cin >> x >> y;
    return Point2D(x, y);
}

//for 3D point
Point3D InputHandler::getInput(Point3D) {  
    double x, y, z;
    std::cout << "Enter x, y and z coordinates: ";
    std::cin >> x >> y >> z;
    return Point3D(x, y, z);
}

// Static-sized 2D array input
TwoPointsArray2D InputHandler::getInput(const TwoPointsArray2D&) {
    TwoPointsArray2D points;
    std::cout << "Enter coordinates for first point: ";
    points[0] = getInput(Point2D());
    std::cout << "Enter coordinates for second point: ";
    points[1] = getInput(Point2D());
    return points;
}

// Static-sized 3D array input
TwoPointsArray3D InputHandler::getInput(const TwoPointsArray3D&) {
    TwoPointsArray3D points;
    std::cout << "Enter coordinates for first point: ";
    points[0] = getInput(Point3D());
    std::cout << "Enter coordinates for second point: ";
    points[1] = getInput(Point3D());
    return points;
}

// ThreePointsArray2D input
ThreePointsArray2D InputHandler::getInput(const ThreePointsArray2D&) {
    ThreePointsArray2D points;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter coordinates for point " << i + 1 << ": ";
        points[i] = getInput(Point2D());
    }
    return points;
}

// ThreePointsArray3D input
ThreePointsArray3D InputHandler::getInput(const ThreePointsArray3D&) {
    ThreePointsArray3D points;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter coordinates for point " << i + 1 << ": ";
        points[i] = getInput(Point3D());
    }
    return points;
}

// Dynamic-sized 2D points array
PointVector2D InputHandler::getInput(const PointVector2D&, int numPoints) {
    PointVector2D points(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Enter coordinates for point " << i + 1 << ": ";
        points[i] = getInput(Point2D());
    }
    return points;
}

// Dynamic-sized 3D points array
PointVector3D InputHandler::getInput(const PointVector3D&, int numPoints) {
    PointVector3D points(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Enter coordinates for point " << i + 1 << ": ";
        points[i] = getInput(Point3D());
    }
    return points;
}

// Circle input
Circle InputHandler::getInput(Circle) { 
    std::cout << "Enter circle center coordinates: ";
    Point2D center = InputHandler::getInput(Point2D());  

    double radius;
    std::cout << "Enter radius: ";
    std::cin >> radius;

    return Circle(center, radius);
}

//rectangle input
Rectangle InputHandler::getInput(Rectangle) {  
    std::cout << "Enter bottom left corner coordinates: ";
    Point2D bottomLeft = InputHandler::getInput(Point2D());  

    double width, height;
    std::cout << "Enter width and height: ";
    std::cin >> width >> height;

    return Rectangle(bottomLeft, width, height);
}

Square InputHandler::getInput(Square) {
    std::cout << "Enter bottom-left corner coordinates: ";
    Point2D bottomLeft = getInput(Point2D());

    double side;
    std::cout << "Enter side length: ";
    std::cin >> side;

    return Square(bottomLeft, side);
}






