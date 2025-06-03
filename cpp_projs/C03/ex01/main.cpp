#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
    // ClapTrap a("Mike");
    // a.attack("Dummy");
    // a.takeDamage(1);
    // a.printInfo();
    // a.attack("bruh");
    // a.takeDamage(10000000);
    // a.beRepaired(7);
    // a.printInfo();
    // ScavTrap a;
    // ScavTrap b("Slevana");
    // b.printInfo();
    // b.attack("Dummy");
    // b.takeDamage(99);
    // b.printInfo();
    // b.beRepaired(1000);
    // b.printInfo();

    ScavTrap a;
    ScavTrap b("Slevana");
    ScavTrap c(b);
    // a = b;
    a.printInfo();
    a.attack("Dummy2");
    c.attack("Dummy1");


}