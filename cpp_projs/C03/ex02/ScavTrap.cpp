#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    :ClapTrap("Default")
{
    std::cout << "ScavTrap Default Contructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &nameGiven) 
    :ClapTrap(nameGiven)
{
    std::cout << "ScavTrap Constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
    :ClapTrap(copy)
{   
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{   
    std::cout << "ScavTrap Copy assignment Operator called" << std::endl;
    if(this != &copy)
    {
        ClapTrap::operator=(copy);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Deconstructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{   
    if(energyPoints > 0 && hitPoints > 0)
    {
        this->energyPoints -= 1; 
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " 
            << this->attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " Has no more energy points " <<
        "or has been destroyed!" << std::endl; 
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}

