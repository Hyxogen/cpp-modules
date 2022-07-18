#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
        std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain)) {
        std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
        std::cout << "Dog deconstructor called" << std::endl;
        delete _brain;
}

Dog &Dog::operator=(const Dog &other) {
        std::cout << "Dog copy assignment operator called" << std::endl;
        if (this != &other) {
                Animal::operator=(other);
                *_brain         = Brain(*other._brain);
        }
        return *this;
}

void Dog::makeSound() const {
        std::cout << "[Dog Noises]" << std::endl;
}

Brain *Dog::getBrain() {
        return _brain;
}
