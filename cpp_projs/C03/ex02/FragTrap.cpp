#include "FragTrap.hpp"

FragTrap::FragTrap()
    :ClapTrap("Default")
{
    std::cout << "FragTrap Default Contructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

FragTrap::FragTrap(const std::string &nameGiven) 
    :ClapTrap(nameGiven)
{
    std::cout << "FragTrap Contructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Deconstructor Called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
    :ClapTrap(copy)
{   
    std::cout << "FragTrap Copy Constructor Called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{   
    std::cout << "FragTrap Copy Assignment Operator Called" << std::endl;
    if(this != &copy)
    {
        ClapTrap::operator=(copy);
    }
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << name << ": positive high-fives request" << std::endl;
}