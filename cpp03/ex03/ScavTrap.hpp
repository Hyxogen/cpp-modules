#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#ifndef SCAVTRAP_DEFAULT_HIT_POINTS
# define SCAVTRAP_DEFAULT_HIT_POINTS 100
#elif SCAVTRAP_DEFAULT_HIT_POINTS < 0
# error "SCAVTRAP_DEFAULT_HIT_POINTS may not be negative"
#endif

#ifndef SCAVTRAP_DEFAULT_ENERGY_POINTS
# define SCAVTRAP_DEFAULT_ENERGY_POINTS 50
#elif SCAVTRAP_DEFAULT_ENERGY_POINTS < 0
# error "SCAVTRAP_DEFAULT_ENERGY_POINTS may not be negative"
#endif

#ifndef SCAVTRAP_DEFAULT_ATTACK_DMG
# define SCAVTRAP_DEFAULT_ATTACK_DMG 20
#elif SCAVTRAP_DEFAULT_ATTACK_DMG < 0
# error "SCAVTRAP_DEFAULT_ATTACK_DMG may not be negative"
#endif

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    protected:
        ScavTrap();

    public:
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &other);

        ~ScavTrap();

        void        guardGate();
        std::string type() const;
};
#endif /* SCAVTRAP_HPP */
