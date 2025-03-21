#include "Zombie.hpp"

void Zombie::announce()
{   
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
    std::cout << "Created Zombie" << std::endl;
}

void Zombie::setName(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << "Destroyed Zombie" << std::endl;
}