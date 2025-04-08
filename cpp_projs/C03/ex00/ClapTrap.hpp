#include <iostream>
#include <string>

class ClapTrap{
    private:
        std::string name;
        int HitPoints;
        int EnergyPoints;
        int AttackDamage;
    public:
        ClapTrap(std::string nameGiven);
        ~ClapTrap();

};