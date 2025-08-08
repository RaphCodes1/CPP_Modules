#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(0){
    std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name){
    if(grade < 1)
        throw GradeTooLowException();
    else if(grade > 150)
        throw GradeTooHighException();
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat Deconstructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name){
    std::cout << "Bureacrat Copy Constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy){
    std::cout << "Bureaucrat Assignment Operator called" << std::endl;
    if(this != &copy){
        _name = copy._name;
    }
    return *this;
}

std::string Bureaucrat::getName() const{
    return _name;
}

int Bureaucrat::getGrade() const{
    return _grade;
}

void Bureaucrat::increaseGrade(unsigned int num){
    int newAmount = _grade + num;
    if(newAmount < 1)
        throw GradeTooLowException();
    else if(newAmount > 150)
        throw GradeTooHighException();
    this->_grade = newAmount;
}

void Bureaucrat::reduceGrade(unsigned int num){
    int newAmount = _grade - num;
    if(newAmount < 1)
        throw GradeTooLowException();
    else if(newAmount > 150)
        throw GradeTooHighException();
    this->_grade = newAmount;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grades too low!";
}


 
