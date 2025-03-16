#include "Header.hpp"

int number_check(std::string str)
{
    for(int f = 0; str[f] == ' '; f++);
    for(int f = 0; str[f] != '\0'; f++)
    {   
        if(!(str[f] >= '0' && str[f] <= '9'))
        {
            std::cout << "Invalid Number\n";
            return (0);
        }
    }
    return (1);
}

int char_check(std::string str)
{
    for(int f = 0;str[f] == ' ';f++);
    for(int f = 0; str[f] != '\0'; f++)
    {   
        if((str[f] >= 'a' && str[f] <= 'z')
            || (str[f] >= 'A' && str[f] <= 'Z')
            || str[f] == ' ')
            continue;
        else
        {
            std::cout << "Invalid values\n";
            return (0);
        }
    }
    return (1);
}

int valid_contact(std::string contact[])
{   
    for(int i = 0; i < 5; i++)
    {
        if(i == 3)
        {   
            if(!number_check(contact[i]))
                return (0);
        }
        else
        {
            if(!char_check(contact[i]))
                return (0);
        }
    }
    return (1);
}