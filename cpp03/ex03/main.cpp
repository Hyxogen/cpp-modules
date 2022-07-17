#include <limits>

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
        ClapTrap cp("CL4P-TP");
        ClapTrap cp_copy(cp);
        ClapTrap other("Better CL4P-TP");
        ScavTrap cv("SC4V-TP");
        ScavTrap cv_copy(cv);
        ScavTrap better_cv("Better SC4V-TP");
        FragTrap fg("FR4G-TP");
        FragTrap fg_copy(fg);
        FragTrap better_fg("Better FR4G-TP");

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
        cv_copy.attack("itself in confusion");
        better_cv.attack("Better CL4P-TP");
        cv.guardGate();
        fg.highFivesGuys();
        fg_copy.highFivesGuys();
        fg_copy.attack("itself in confusion");
        better_fg.highFivesGuys();

        for (int i = 0; i < 50; ++i) {
                fg.highFivesGuys();
                cv.attack("Better CL4P-TP");
                fg.highFivesGuys();
        }
        fg.beRepaired(42);

        cv = better_cv;
        cv.guardGate();
        cv.attack("Better CL4P-TP");

        DiamondTrap dd("DI4MOND-TP");
        dd.attack("everyone else");
}
