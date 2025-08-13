#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat a("Mike",0);
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "caught an exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "caught an exception: " << e.what() << std::endl;
    }

    Bureaucrat b("Kyle",10);

    try{
        b.increaseGrade(-11);
    } catch(const Bureaucrat::GradeTooHighException& e){
        std::cerr << "caught exception: " << e.what() << std::endl;
    } catch(const Bureaucrat::GradeTooLowException& e){
        std::cerr << "caught exception: " << e.what() << std::endl;
    }
    std::cout << b; 
    
    Form c("bruh",30,30);
    b.signForm(c);
    std::cout << c.getGradeSigned() << std::endl;
}