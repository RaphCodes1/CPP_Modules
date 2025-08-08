#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form{
    private:
        std::string _name;
        bool checkSigned;
        const int _gradeToSign;
        const int _gradeToExcecute;
    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &src);
        Form &operator=(const Form &src);
        ~Form();
        void beSigned(Bureaucrat &src);

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
