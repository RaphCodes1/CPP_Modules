#include "randomChump.hpp"

void randomChump(std::string name)
{
    Zombie randomZombie(name);
    randomZombie.announce();
}