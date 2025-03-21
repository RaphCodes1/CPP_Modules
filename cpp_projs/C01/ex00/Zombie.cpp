#include "Zombie.hpp"
#include "randomChump.hpp"
#include "newZombie.hpp"

void Zombie::announce()
{   
    std::cout << "Zombie created!" << std::endl;
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name){
    _name = name;
}

Zombie::~Zombie(){
    std::cout << "zombie destroyed!" << std::endl;
}

void Zombie::randomChump(std::string name)
{   
    ::randomChump(name);
}

::Zombie* newZombie(std::string name);