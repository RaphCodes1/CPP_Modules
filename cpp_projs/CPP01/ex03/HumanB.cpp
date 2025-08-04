#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{   
    std::cout << "Human B created" << std::endl;
    _name = name;
    _weapon = NULL;
}

HumanB::~HumanB()
{
    std::cout << "Human B destroyed" << std::endl;
}


void HumanB::attack()
{   
    if(_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " has no weapon to attack with" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}