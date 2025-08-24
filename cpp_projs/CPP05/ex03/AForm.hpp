#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        std::string _name;
        bool checkSigned;
        const int _gradeToSign;
        const int _gradeToExcecute;
    public:
        AForm();
        AForm(std::string name, const int gradeToSign, const int gradeToExecute);
        virtual ~AForm();
        AForm(const AForm &src);
        AForm &operator=(const AForm &src);
        void beSigned(const Bureaucrat &src);
        std::string getName() const;
        bool getSigned() const;
        int getGradeSigned() const;
        int getGradeExecute() const;
        virtual void execute(Bureaucrat const &executor) const = 0;


    //exceptions
    class GradeTooHighException : public std::exception{
        public:
            const char* what() const throw();
    };

    class GradeTooLowException: public std::exception{
        public:
            const char* what() const throw();
    };

    class NotSignedException: public std::exception{
        public:
            const char* what() const throw();
    };
};
std::ostream &operator<<(std::ostream &out, AForm const &other);

#endif
