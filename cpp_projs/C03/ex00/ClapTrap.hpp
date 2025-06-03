#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap{
    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string nameGiven);
        ~ClapTrap();
        ClapTrap(ClapTrap &copy);
        ClapTrap&operator=(ClapTrap &copy);
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        int  getEnergyPoints();
        int  getHitPoints();
        void printInfo();

};

#endif