#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point);

int main() {
    const Point a(1, 1);
    const Point b(4, 2);
    const Point c(2, 7);
    std::cout << "should be in triangle: " << bsp(a, b, c, Point(2, 3))
              << std::endl;
    std::cout << "should be in triangle: " << bsp(a, b, c, a) << std::endl;
    std::cout << "should be in triangle: " << bsp(a, b, c, b) << std::endl;
    std::cout << "should be in triangle: " << bsp(a, b, c, c) << std::endl;

    std::cout << "should be outside of triangle: "
              << bsp(a, b, c, Point(1.5f, 5)) << std::endl;
    std::cout << "should be outside of triangle: "
              << bsp(a, b, c, Point(-1, -1)) << std::endl;
    return 0;
}
