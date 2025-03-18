#include "PhoneBook.hpp"

int PhoneBook::number_check(std::string str)
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

int PhoneBook::valid_contact(std::string contact[])
{   
    for(int i = 0; i < 5; i++)
    {
        if(i == 3)
        {   
            if(!number_check(contact[i]))
                return (0);
        }
    }
    return (1);
}