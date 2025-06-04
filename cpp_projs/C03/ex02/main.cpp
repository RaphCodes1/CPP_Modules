#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{   
    ScavTrap a;
    ScavTrap b("Slevana");
    // a = b;
    a.printInfo();
    a.attack("Dummy1");
    a.guardGate();
    
    ClapTrap z("Mike");
    z.printInfo();
    z.attack("Dummy2");

    FragTrap c("hello");
    c.printInfo();
    c.attack("Dummy");
    c.takeDamage(99);
    c.printInfo();
    c.beRepaired(1000);
    c.printInfo();
    c.highFivesGuys();


}