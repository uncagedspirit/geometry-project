#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    
    // Virtual method for saving points (overridden by each shape)
    virtual void savePointsToFile(const std::string& filename, bool append = false) = 0;
};

#endif