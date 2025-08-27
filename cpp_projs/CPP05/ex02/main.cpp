#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <ctime>

int main()
{   
    srand(time(0)); 
    
    std::cout << "TIMEEEEEEEEE: " << time(0) << std::endl;
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
        Bureaucrat c("David",21);
        c.signForm(cheese);
        c.executeForm(cheese);
    } catch(std::exception& e){
        std::cerr << "caught an exception: " << e.what() << std::endl;
    }

    try{
        RobotomyRequestForm cheese("target jackfruit");
        Bureaucrat c("William",150);
        c.signForm(cheese);
        c.executeForm(cheese);
    } catch(std::exception& e){
        std::cerr << "caught an exception: " << e.what() << std::endl;
    }
}