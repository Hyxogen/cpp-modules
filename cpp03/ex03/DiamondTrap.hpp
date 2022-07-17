#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
        std::string _name;

        DiamondTrap();

    public:
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &other);

        ~DiamondTrap();

        void        whoAmI() const;
        std::string type() const;
        void        attack(const std::string &target);
};

#endif /* DIAMONDTRAP_HPP */
