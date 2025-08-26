#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat a("Mike",1);
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "caught an exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "caught an exception: " << e.what() << std::endl;
    }

    Bureaucrat b("Kyle",10);

    try{
        b.increaseGrade(9);
        std::cout << b << std::endl;
    } catch(const Bureaucrat::GradeTooHighException& e){
        std::cerr << "caught exception: " << e.what() << std::endl;
    } catch(const Bureaucrat::GradeTooLowException& e){
        std::cerr << "caught exception: " << e.what() << std::endl;
    }
}