#include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Deconstructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string nameGiven)
    :name(nameGiven), hitPoints(10), energyPoints(10), attackDamage(0) 
{   
    std::cout << "ClapTrap Constructor called" << std::endl;
}

void ClapTrap::printInfo()
{
    std::cout << "Hit Point: " << this->hitPoints << std::endl;
    std::cout << "Energy Points: " << this->energyPoints << std::endl;
}

void ClapTrap::attack(const std::string &target)
{   
    if(energyPoints > 0 && hitPoints > 0)
    {
        this->energyPoints -= 1; 
        std::cout << this->name << " attacks " << target << ", causing " 
            << this->attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " Has no more energy points " <<
        "or has been destroyed!" << std::endl; 
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->hitPoints > 0)
    {
        this->hitPoints -= amount;
        std::cout << "ClapTrap " <<  name <<" takes " << amount << " damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << name << " has " << this->hitPoints << " hitpoints" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{   
    if(this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints -= 1;
        this->hitPoints += amount;
        std::cout << "ClapTrap " << name << " repaired itself with " << amount << " points" << std::endl;
    }
    else
        std::cout << "ClapTrap " << name << " has no more Energy points or has been destroyed!" << std::endl;
}

