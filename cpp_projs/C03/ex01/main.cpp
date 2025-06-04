#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
    ScavTrap a;
    ScavTrap b("Slevana");
    ScavTrap c(b);
    // a = b;
    a.printInfo();
    a.attack("Dummy2");
    c.attack("Dummy1");

}