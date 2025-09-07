#include "conversion.hpp"

int main(int ac, char **av)
{   
    if(ac == 2)
        ScalarConverter::convert(av[1]);
    else
        std::cout << "Enter Valid Input: (char,int,double,float)" << std::endl;
}