#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
    int              _data;
    const static int POINT;

public:
    Fixed();
    Fixed(const Fixed &other);

    ~Fixed();

    Fixed &operator=(const Fixed &other);

    int  getRawBits() const;
    void setRawBits(int raw);
};

#endif
