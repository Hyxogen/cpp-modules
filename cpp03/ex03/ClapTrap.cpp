#include "ClapTrap.hpp"

#include <iostream>

#ifndef CLAPTRAP_DEFAULT_HIT_POINTS
# define CLAPTRAP_DEFAULT_HIT_POINTS 10
#elif CLAPTRAP_DEFAULT_HIT_POINTS < 0
# error "CLAPTRAP_DEFAULT_HIT_POINTS may not be negative"
#endif

#ifndef CLAPTRAP_DEFAULT_ENERGY_POINTS
# define CLAPTRAP_DEFAULT_ENERGY_POINTS 10
#elif CLAPTRAP_DEFAULT_ENERGY_POINTS < 0
# error "CLAPTRAP_DEFAULT_ENERGY_POINTS may not be negative"
#endif

#ifndef CLAPTRAP_DEFAULT_ATTACK_DMG
# define CLAPTRAP_DEFAULT_ATTACK_DMG 0
#elif CLAPTRAP_DEFAULT_ATTACK_DMG < 0
# error "CLAPTRAP_DEFAULT_ATTACK_DMG may not be negative"
#endif

ClapTrap::ClapTrap() :
    _name("CL4P-TP"), _hit_points(CLAPTRAP_DEFAULT_HIT_POINTS),
    _energy_points(CLAPTRAP_DEFAULT_ENERGY_POINTS),
    _attack_dmg(CLAPTRAP_DEFAULT_ATTACK_DMG) {
        std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(
    const std::string &name, unsigned int hit_points,
    unsigned int energy_points, unsigned int attack_dmg) :
    _name(name),
    _hit_points(hit_points), _energy_points(energy_points),
    _attack_dmg(attack_dmg) {
        std::cout << "ClapTrap protected constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) :
    _name(name), _hit_points(CLAPTRAP_DEFAULT_HIT_POINTS),
    _energy_points(CLAPTRAP_DEFAULT_ENERGY_POINTS),
    _attack_dmg(CLAPTRAP_DEFAULT_ATTACK_DMG) {
        std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) :
    _name(other._name), _hit_points(other._hit_points),
    _energy_points(other._energy_points), _attack_dmg(other._attack_dmg) {
        std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
        std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
        if (this != &other) {
                _name          = other._name;
                _hit_points    = other._hit_points;
                _energy_points = other._energy_points;
                _attack_dmg    = other._attack_dmg;
        }
        return *this;
}

void ClapTrap::attack(const std::string &target) {
        if (_energy_points == 0) {
                std::cout << *this
                          << " did not have enough energy points to attack!"
                          << std::endl;
                return;
        }
        --_energy_points;
        std::cout << *this << " attacks " << target << ", causing "
                  << _attack_dmg << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
        if (amount > _hit_points) {
                std::cout << *this << " took " << _hit_points
                          << " points of damage!" << std::endl;
                _hit_points = 0;
        } else {
                std::cout << *this << " took " << amount << " points of damage!"
                          << std::endl;
                _hit_points -= amount;
        }
}

void ClapTrap::beRepaired(const unsigned int amount) {
        if (_energy_points == 0) {
                std::cout
                    << *this
                    << " did not have enough energy points to repair itself!"
                    << std::endl;
        }
        --_energy_points;
        const unsigned int maxv = std::numeric_limits<unsigned int>::max();
        if (maxv - amount < _hit_points) {
                std::cout << *this << " is now at full hp!" << std::endl;
                _hit_points = maxv;
        } else {
                std::cout << *this << " was repaired for " << amount
                          << " hit points!" << std::endl;
                _hit_points += amount;
        }
}

const std::string &ClapTrap::name() const {
        return _name;
}

std::string ClapTrap::type() const {
        return "ClapTrap";
}

std::ostream &operator<<(std::ostream &stream, const ClapTrap &clap_trap) {
        return stream << clap_trap.type() << " " << clap_trap.name();
}
