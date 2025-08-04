#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{   
    int choice = -1;
    void (Harl::*functions[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    std::string keywords[4] = {"DEBUG","INFO","WARNING","ERROR"};
    for(size_t i = 0;i < 4;i++)
    {   
        if(level == keywords[i])
        {   
            choice = i;
            break ;
        }
    }

    switch(choice) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            (this->*functions[choice])();
            break ;
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            (this->*functions[choice])();
            break ;
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            (this->*functions[choice])();
            break ;
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            (this->*functions[choice])();
            break ;
        default:
            std::cout << "[ Proabably complaining about insignificant problems ]" << std::endl;
    }
}

Harl::Harl()
{
    std::cout << "Created Harl" << std::endl;
}

Harl::~Harl()
{
    std::cout << "Destroyed Harl" << std::endl;
}
