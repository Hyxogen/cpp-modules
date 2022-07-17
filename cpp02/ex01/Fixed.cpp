#include "Fixed.hpp"

#include <iostream>

const int Fixed::POINT = 8;

Fixed::Fixed() : _data(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _data(value << Fixed::POINT) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) :
    _data(static_cast<int>((1 << Fixed::POINT) * value)) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _data(other._data) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy operator called" << std::endl;
    if (this == &other) {
        return *this;
    }
    _data = other._data;
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits called" << std::endl;
    return _data;
}

void Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits called" << std::endl;
    _data = raw;
}

int Fixed::toInt() const {
    return _data >> Fixed::POINT;
}

float Fixed::toFloat() const {
    return static_cast<float>(_data) / (1 << Fixed::POINT);
}

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed) {
    stream << fixed.toFloat();
    return stream;
}
