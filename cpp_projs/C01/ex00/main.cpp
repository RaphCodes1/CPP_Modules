#include "Zombie.hpp"
#include "randomChump.hpp"
#include "newZombie.hpp"

int main()
{
    Zombie zombie1("CHARGER");
    zombie1.announce();

    zombie1.randomChump("WITCH");
    
    Zombie* zombiePtr = newZombie("HUNTER");
    zombiePtr->announce();
    delete zombiePtr;

    return (0);
}