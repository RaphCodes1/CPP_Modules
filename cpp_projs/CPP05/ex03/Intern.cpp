#include "Intern.hpp"
Intern::Intern()
{
    // std::cout << "Intern Constructor Called" << std::endl;
}

Intern::~Intern()
{
    // std::cout << "Intern Destructor Called" << std::endl;
}

Intern::Intern(Intern const &src)
{
    (void)src;
}

Intern &Intern::operator=(Intern const &src){
    (void)src;
    return(*this);
}

AForm *PresidentForm(std::string target){
    return new PresidentialPardonForm(target);
}

AForm *ShrubberyForm(std::string target){
    return new ShrubberyCreationForm(target);
}

AForm *RobotomyForm(std::string target){
    return new RobotomyRequestForm(target);
}

const char *Intern::FormError::what() const throw(){
    return "Form does not exist";
}

AForm *Intern::makeForm(std::string name, std::string target){
    std::string formNames[3] = {"robotomy request","shrubbery request","president request"};

    AForm* (*formCreate[3])(std::string) = {
        &RobotomyForm,
        &ShrubberyForm,
        &PresidentForm,
    }; 

    for(int i = 0; i < 3;i++)
    {
        if(formNames[i] == name)
        {
            std::cout << "Intern creates " << name << " form" << std::endl;
            return formCreate[i](target);
        }
    }
    // std::cerr << "Error: Form Type '" << name << "' does not exist" << std::endl;
    throw FormError();
    return NULL;
}