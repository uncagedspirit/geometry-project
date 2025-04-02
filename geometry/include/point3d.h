#ifndef POINT3D_H
#define POINT3D_H

class Point3D {
private:
    double x, y, z;

public:
    // Constructor
    Point3D(double x = 0, double y = 0, double z = 0);

    // Getters
    double getX() const;
    double getY() const;
    double getZ() const;

    // Setters
    void setX(double x);
    void setY(double y);
    void setZ(double z);

};

#endif 
