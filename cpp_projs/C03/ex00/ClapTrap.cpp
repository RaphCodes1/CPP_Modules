#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    :name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string nameGiven)
    :name(nameGiven), hitPoints(10), energyPoints(10), attackDamage(0) 
{;}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Deconstructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{   
    std::cout << "ClapTrap Copy Constructor Called" << std::endl;
    if(this != &copy)
    {
        this->name = copy.name;
        this->hitPoints = copy.hitPoints;
        this->energyPoints = copy.energyPoints;
        this->attackDamage = copy.attackDamage;
    }
    
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{   
    std::cout << "ClapTrap Copy Assignment Operator Called" << std::endl;
    if(this != &copy)
    {
        this->name = copy.name;
        this->hitPoints = copy.hitPoints;
        this->energyPoints = copy.energyPoints;
        this->attackDamage = copy.attackDamage;
    }
    return *this;
}

void ClapTrap::printInfo()
{
    std::cout << "Hit Point: " << this->hitPoints << std::endl;
    std::cout << "Energy Points: " << this->energyPoints << std::endl;
}

int ClapTrap::getEnergyPoints()
{
    return (this->energyPoints);
}

int ClapTrap::getHitPoints()
{
    return (this->hitPoints);
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
        std::cout << "ClapTrap " <<  name <<" takes " << amount << " damage!" << std::endl;

    if (amount >= static_cast<unsigned int>(hitPoints))
        hitPoints = 0;
    else
        hitPoints -= amount;
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

