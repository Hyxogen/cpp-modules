#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
        std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) :
    ClapTrap(
        name + "_clap_name", DIATRAP_DEFAULT_HIT_POINTS,
        DIATRAP_DEFAULT_ENERGY_POINTS, DIATRAP_DEFAULT_ATTACK_DMG),
    ScavTrap(), FragTrap(), _name(name) {
        std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) :
    ClapTrap(other), ScavTrap(), FragTrap(), _name(other._name) {
        std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
        std::cout << "DiamondTrap deconstructor called" << std::endl;
}

void DiamondTrap::whoAmI() const {
        std::cout << "DiamondTrap " << _name << " DiamondTrap name: " << _name
                  << " ClapTrap name: " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::type() const {
        return "DiamondTrap";
}

void DiamondTrap::attack(const std::string &target) {
        ScavTrap::attack(target);
}
