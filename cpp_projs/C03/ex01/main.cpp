#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
    ScavTrap a;
    ScavTrap b("Slevana");
    ScavTrap c(b);
    a.printInfo();
    a.attack("Dummy");
    a.takeDamage(99);
    a.printInfo();
    a.beRepaired(1000);
    a.printInfo();
    a.guardGate();


    ClapTrap z("Mike");
    z.printInfo();
    z.attack("Dummy2");

}