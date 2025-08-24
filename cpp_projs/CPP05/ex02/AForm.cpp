#include "AForm.hpp"

AForm::AForm():_name("Default"),checkSigned(false),_gradeToSign(150),_gradeToExcecute(150){
    std::cout << "Default AForm Constructor called" << std::endl;
}

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute) 
: _name(name),checkSigned(false),_gradeToSign(gradeToSign),_gradeToExcecute(gradeToExecute)
{   
    std::cout << "AForm Constructor called" << std::endl;
    if(_gradeToSign < 1 || _gradeToExcecute < 1)
        throw GradeTooHighException();
    else if(_gradeToExcecute > 150 || _gradeToExcecute > 150)
        throw GradeTooLowException();
}

AForm::~AForm(){
    std::cout << "AForm Destructor called" << std::endl;
}

AForm::AForm(const AForm& src)
: _name(src._name), checkSigned(src.checkSigned), _gradeToSign(src._gradeToSign), _gradeToExcecute(src._gradeToExcecute){
    
    std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm& src)
{
    if(this != &src)
    {
        this->_name = src._name;
        this->checkSigned = src.checkSigned;
    }

    return(*this);
}

std::string AForm::getName() const
{
    return(_name);
}

bool AForm::getSigned() const
{
    return(checkSigned);
}

int AForm::getGradeExecute() const
{
    return (_gradeToExcecute);
}

int AForm::getGradeSigned() const
{
    return (_gradeToSign);
}


std::ostream &operator<<(std::ostream &out, AForm const &other)
{
    out << "Name: " << other.getName() << "\nIsSigned: " << other.getSigned() << "\nGrade to execute: "
    << other.getGradeExecute() << "\nGrade to get signed: " << other.getGradeSigned() << std::endl;

    return out;
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "Grade too low";
}

const char* AForm::NotSignedException::what() const throw(){
    return "Not signed!";
}

void AForm::beSigned(const Bureaucrat &src)
{
    if(src.getGrade() >= this->getGradeSigned())
        throw GradeTooLowException();
    checkSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const{
    if(!this->getSigned())
        throw NotSignedException();
    else if(executor.getGrade() >= this->getGradeExecute())
        throw GradeTooLowException();
}