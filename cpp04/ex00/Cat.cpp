#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat") {
        std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
        std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
        std::cout << "Cat deconstructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
        std::cout << "Cat copy assignment operator called" << std::endl;
        return *static_cast<Cat *>(&Animal::operator=(other));
}

void Cat::makeSound() const {
        std::cout << "[Cat Noises]" << std::endl;
}
