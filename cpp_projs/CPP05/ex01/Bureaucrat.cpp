#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150){
    std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name){
    std::cout << "Bureaucrat Constructor called" << std::endl;
    if(grade < 1)
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat Deconstructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name), _grade(src._grade){
    std::cout << "Bureacrat Copy Constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy){
    std::cout << "Bureaucrat Assignment Operator called" << std::endl;
    if(this != &copy){
        _name = copy._name;
        _grade = copy._grade;
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
    int newAmount = _grade - num;
    if(newAmount < 1)
        throw GradeTooHighException();
    else if(newAmount > 150)
        throw GradeTooLowException();
    this->_grade = newAmount;
}

void Bureaucrat::reduceGrade(unsigned int num){
    int newAmount = _grade + num;
    if(newAmount < 1)
        throw GradeTooHighException();
    else if(newAmount > 150)
        throw GradeTooLowException();
    this->_grade = newAmount;
}

void Bureaucrat::signForm(Form &src){
    try{
        src.beSigned(*this);
        std::cout << getName() << " signed " << src.getName() <<std::endl;
    }catch(const std::exception& e){
        std::cerr << "Couldnt sign form because: " << e.what() << std::endl; 
    }

}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grades too low!";
}

std::ostream &operator<<(std::ostream& out,Bureaucrat const &other){
    out << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return out; 
}


 
