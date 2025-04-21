#include "PhoneBook.hpp"

int PhoneBook::counter = 0;

std::string PhoneBook::people[8][5] = {};

PhoneBook::PhoneBook(){;}

PhoneBook::~PhoneBook(){;}

std::string PhoneBook::truncate(const std::string&  str)
{
    return (str.length() > 10) ? str.substr(0, 9) + "." : str;
}

void PhoneBook::print_info()
{
    text_output[0] = "First Name: ";
    text_output[1] = "Last Name: ";
    text_output[2] = "Nickname: ";
    text_output[3] = "Phone Number: ";
    text_output[4] = "Darkest secret: ";
}

int PhoneBook::add_contact(std::string info[])
{
    if(!valid_contact(info))
        return (0);
    if(counter == 8)
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
    std::string              index;
    print_info();
    if(people[0]->empty())
    {
        std::cout << "please enter input first.\n";
        return (0);
    }
    print_header();    
    for(int i = 0; i < 8; i++)
    {   
        if(!people[i]->empty())
        {
            std::cout << std::setw(10) << i << "|";
            for (size_t f = 0; f < 3; f++)
                std::cout<< std::setw(10) << truncate(people[i][f]) << "|";
            std::cout << "\n";
        }
    }
    while (end == 0)
    {   
        std::cout << "Enter Index or EXIT: ";
        std::getline(std::cin,index);
        if(std::cin.eof())
            return (0);
        if(index == "EXIT")
            return (1);
        if((index[0] >= '0' && index[0] <= '9') && index[1] == '\0')
        {   
            int i = index[0] - '0';
            if(!people[i]->empty())
            {   
                std::cout << "---------------------------------------------\n";
                for (size_t f = 0; f < 5; f++)
                    std::cout << text_output[f] << people[i][f] << "\n"; 
                std::cout << "---------------------------------------------\n";

                return (1);
            }
            else
                std::cout << "Enter a Valid Index.\n";
        }
        else
            std::cout << "Enter a Valid Index.\n";
    }
    return (1);
}
    
