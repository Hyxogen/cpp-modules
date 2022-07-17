#include "Zombie.hpp"

int main() {
        Zombie("Carl").announce();

        Zombie *dynamic_zombie = newZombie("dynamic");
        dynamic_zombie->announce();
        randomChump("chump");

        delete dynamic_zombie;
        return (0);
}
