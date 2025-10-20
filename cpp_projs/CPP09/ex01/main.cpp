#include "RPN.hpp"

int main(int ac, char **av)
{   
    RPN rpnObj;
    if(ac == 2)
    {
        rpnObj.RPNprocess(av[1]);
    }
    else
        std::cerr << "Error" << std::endl;
} 