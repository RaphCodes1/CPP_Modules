#include "Zombie.hpp"
#include <sstream>

Zombie *zombieHorde(int N, std::string name)
{
    if(N <= 0)
        return NULL;
        
    Zombie* horde = new Zombie[N];

    for(int i = 0;i < N; i++)
    {
        std::stringstream ss;
        ss << i + 1;
        std::string str = ss.str();
        horde[i].setName(name + "_" + str);
    }
    
    return (horde);
};