#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) { }

Weapon::Weapon(const Weapon &other) : _type(other._type) { }

Weapon::~Weapon() { }

const std::string &Weapon::getType() const {
    return _type;
}

void Weapon::setType(const std::string &type) {
    _type = type;
}

Weapon &Weapon::operator=(const Weapon &other) {
    if (this == &other) {
        return *this;
    }
    _type = other._type;
    return *this;
}
