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
    (void)level;
    debugPtr ptrDebug = &Harl::debug;
    infoPtr ptrInfo = &Harl::info;
    warningPtr ptrWarning = &Harl::warning;
    errorPtr ptrError = &Harl::error;
    (this->*ptrDebug)();
    (this->*ptrInfo)();
    (this->*ptrError)();
    (this->*ptrWarning)();

}

Harl::Harl()
{
    std::cout << "Created Harl" << std::endl;
}

Harl::~Harl()
{
    std::cout << "Destroyed Harl" << std::endl;
}
