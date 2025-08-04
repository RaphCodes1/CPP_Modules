#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    protected:
        std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &src); //copy constructor
        Bureaucrat &operator=(const Bureaucrat &copy); //copy assignment operator
        ~Bureaucrat();
        string::getName();
        int::getGrade();
};

#endif
