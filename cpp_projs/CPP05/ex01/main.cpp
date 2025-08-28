#include "Bureaucrat.hpp"

int main()
{
    
    Bureaucrat b("Kyle",10);
    try{
        b.increaseGrade();
        b.reduceGrade();
        b.reduceGrade();
    } catch(const Bureaucrat::GradeTooHighException& e){
        std::cerr << "caught exception: " << e.what() << std::endl;
    } catch(const Bureaucrat::GradeTooLowException& e){
        std::cerr << "caught exception: " << e.what() << std::endl;
    }
    std::cout << b; 
    
    Form form1("Jack",30,30);
    b.signForm(form1);
    Form copyForm1 = form1;
    std::cout << form1.getGradeSigned() << std::endl;
    std::cout << copyForm1 << std::endl;
}