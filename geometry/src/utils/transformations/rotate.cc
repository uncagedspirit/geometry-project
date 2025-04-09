/*
a rotate function or class is passed a shape and transform the points of the shape, store them 
temp into some variables and later create a new obj using the same variables

eg 

transform(shapename){
apply transform logic on single points from the shape
    transformmatrix logic and all for all points in a loop
    then store the points in a temp data strucutre for now
}

later create a new obj of the shape, eg for circle use transformed point and radiusand create new obj 
and then return it

to whoever you will return it to will handle what he wants to do with it rather than 
this function doing saving and all.
we have applied transformation created shape, the receiver will see what he wants to do with the object of the shape

*/

//dummy code for testing change later

#include "transformer.h"
#include <iostream>

std::vector<Point2D> Transformer::rotate(std::vector<Point2D> points, char axis, double angle) {
    std::cout << "[Dummy] Rotating 2D around " << axis << "-axis by " << angle << " degrees.\n";
    return points;
}

std::vector<Point3D> Transformer::rotate(std::vector<Point3D> points, char axis, double angle) {
    std::cout << "[Dummy] Rotating 3D around " << axis << "-axis by " << angle << " degrees.\n";
    return points;
}
