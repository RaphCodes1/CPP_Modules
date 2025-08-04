#include "Bureaucrat.hpp"

int main()
{
    try{
        throw std::exception();
    } catch (const std::exception &e) {
        std::cerr << "caught an exception: " << e.what() << std::endl;
    }

}