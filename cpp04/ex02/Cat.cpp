#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
        std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain)) {
        std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
        std::cout << "Cat deconstructor called" << std::endl;
        delete _brain;
}

Cat &Cat::operator=(const Cat &other) {
        std::cout << "Cat copy assignment operator called" << std::endl;
        if (this != &other) {
                *_brain = Brain(*other._brain);
        }
        return *this;
}

void Cat::makeSound() const {
        std::cout << "[Cat Noises]" << std::endl;
}

Brain *Cat::getBrain() {
        return _brain;
}
