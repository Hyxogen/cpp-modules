#include "Fixed.hpp"

#include <ostream>

const int Fixed::POINT = 8;

Fixed::Fixed() : _data(0) { }

Fixed::Fixed(const int value) : _data(value << Fixed::POINT) { }

Fixed::Fixed(const float value) :
    _data(static_cast<int>((1 << Fixed::POINT) * value)) { }

Fixed::Fixed(const Fixed &other) : _data(other._data) { }

Fixed::~Fixed() { }

Fixed &Fixed::operator=(const Fixed &other) {
    if (this == &other) {
        return *this;
    }
    _data = other._data;
    return *this;
}

bool Fixed::operator==(const Fixed &other) const {
    return getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    return !(*this == other);
}

bool Fixed::operator>(const Fixed &other) const {
    return _data > other._data;
}

bool Fixed::operator<(const Fixed &other) const {
    return _data < other._data;
}

bool Fixed::operator>=(const Fixed &other) const {
    return _data >= other._data;
}

bool Fixed::operator<=(const Fixed &other) const {
    return _data <= other._data;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result(*this);
    result._data += other._data;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result(*this);
    result._data -= other._data;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result(*this);
    result._data *= other._data;
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result(*this);
    result._data /= other._data;
    return result;
}

Fixed &Fixed::operator++() {
    ++_data;
    return *this;
}

const Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++_data;
    return temp;
}

Fixed &Fixed::operator--() {
    --_data;
    return *this;
}

const Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --_data;
    return (temp);
}

Fixed &Fixed::min(Fixed &left, Fixed &right) {
    if (left < right) {
        return left;
    }
    return right;
}

const Fixed &Fixed::min(const Fixed &left, const Fixed &right) {
    if (left < right) {
        return left;
    }
    return right;
}

Fixed &Fixed::max(Fixed &left, Fixed &right) {
    if (left > right) {
        return left;
    }
    return right;
}

const Fixed &Fixed::max(const Fixed &left, const Fixed &right) {
    if (left > right) {
        return left;
    }
    return right;
}

int Fixed::getRawBits() const {
    return _data;
}

void Fixed::setRawBits(const int raw) {
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
