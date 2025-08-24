#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
int main()
{  
    try{
        ShrubberyCreationForm bruh("target banana");
        Bureaucrat a("Kyle",144);
        a.signForm(bruh);
        a.executeForm(bruh);
    } catch(std::exception& e){
        std::cerr << "caught an exception: " << e.what() << std::endl;
    }

    try{
        PresidentialPardonForm obama("target orange");
        Bureaucrat b("David",23);
        b.signForm(obama);
        b.executeForm(obama);
    } catch(std::exception& e){
        std::cerr << "caught an exception: " << e.what() << std::endl;
    }

    try{
        RobotomyRequestForm cheese("target apple");
        Bureaucrat c("David",69);
        c.signForm(cheese);
        c.executeForm(cheese);
    } catch(std::exception& e){
        std::cerr << "caught an exception: " << e.what() << std::endl;
    }
    
}