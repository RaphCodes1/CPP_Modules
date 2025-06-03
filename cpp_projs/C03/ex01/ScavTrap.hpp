#ifndef  SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    public:
        ScavTrap();
        ScavTrap(std::string nameGiven);
        ~ScavTrap();
        ScavTrap(ScavTrap &copy);
        ScavTrap&operator=(ScavTrap &copy);
        void guardGate();
};

#endif