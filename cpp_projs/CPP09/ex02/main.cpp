#include "PmergeMe.hpp"

int main(int ac, char **av)
{   
    PmergeMe obj;
    if(ac > 1)
    {   
        std::string temp;
        for(int i = 1; i < ac; i++)
        {   
            temp = av[i];
            if(!obj.inputCheck(temp))
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            
        }
        //do the algorithm
        obj.doAlgorithm();
    }
    else
    {
        std::cerr << "Error" << std::endl;
    }
    return 0;
}