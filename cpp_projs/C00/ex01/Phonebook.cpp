#include "Header.hpp"

int PhoneBook::counter = 0;

std::string PhoneBook::people[8][5] = {};

std::string PhoneBook::truncate(const std::string&  str)
{
    return (str.length() > 10) ? str.substr(0, 9) + "." : str;
}

PhoneBook::PhoneBook(std::string perName) {
    name = perName;
    std::cout << "Class " << name << " created\n";
}

PhoneBook::~PhoneBook(){}

int PhoneBook::add_contact(std::string info[])
{
    if(!valid_contact(info))
        return (0);
    if(counter == 7)
        counter = 0;
    for(int i = 0; i < 5; i++)
        people[counter][i] = info[i];
    counter += 1;
    return (1);
}
void print_header()
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|\n";
    std::cout << "---------------------------------------------\n";
}
int PhoneBook::search_func()
{
    int end = 0;
    std::string index;
    print_header();    
    for(int i = 0; i < counter; i++)
    {   
        std::cout << std::setw(10) << i << "|";
        for (size_t f = 0; f < 3; f++)
            std::cout<< std::setw(10) << truncate(people[i][f]) << "|";
        std::cout << "\n";
    }
    while (end == 0)
    {
        std::cout << "Enter Valid Index: ";
        std::cin >> index;
        if((index[0] >= '0' && index[0] <= '9') && index[1] == '\0')
        {   
            int i = index[0] - '0';
            if(!people[i]->empty())
            {
                std::cout << std::setw(10) << i << "|";
                for (size_t f = 0; f < 3; f++)
                    std::cout<< std::setw(10) << truncate(people[i][f]) << "|";
                std::cout << "\n";
                return (1);
            }
            else
                std::cout << "Enter a valid index.\n";
        }
        else
            std::cout << "Enter a valid index.\n";
    }
    return (1);
}
    
