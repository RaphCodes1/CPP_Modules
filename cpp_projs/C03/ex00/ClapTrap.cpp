#include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{
    std::cout << "Deconstructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string nameGiven)
{   
    std::cout << "Constructor called" << std::endl;
    this->name = nameGiven;
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
}

