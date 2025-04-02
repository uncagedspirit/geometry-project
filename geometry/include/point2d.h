#ifndef POINT2D_H
#define POINT2D_H

class Point2D {
private:
    double x, y;

public:
    Point2D(double x = 0, double y = 0);

    // Getters
    double getX() const;
    double getY() const;

    // Setters
    void setX(double x);
    void setY(double y);
};

#endif // POINT2D_H
