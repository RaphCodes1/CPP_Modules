#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
int main()
{
    // try{
    //     Bureaucrat a("Mike",0);
    // } catch (const Bureaucrat::GradeTooHighException& e) {
    //     std::cerr << "caught an exception: " << e.what() << std::endl;
    // } catch (const Bureaucrat::GradeTooLowException& e) {
    //     std::cerr << "caught an exception: " << e.what() << std::endl;
    // }
        
    try{
        ShrubberyCreationForm bruh("target banana");
        PresidentialPardonForm obama("target orange");
        RobotomyRequestForm cheese("target apple");
        Bureaucrat b("Kyle",10);
        bruh.beSigned(b);
        bruh.execute(b);
        obama.beSigned(b);
        obama.execute(b);
        cheese.beSigned(b);
        cheese.execute(b);
    } catch(std::exception& e){
        std::cerr << "caught an exception: " << e.what() << std::endl;
    }
    
}