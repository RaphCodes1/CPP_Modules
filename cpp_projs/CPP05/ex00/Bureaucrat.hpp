#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
        std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &src); //copy constructor
        Bureaucrat &operator=(const Bureaucrat &copy); //copy assignment operator
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;

        //exception
        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "Grade too high!";
                }
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "Grade too low!";
                }
        };
};

#endif
