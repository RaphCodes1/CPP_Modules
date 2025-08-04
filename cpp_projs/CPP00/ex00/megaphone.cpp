#include <iostream>
#include <string>

int main(int ac, char **av)
{   
    if(ac == 1)
        std::cout << "* LOUD AND UNBREARABLE FEEDBACK NOISE *\n";
    else
    {   
        for(int i = 1; i < ac; i++)
        {   
            for(int f = 0;av[i][f] != '\0'; f++)
                std::cout << char(toupper(av[i][f]));
        }
        std::cout << std::endl;
    }
    return (0);
}