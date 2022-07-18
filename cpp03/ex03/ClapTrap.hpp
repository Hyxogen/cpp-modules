#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <ostream>
#include <string>

class ClapTrap {
    protected:
        std::string  _name;
        unsigned int _hit_points, _energy_points, _attack_dmg;

        ClapTrap();
        ClapTrap(
            const std::string &name, unsigned int hit_points,
            unsigned int energy_points, unsigned int attack_dmg);

    public:
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &other);

        ~ClapTrap();

        ClapTrap           &operator=(const ClapTrap &other);
        virtual void        attack(const std::string &target);
        void                takeDamage(unsigned int amount);
        void                beRepaired(unsigned int amount);
        const std::string  &name() const;

    protected:
	void attack_base(const std::string &target, cosnt std::string &type);
};

std::ostream &operator<<(std::ostream &stream, const ClapTrap &clap_trap);

#endif /* CLAPTRAP_HPP */
