#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"){
    std::cout << "Bureaucrat Default Constructor called" << std::endl;
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
 
