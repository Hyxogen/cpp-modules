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

    Fixed &operator=(const Fixed &other);

    int   getRawBits() const;
    void  setRawBits(int raw);
    int   toInt() const;
    float toFloat() const;
};
std::ostream &operator<<(std::ostream &stream, const Fixed &fixed);

#endif
