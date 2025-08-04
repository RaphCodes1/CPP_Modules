#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
    std::cout << "Weapon Created\n";
    type = str;
}

Weapon::~Weapon()
{
    std::cout << "Weapon Destroyed\n";
}
const std::string& Weapon::getType()
{
    return type;
}

void Weapon::setType(std::string newType)
{
    type = newType;
}