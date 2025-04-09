#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Mike");
    a.attack("Dummy");
    a.takeDamage(1);
    a.printInfo();
    a.beRepaired(7);
    a.beRepaired(7);
    a.beRepaired(7);
    a.beRepaired(7);
    a.beRepaired(7);
    a.beRepaired(7);
    a.attack("bruh");
    a.takeDamage(10000000);
    a.beRepaired(7);
    a.printInfo();
}