#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{   
    ScavTrap a;
    ScavTrap b("Slevana");
    a.printInfo();
    a.attack("Dummy1");
    a.guardGate();
    
    ClapTrap z("Mike");
    z.printInfo();
    z.attack("Dummy2");

    FragTrap c("hello");
    FragTrap d;
    d.printInfo();
    d.attack("Dummy");
    d.takeDamage(99);
    d.printInfo();
    d.beRepaired(1000);
    d.printInfo();
    d.highFivesGuys();


}