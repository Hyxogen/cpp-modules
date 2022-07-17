#include <limits>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
        ClapTrap cp("CL4P-TP");
        ClapTrap cp_copy(cp);
        ClapTrap other("Better CL4P-TP");
        ScavTrap cv("SC4V-TP");
        ScavTrap better_cv("Better SC4V-TP");

        cp.attack("Handsome Jack");
        cp.attack("Flynn");
        cp.takeDamage(5);
        cp.beRepaired(10);
        cp.takeDamage(std::numeric_limits<unsigned int>::max());
        cp.beRepaired(1);
        cp.beRepaired(std::numeric_limits<unsigned int>::max());
        cp.beRepaired(1);

        cp_copy.attack("itself in confusion");
        other.attack("CL4P-TP");
        other.beRepaired(500);

        cp = other;
        cp.attack("door");
        cp.attack("door");
        cp.attack("door");
        cp.attack("door");
        cp.attack("door");
        cp.attack("door");
        cp.attack("door");
        cp.attack("door");
        cp.attack("door");
        cp.attack("door");
        cp.attack("door");
        cp.attack("door");
        cp.attack("door");
        cp.attack("door");

        cv.attack("Better CL4P-TP");
        better_cv.attack("Better CL4P-TP");
        cv.guardGate();

        for (int i = 0; i < 50; ++i) {
                cv.attack("Better CL4P-TP");
        }

        cv = better_cv;
        cv.guardGate();
        cv.attack("Better CL4P-TP");
}
