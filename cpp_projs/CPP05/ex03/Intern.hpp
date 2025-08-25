#ifndef INTERN_HPP
# define INTERN_HPP
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class Intern:public AForm{
    public:
        Intern();
        ~Intern();
        Intern(Intern const &src);
        Intern&operator=(Intern const &src);
        AForm *makeForm(std::string name, std::string target);
};



#endif