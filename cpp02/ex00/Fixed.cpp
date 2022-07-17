#include "Fixed.hpp"

#include <iostream>

const int Fixed::POINT = 8;

Fixed::Fixed() : _data(0) {
    std::cout << "Default constructor called" << std::endl;
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
