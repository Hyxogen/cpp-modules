#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria() : _type("unknown") { }

AMateria::AMateria(const std::string &type) : _type(type) { }

AMateria::AMateria(const AMateria &other) : _type(other._type) { }

AMateria::~AMateria() { }

AMateria &AMateria::operator=(const AMateria &other) {
        if (this != &other) {
                _type = other._type;
        }
        return *this;
}

const std::string &AMateria::getType() const {
        return _type;
}

void AMateria::use(ICharacter &target) {
        std::cout << "* some unknown magic in the general direction of "
                  << target.getName() << " *" << std::endl;
}
