#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <ostream>
#include <string>

class ClapTrap {
        std::string  _name;
        unsigned int _hit_points, _energy_points, _attack_dmg;

        ClapTrap();

    public:
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &other);

        ~ClapTrap();

        ClapTrap          &operator=(const ClapTrap &other);
        void               attack(const std::string &target);
        void               takeDamage(unsigned int amount);
        void               beRepaired(unsigned int amount);
        const std::string &name() const;
};

std::ostream &operator<<(std::ostream &stream, const ClapTrap &clap_trap);

#endif
