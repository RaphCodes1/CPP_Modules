#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <ctime>
int main()
{  
    srand(time(0));
    Intern formMaker;
    try{
        AForm *myForm = formMaker.makeForm("robotomy request","banana");
        std::cout << "Name of Form: " << myForm->getName() << std::endl;
        std::cout << *myForm << std::endl;
        Bureaucrat c("David",10);
        c.signForm(*myForm);
        c.executeForm(*myForm);
        delete myForm;
    } catch(std::exception &e){
        std::cerr << "Exception error: " << e.what() << std::endl;
    }

    try{
        AForm *myForm = formMaker.makeForm("robotomy request","cheese");
        std::cout << "Name of Form: " << myForm->getName() << std::endl;
        std::cout << *myForm << std::endl;
        Bureaucrat c("Francis",10);
        c.signForm(*myForm);
        c.executeForm(*myForm);
        delete myForm;
    } catch(std::exception &e){
        std::cerr << "Exception error: " << e.what() << std::endl;
    }
}