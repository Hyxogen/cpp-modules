#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    public:
        const Fixed x, y;

        Point();
        Point(const Fixed &x, const Fixed &y);
        Point(const Point &other);

        ~Point();

        Point operator+(const Point &other) const;
        Point operator-(const Point &other) const;

    private:
        Point &operator=(const Point &other); /* deleted */
};

#endif
