#include <iostream>
#include "geometryHeaders.h"
#include "inputHandler.h"

void execute(int n){
    switch (n){
        case 1: {
            Circle circle = InputHandler::getInput(Circle());
            break;
        }
        case 2: {
            Rectangle rectangle = InputHandler::getInput(Rectangle());
            break;
        }   
        case 3: {
            Square square = InputHandler::getInput(Square());
            break;
        }
        case 4: {
            Cuboid cuboid = InputHandler::getInput(Cuboid());
            break;
        }
        case 5: {
            Cube cube = InputHandler::getInput(Cube());
            break;
        }
        case 6: {
            Sphere sphere = InputHandler::getInput(Sphere());
            break;
        }
        default: {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    std::cout << "Do you want to transform the shape? (y/n): ";
    char transformChoice;
    std::cin >> transformChoice;
    if (transformChoice == 'y' || transformChoice == 'Y') {
        std::cout << "Transforming the shape..." << std::endl;
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
