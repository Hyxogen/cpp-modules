#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
    int              _data;
    const static int POINT;

public:
    Fixed();
    Fixed(int value);
    Fixed(float value);
    Fixed(const Fixed &other);

    ~Fixed();

    Fixed      &operator=(const Fixed &other);
    bool        operator==(const Fixed &other) const;
    bool        operator!=(const Fixed &other) const;
    bool        operator>(const Fixed &other) const;
    bool        operator<(const Fixed &other) const;
    bool        operator>=(const Fixed &other) const;
    bool        operator<=(const Fixed &other) const;
    Fixed       operator+(const Fixed &other) const;
    Fixed       operator-(const Fixed &other) const;
    Fixed       operator*(const Fixed &other) const;
    Fixed       operator/(const Fixed &other) const;
    Fixed      &operator++();
    const Fixed operator++(int);
    Fixed      &operator--();
    const Fixed operator--(int);

    static Fixed       &min(Fixed &left, Fixed &right);
    static const Fixed &min(const Fixed &left, const Fixed &right);
    static Fixed       &max(Fixed &left, Fixed &right);
    static const Fixed &max(const Fixed &left, const Fixed &right);

    int   getRawBits() const;
    void  setRawBits(int raw);
    int   toInt() const;
    float toFloat() const;
};
std::ostream &operator<<(std::ostream &stream, const Fixed &fixed);

#endif
