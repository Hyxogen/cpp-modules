#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>

#include "Weapon.hpp"

class HumanA {
        const std::string _name;
        Weapon           &_weapon;

    public:
        HumanA(const std::string &name, Weapon &weapon);

        void attack() const;
};

#endif
