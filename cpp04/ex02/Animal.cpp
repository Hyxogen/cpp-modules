#include "Animal.hpp"

#include <iostream>

Animal::Animal() : _type("Animal") {
        std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {
        std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
        std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
        std::cout << "Animal deconstructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
        std::cout << "Animal copy assignment operator called" << std::endl;
        if (this != &other) {
                _type = other._type;
        }
        return *this;
}

const std::string &Animal::getType() const {
        return _type;
}
