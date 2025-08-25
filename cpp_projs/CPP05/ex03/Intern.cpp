#include "Intern.hpp"

Intern::Intern()
{
    // std::cout << "Intern Constructor Called" << std::endl;
}

Intern::~Intern()
{
    // std::cout << "Intern Destructor Called" << std::endl;
}

Intern::Intern(Intern const &src) :Intern(src)
{
    // std::cout << "Intern Copy Constructor Called" << std::endl;
}

Intern &Intern::operator=(Intern const &src){
    if(this != &src)
        *this = src;
    return(*this);
}

AForm Intern::*makeForm(std::string name, std::string target){
    std::string name[3] = {"robotomy request","shrubbery request","president request"}
}