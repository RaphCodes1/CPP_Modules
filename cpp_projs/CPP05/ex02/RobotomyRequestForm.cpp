#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm",145,137), _target("Default"){
    std::cout << "Default RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("RobotomyRequestForm",145,137), _target(target)
{   
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
:AForm(src), _target(src._target) 
{
    std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    if(this != &src)
    {
        AForm::operator=(src);
        this->_target=src._target;
    }
    return(*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{   
    std::cout << "Drilling Noises brrrrrr" << std::endl;
    try{
        AForm::execute(executor);
        std::cout << _target << " has been robotomized successfully 50" << "%" << " most of the time" << std::endl;
    } catch(std::exception& e)
    {
        std::cerr << "Robotomy Failed." << std::endl; 
    }
}