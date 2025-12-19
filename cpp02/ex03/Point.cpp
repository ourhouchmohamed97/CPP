#include "Point.hpp"


Point::Point() : x(0), y(0) {}

Point::Point( const float f1, const float f2 ) : x(f1), y(f2) {}

Point::Point( const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=( const Point& other ) {
    (void)other;
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const { return x; }
Fixed Point::getY() const { return y; }