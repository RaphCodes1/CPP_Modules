#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        std::string defaultType;
    public:
        HumanB(std::string name);
        ~HumanB();
        void setDefault();
        void attack(); 
        void setType(Weapon& weapon);
};