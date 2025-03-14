#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int ac, char **av)
{   
    if(ac == 1)
        cout << "* LOUD AND UNBREARABLE FEEDBACK NOISE *\n";
    else
    {   
        for(int i = 1; i < ac; i++)
        {   
            for(int f = 0;f < av[i][f] != '\0'; f++)
                cout << static_cast<char>(toupper(av[i][f]));
        }
        cout <<endl;
    }
    return (0);
}