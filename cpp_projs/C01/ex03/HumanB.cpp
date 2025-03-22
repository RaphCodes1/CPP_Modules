#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{   
    std::cout << "Human B created" << std::endl;
    this->setDefault();
    _name = name;
}

HumanB::~HumanB()
{
    std::cout << "Human B destroyed" << std::endl;
}

void HumanB::setDefault()
{
    Weapon defaultWeapon("Bare Hands");
    defaultType = defaultWeapon.getType();
}
void HumanB::attack()
{
    std::cout << _name << " attacks with their " << defaultType << std::endl;
}

void HumanB::setType(Weapon& weapon) 
{
    defaultType = weapon.getType();
}