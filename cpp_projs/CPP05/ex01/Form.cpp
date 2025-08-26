#include "Form.hpp"

Form::Form():_name("Default"),checkSigned(false),_gradeToSign(150),_gradeToExcecute(150){
    std::cout << "Default Form Constructor called" << std::endl;
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute) 
: _name(name), checkSigned(false),_gradeToSign(gradeToSign),_gradeToExcecute(gradeToExecute)
{   
    std::cout << "Form Constructor called" << std::endl;
    if(_gradeToSign < 1 || _gradeToExcecute < 1)
        throw GradeTooHighException();
    else if(_gradeToSign > 150 || _gradeToExcecute > 150)
        throw GradeTooLowException();
}

Form::~Form(){
    std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const Form& src)
: _name(src._name), checkSigned(src.checkSigned), _gradeToSign(src._gradeToSign), _gradeToExcecute(src._gradeToExcecute){
    
    std::cout << "Form Copy Constructor called" << std::endl;
}

Form &Form::operator=(const Form& src)
{
    if(this != &src)
    {
        this->_name = src._name;
        this->checkSigned = src.checkSigned;
    }

    return(*this);
}

std::string Form::getName() const
{
    return(_name);
}

bool Form::getSigned() const
{
    return(checkSigned);
}

int Form::getGradeExecute() const
{
    return (_gradeToExcecute);
}

int Form::getGradeSigned() const
{
    return (_gradeToSign);
}


std::ostream &operator<<(std::ostream &out, Form const &other)
{
    out << "Name: " << other.getName() << "\nIsSigned: " << other.getSigned() << "\nGrade to execute: "
    << other.getGradeExecute() << "\nGrade to get signed: " << other.getGradeSigned() << std::endl;

    return out;
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Grade too low";
}

void Form::beSigned(const Bureaucrat &src)
{
    if(src.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    checkSigned = true;
}