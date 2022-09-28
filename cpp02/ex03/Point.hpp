#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
        const Fixed _x, _y;

    public:
        Point();
        Point(const Fixed &x, const Fixed &y);
        Point(const Point &other);

        ~Point();

        Point operator+(const Point &other) const;
        Point operator-(const Point &other) const;

        /* deprecated */
        Point &operator=(const Point &other);

        const Fixed &x() const;
        const Fixed &y() const;
};

#endif
