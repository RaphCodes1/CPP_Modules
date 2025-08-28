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
        Bureaucrat(const std::string name, const int grade);
        Bureaucrat(const Bureaucrat &src); //copy constructor
        Bureaucrat &operator=(const Bureaucrat &copy); //copy assignment operator
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void reduceGrade();
        void increaseGrade();

        //exception
        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };
};
std::ostream &operator<<(std::ostream& out,Bureaucrat const &other);

#endif
