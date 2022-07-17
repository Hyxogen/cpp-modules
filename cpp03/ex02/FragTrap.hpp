#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#ifndef FRAGTRAP_DEFAULT_HIT_POINTS
# define FRAGTRAP_DEFAULT_HIT_POINTS 100
#elif FRAGTRAP_DEFAULT_HIT_POINTS < 0
# error "FRAGTRAP_DEFAULT_HIT_POINTS may not be negative"
#endif

#ifndef FRAGTRAP_DEFAULT_ENERGY_POINTS
# define FRAGTRAP_DEFAULT_ENERGY_POINTS 100
#elif FRAGTRAP_DEFAULT_ENERGY_POINTS < 0
# error "FRAGTRAP_DEFAULT_ENERGY_POINTS may not be negative"
#endif

#ifndef FRAGTRAP_DEFAULT_ATTACK_DMG
# define FRAGTRAP_DEFAULT_ATTACK_DMG 30
#elif FRAGTRAP_DEFAULT_ATTACK_DMG < 0
# error "FRAGTRAP_DEFAULT_ATTACK_DMG may not be negative"
#endif

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
        FragTrap();

    public:
        FragTrap(const std::string &name);
        FragTrap(const FragTrap &other);

        ~FragTrap();

        void        highFivesGuys();
        std::string type() const;
};

std::ostream &operator<<(std::ostream &stream, const FragTrap &frag_trap);

#endif /* FRAGTRAP_HPP */
