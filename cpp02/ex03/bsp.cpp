#include "Point.hpp"

bool bsp(const Point &a, const Point &b, const Point &c, const Point &p) {
    const Point q(p - a);
    const Point r(b - a);
    const Point s(c - a);

    const float denom = ((s.y * r.x) - (s.x * r.y)).toFloat();
    const float w     = ((q.y * r.x) - (q.x * r.y)).toFloat() / denom;
    const float v     = ((q.y * s.x) - (q.x * s.y)).toFloat() / -denom;
    return v >= 0.0F && w >= 0.0F && v + w <= 1.0F;
}
