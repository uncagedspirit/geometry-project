#include <iostream>
#include "geometryHeaders.h"
#include "inputHandler.h"
#include "transformer.h"


#include <memory>  // Add this at the top

void execute(int n){
    std::unique_ptr<Shape> shape;

    switch (n){
        case 1: {
            shape = std::make_unique<Circle>(InputHandler::getInput(Circle()));
            break;
        }
        case 2: {
            shape = std::make_unique<Rectangle>(InputHandler::getInput(Rectangle()));
            break;
        }   
        case 3: {
            shape = std::make_unique<Square>(InputHandler::getInput(Square()));
            break;
        }
        case 4: {
            shape = std::make_unique<Cuboid>(InputHandler::getInput(Cuboid()));
            break;
        }
        case 5: {
            shape = std::make_unique<Cube>(InputHandler::getInput(Cube()));
            break;
        }
        case 6: {
            shape = std::make_unique<Sphere>(InputHandler::getInput(Sphere()));
            break;
        }
        default: {
            std::cout << "Invalid choice. Please try again." << std::endl;
            return;
        }
    }

    std::cout << "Do you want to transform the shape? (y/n): ";
    char transformChoice;
    std::cin >> transformChoice;
    if (transformChoice == 'y' || transformChoice == 'Y') {
        if (auto* s2d = dynamic_cast<Shape2D*>(shape.get())) {
            Transformer::transform(s2d->getPoints2D(), shape->getParams(), shape->getType());
        } else if (auto* s3d = dynamic_cast<Shape3D*>(shape.get())) {
            Transformer::transform(s3d->getPoints3D(), shape->getParams(), shape->getType());
        }
        std::cout << "Transformation applied." << std::endl;
    }
}


// Display menu
int displayMenu() {
    std::cout << "\nSelect a shape to create and plot:\n";
    std::cout << "0. Exit\n";
    std::cout<<"1. circle\n";
    std::cout<<"2. rectangle\n";     
    std::cout<<"3. square\n";
    std::cout<<"4. cuboid\n";
    std::cout<<"5. cube\n";
    std::cout<<"6. Sphere\n";
    
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    return choice;
}


int main() {
    bool cont = true;
    
    do {
        int choice = displayMenu();
        if (choice == 0) {
            cont = false;
        } else {
            execute(choice);
        }
    } while (cont);
}
