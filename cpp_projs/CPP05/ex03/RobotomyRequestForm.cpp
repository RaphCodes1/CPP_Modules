#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm",72,25), _target("Default"){
    // std::cout << "Default RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("RobotomyRequestForm",72,25), _target(target)
{   
    // std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    // std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
:AForm(src), _target(src._target) 
{
    // std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
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

const char *RobotomyRequestForm::RobotomyFailureException::what() const throw(){
    return "Robotomy Failed.";
}

const char *RobotomyRequestForm::RobotomyFiftyFifty::what() const throw(){
    return "Robotomy did not win 50/50";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{   
    int randomNum = rand() % 2;
    if(randomNum == 1)
    {
        try{
            AForm::execute(executor);
            std::cout << "Drilling Noises brrrrrr " << _target << " has been robotomized successfully" << std::endl;
        } catch(std::exception& e)
        {
            throw RobotomyFailureException();
        }
    } else {
        throw RobotomyFiftyFifty();
    }
}