#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
    std::string _type;

public:
    explicit Weapon(const std::string &type);
    Weapon(const Weapon &other);

    ~Weapon();

    const std::string &getType() const;
    void               setType(const std::string &_type);

    Weapon &operator=(const Weapon &other);
};

#endif
