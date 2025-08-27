#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string _name;
        bool checkSigned;
        const int _gradeToSign;
        const int _gradeToExcecute;
    public:
        Form();
        Form(const std::string name, const int gradeToSign, const int gradeToExecute);
        ~Form();
        Form(const Form &src);
        Form &operator=(const Form &src);
        void beSigned(const Bureaucrat &src);
        std::string getName() const;
        bool getSigned() const;
        int getGradeSigned() const;
        int getGradeExecute() const;

    //exceptions
    class GradeTooHighException : public std::exception{
        public:
            const char* what() const throw();
    };

    class GradeTooLowException: public std::exception{
        public:
            const char* what() const throw();
    };
};
std::ostream &operator<<(std::ostream &out, Form const &other);

#endif
