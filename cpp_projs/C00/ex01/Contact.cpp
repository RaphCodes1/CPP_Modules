#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void Contact::text_output_init()
{
    text_output[0] = "First Name: ";
    text_output[1] = "Last Name: ";
    text_output[2] = "Nickname: ";
    text_output[3] = "Phone Number: ";
    text_output[4] = "Darkest secret: ";
}

int Contact::add_function(PhoneBook pb)
{   
    int i = 0;
    int all_true;
    text_output_init();
    // std::cin.ignore();
    while(i < 5)
    {   
        all_true = 1;
        std::cout << text_output[i];
        std::getline(std::cin, input[i]);
        if(std::cin.eof())
            return (0);
        if(input[i].empty())
        {
            std::cout << "enter valid value\n";
            all_true = 0;
        }
        if(i == 3)
        {
            if(!pb.number_check(input[i]))
            {
                std::cout << "enter valid number\n";
                all_true = 0;
            }
        }
        if(all_true == 1)
            i++;
    }
    if(!pb.add_contact(input))
        return (0);
    std::cout << "Info succesfully saved!\n";
    return (1);
}
