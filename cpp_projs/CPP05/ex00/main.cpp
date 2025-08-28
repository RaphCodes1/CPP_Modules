#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat a("Mike",0);
    } catch (const std::exception& e) {
        std::cerr << "caught an exception: " << e.what() << std::endl;
    }

    Bureaucrat b("Kyle",10);

    Bureaucrat c(b);
    try{
        b.increaseGrade();
        c.reduceGrade();
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    } catch(const std::exception& e){
        std::cerr << "caught exception: " << e.what() << std::endl;
    }
}