#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() : _name("unnamed") { }

Zombie::Zombie(const Zombie &other) : _name(other._name) { }

Zombie::Zombie(const std::string &name) : _name(name) { }

Zombie::~Zombie() {
    std::cout << _name << " destroyed" << std::endl;
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie &Zombie::operator=(const Zombie &other) {
    if (this == &other) {
        return *this;
    }
    _name = other._name;
    return *this;
}

Zombie *Zombie::newZombie(const std::string &name) {
    return new Zombie(name);
}

void Zombie::randomChump(const std::string &name) {
    Zombie(name).announce();
}
