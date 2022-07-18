#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#ifndef DIATRAP_DEFAULT_HIT_POINTS
# define DIATRAP_DEFAULT_HIT_POINTS FRAGTRAP_DEFAULT_HIT_POINTS
#elif DIATRAP_DEFAULT_HIT_POINTS < 0
# error "DIATRAP_DEFAULT_HIT_POINTS may not be negative"
#endif

#ifndef DIATRAP_DEFAULT_ENERGY_POINTS
# define DIATRAP_DEFAULT_ENERGY_POINTS SCAVTRAP_DEFAULT_HIT_POINTS
#elif DIATRAP_DEFAULT_ENERGY_POINTS < 0
# error "DIATRAP_DEFAULT_ENERGY_POINTS may not be negative"
#endif

#ifndef DIATRAP_DEFAULT_ATTACK_DMG
# define DIATRAP_DEFAULT_ATTACK_DMG FRAGTRAP_DEFAULT_ATTACK_DMG
#elif DIATRAP_DEFAULT_ATTACK_DMG < 0
# error "DIATRAP_DEFAULT_ATTACK_DMG may not be negative"
#endif

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
