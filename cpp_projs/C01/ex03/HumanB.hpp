#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon* _weapon;
    public:
        HumanB(std::string name);
        ~HumanB();
        void attack(); 
        void setType(std::string newType);
        void setWeapon(Weapon& weapon);
};