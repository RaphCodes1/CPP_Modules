#include "FragTrap.hpp"

FragTrap::FragTrap(std::string nameGiven) : ClapTrap(nameGiven)
{
    std::cout << "FragTrap Constructor Called" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Deconstructor Called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << name << ": positive high-fives request" << std::endl;
}