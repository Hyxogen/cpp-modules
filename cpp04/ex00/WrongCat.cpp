#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
        std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
        std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
        std::cout << "WrongCat deconstructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
        std::cout << "WrongCat copy assignment operator called" << std::endl;
        return *static_cast<WrongCat *>(&WrongAnimal::operator=(other));
}
