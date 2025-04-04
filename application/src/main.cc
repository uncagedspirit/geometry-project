#include <iostream>
#include "inputHandler.h"
#include "line2d.h"
#include "line3d.h"

int main() {
//2d line input test
    // std::cout << "Testing 2D Line Input\n";
    // TwoPointsArray2D points2D = InputHandler::getInput(TwoPointsArray2D());
    // Line2D line2D;
    // line2D.setStart(points2D[0]);
    // line2D.setEnd(points2D[1]);
    // std::cout << "2D Line Created!\n";

//3d line input test
    // std::cout << "\nTesting 3D Line Input\n";
    // TwoPointsArray3D points3D = InputHandler::getInput(TwoPointsArray3D());
    // Line3D line3D;
    // line3D.setStart(points3D[0]);
    // line3D.setEnd(points3D[1]);
    // std::cout << "3D Line Created!\n";

//circle input test    
    // std::cout << "Testing Circle Input\n";
    // Circle circle = InputHandler::getInput(Circle());
    // std::cout << "Circle Created!\n";

//rectangle input test
    // std::cout << "Testing Rectangle Input\n";
    // Rectangle rectangle = InputHandler::getInput(Rectangle());
    // std::cout << "Rectangle Created!\n";


//square input test
    // std::cout << "Testing Square Input\n";
    // Square square = InputHandler::getInput(Square());
    // std::cout << "Square Created!\n";

//cuboid input test
    std::cout << "Testing Cuboid Input\n";  
    Cuboid cuboid = InputHandler::getInput(Cuboid());
    std::cout << "Cuboid Created!\n";

    return 0;
}
