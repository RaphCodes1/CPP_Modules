#ifndef  SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    public:
        ScavTrap();
        ScavTrap(const std::string &nameGiven);
        ~ScavTrap();
        ScavTrap(const ScavTrap &copy);
        ScavTrap&operator=(const ScavTrap &copy);
        void attack(const std::string &target);
        void guardGate();
};

#endif