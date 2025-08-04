#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap{
    protected:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public:
        ClapTrap();
        ClapTrap(const std::string &nameGiven);
        ~ClapTrap();
        ClapTrap(const ClapTrap &copy);
        ClapTrap&operator=(const ClapTrap &copy);
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        int  getEnergyPoints() const;
        int  getHitPoints() const;
        void printInfo() const;
};

#endif