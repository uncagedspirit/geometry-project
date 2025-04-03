#include "line2d.h"
#include <fstream>
#include <iostream>

// Constructor
Line2D::Line2D(const Point2D& start, const Point2D& end) : start(start), end(end) {}

// Getters
Point2D Line2D::getStart() const { return start; }
Point2D Line2D::getEnd() const { return end; }

// Setters
void Line2D::setStart(const Point2D& start) { this->start = start; }
void Line2D::setEnd(const Point2D& end) { this->end = end; }


//methods

//save points function is implemented here itself to preserve encapsulation property for the shape
//so instead of creating a general interface to save points of eac hshape to a file,
//this approach is better since each shape anyways have unique logic for points

// Save points of the line to a file
void Line2D::savePointsToFile(const std::string& filename, bool appendMode) {
    std::ofstream file;

    if (appendMode) file.open(filename, std::ios::app);
    else file.open(filename, std::ios::out);

    //error hadling
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Write points to the file 
    file << start.getX() << " " << start.getY() << "\n";
    file << end.getX() << " " << end.getY() << "\n\n";

    file.close();
}

//call to this:     line2.savePointsToFile("lines.dat", true); 
// Save points of line 2 to the same file (append)
