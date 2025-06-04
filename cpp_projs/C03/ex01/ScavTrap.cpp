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

ScavTrap::ScavTrap(const std::string nameGiven) 
    :ClapTrap(nameGiven)
{
    std::cout << "ScavTrap Contructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
    :ClapTrap(copy)
{   
    if(this != &copy)
    {
        this->name = copy.name;
        this->hitPoints = copy.hitPoints;
        this->energyPoints = copy.energyPoints;
        this->attackDamage = copy.attackDamage;
    }
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    if(this != &copy)
    {
        this->name = copy.name;
        this->hitPoints = copy.hitPoints;
        this->energyPoints = copy.energyPoints;
        this->attackDamage = copy.attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Deconstructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}

