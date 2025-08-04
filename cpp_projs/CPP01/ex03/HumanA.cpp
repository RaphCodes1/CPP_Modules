#include "HumanA.hpp"
#include "Weapon.hpp"

/*member initializer list _weapon(weapon) is initialized 
this way because it is a reference from the weapon class*/

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon)
{   
    std::cout << "Human A created" << std::endl;
    _name = name;
}

HumanA::~HumanA()
{
    std::cout << "Human A destroyed" << std::endl;
}

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}