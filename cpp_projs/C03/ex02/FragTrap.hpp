#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
    public:
        FragTrap();
        FragTrap(const std::string &nameGiven);
        ~FragTrap();
        FragTrap(const FragTrap &copy);
        FragTrap&operator=(const FragTrap &copy);
        void highFivesGuys();
};


#endif