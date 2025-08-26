#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &src);

        virtual void execute(Bureaucrat const & executor) const;

        class RobotomyFailureException: public std::exception{
            public:
                const char* what() const throw();
        };

        class RobotomyFiftyFifty: public std::exception{
            public:
                const char* what() const throw();
        };
};

#endif