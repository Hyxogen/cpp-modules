#include "Point.hpp"

Point::Point() : _x(0), _y(0) { }

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y) { }

Point::Point(const Point &other) : _x(other._x), _y(other._y) { }

Point::~Point() { }

Point Point::operator+(const Point &other) const {
        Point result(_x + other._x, _y + other._y);
        return result;
}

Point Point::operator-(const Point &other) const {
        Point result(_x - other._x, _y - other._y);
        return result;
}

Point &Point::operator=(const Point &other) {
        (void) other;
        return *this;
}

const Fixed &Point::x() const {
        return _x;
}

const Fixed &Point::y() const {
        return _y;
}
