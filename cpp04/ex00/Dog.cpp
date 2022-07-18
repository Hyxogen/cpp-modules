#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog") {
        std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
        std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
        std::cout << "Dog deconstructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
        std::cout << "Dog copy assignment operator called" << std::endl;
        return *static_cast<Dog *>(&Animal::operator=(other));
}

void Dog::makeSound() const {
        std::cout << "[Dog Noises]" << std::endl;
}
