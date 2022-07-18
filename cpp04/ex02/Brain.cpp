#include "Brain.hpp"

#include <iostream>
#include <stdexcept>

Brain::Brain() {
        std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
        std::cout << "Brain copy constructor called" << std::endl;
        copy(other._ideas);
}

Brain::~Brain() {
        std::cout << "Brain deconstructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
        std::cout << "Brain copy assignment operator called" << std::endl;
        if (this != &other) {
                copy(other._ideas);
        }
        return *this;
}

std::string &Brain::at(std::size_t idx) {
        if (idx >= BRAIN_IDEA_SIZE) {
                throw std::out_of_range("out of bounds access in Brain");
        }
        return _ideas[idx];
}

void Brain::copy(const std::string ideas[BRAIN_IDEA_SIZE]) {
        for (size_t i = 0; i < BRAIN_IDEA_SIZE; i++) {
                at(i) = std::string(ideas[i]);
        }
}
