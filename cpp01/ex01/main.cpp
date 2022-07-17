#include "Zombie.hpp"

#define HORDE_SIZE 10

int main() {
    Zombie("Carl").announce();

    Zombie *dynamic_zombie = Zombie::newZombie("dynamic");
    dynamic_zombie->announce();
    Zombie::randomChump("chump");

    Zombie *zombies = zombieHorde(HORDE_SIZE, "horde");
    for (int index = 0; index < HORDE_SIZE; ++index) {
        zombies[index].announce();
    }

    delete[] zombies;
    delete dynamic_zombie;
    return (0);
}
