#include "PhoneBook.hpp"

int PhoneBook::numCheck(std::string str)
{
    for(int f = 0; str[f] == ' '; f++);
    for(int f = 0; str[f] != '\0'; f++)
    {   
        if(!(str[f] >= '0' && str[f] <= '9'))
            return (0);
    }
    return (1);
}

int PhoneBook::strCheck(std::string str)
{
    for(size_t i = 0; i < str.length(); i++)
    {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ' '))
            continue;
        else
            return (0);
    }
    return (1);
}

int PhoneBook::spaceOnly(std::string str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ')
            return (1);
    }
    return (0);
}

void PhoneBook::textOutInit()
{
    text_output[0] = "First Name: ";
    text_output[1] = "Last Name: ";
    text_output[2] = "Nickname: ";
    text_output[3] = "Phone Number: ";
    text_output[4] = "Darkest secret: ";
}

void PhoneBook::printHeader()
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|\n";
    std::cout << "---------------------------------------------\n";
}

