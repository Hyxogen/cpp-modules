#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() :
    ClapTrap(
        "SC4V-TP", SCAVTRAP_DEFAULT_HIT_POINTS, SCAVTRAP_DEFAULT_ENERGY_POINTS,
        SCAVTRAP_DEFAULT_ATTACK_DMG) {
        std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) :
    ClapTrap(
        name, SCAVTRAP_DEFAULT_HIT_POINTS, SCAVTRAP_DEFAULT_ENERGY_POINTS,
        SCAVTRAP_DEFAULT_ATTACK_DMG) {
        std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
        std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
        std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	attack_base(target, "ScavTrap");
}

void ScavTrap::guardGate() {
        if (_energy_points == 0) {
                std::cout << *this
                          << " does not have enough energy points to enter "
                             "gate keeper mode!"
                          << std::endl;
                return;
        }
        --_energy_points;
        std::cout << *this << " has entered gate keeping mode!" << std::endl;
}
