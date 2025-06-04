#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Mike");
    ClapTrap b(a);
    ClapTrap c;
    c = a;
    c.attack("Dummy1");
    std::cout << "C Energy Points: " << c.getEnergyPoints() << std::endl;
    std::cout << "C Hit Points: " << c.getHitPoints() << std::endl;
    c.takeDamage(1000000);
    c.beRepaired(7);
    std::cout << "C Energy Points: " << c.getEnergyPoints() << std::endl;
    std::cout << "C Hit Points: " << c.getHitPoints() << std::endl;
}