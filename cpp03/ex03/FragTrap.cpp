#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() :
    ClapTrap(
        "FR4G-TP", FRAGTRAP_DEFAULT_HIT_POINTS, FRAGTRAP_DEFAULT_ENERGY_POINTS,
        FRAGTRAP_DEFAULT_ATTACK_DMG) {
        std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) :
    ClapTrap(
        name, FRAGTRAP_DEFAULT_HIT_POINTS, FRAGTRAP_DEFAULT_ENERGY_POINTS,
        FRAGTRAP_DEFAULT_ATTACK_DMG) {
        std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
        std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
        std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
        if (_energy_points == 0) {
		std::cout << "FragTrap " << _name << " does not have enough energy points to ask for "
                             "high fives!"
                          << std::endl;
                return;
        }
        --_energy_points;
        std::cout << "FragTrap " << _name << ": \"Gimme five!\"" << std::endl;
}
