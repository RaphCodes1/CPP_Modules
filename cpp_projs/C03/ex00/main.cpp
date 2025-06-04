#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Mike");
    ClapTrap b(a);
    ClapTrap c;
    c = a;
    c.attack("Dummy1");
    c.printInfo();
    c.takeDamage(1000000);
    c.beRepaired(7);
    c.printInfo();
}