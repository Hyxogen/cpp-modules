#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
        std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
        std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
        std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
        std::cout << "WrongAnimal deconstructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
        std::cout << "WrongAnimal copy assignment operator called" << std::endl;
        if (this != &other) {
                _type = other._type;
        }
        return *this;
}

void WrongAnimal::makeSound() const {
        std::cout << "[WrongAnimal Noises]" << std::endl;
}

const std::string &WrongAnimal::getType() const {
        return _type;
}
