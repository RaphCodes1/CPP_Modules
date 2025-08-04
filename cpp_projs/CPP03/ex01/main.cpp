#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
    ScavTrap a;
    ScavTrap b("Slevana");
    ScavTrap c(b);
    c.printInfo();
    c.attack("Dummy");
    c.takeDamage(99);
    c.printInfo();
    c.beRepaired(1000);
    c.printInfo();
    c.guardGate();


    ClapTrap z("Mike");
    z.printInfo();
    z.attack("Dummy2");

}