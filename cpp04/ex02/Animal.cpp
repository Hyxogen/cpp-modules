#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("Animal") {
        std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type) {
        std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
        std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
        std::cout << "Animal deconstructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
        std::cout << "Animal copy assignment operator called" << std::endl;
        (void) other;
        return *this;
}

const std::string &Animal::getType() const {
        return type;
}
