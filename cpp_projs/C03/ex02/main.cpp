#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    // ScavTrap b("Slevana");
    // b.printInfo();
    // b.attack("Dummy");
    // b.takeDamage(99);
    // b.printInfo();
    // b.beRepaired(1000);
    // b.printInfo();
    // b.guardGate();

    FragTrap c("hello");
    c.printInfo();
    c.attack("Dummy");
    c.takeDamage(99);
    c.printInfo();
    c.beRepaired(1000);
    c.printInfo();
    c.highFivesGuys();


}