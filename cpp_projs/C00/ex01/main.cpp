#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    {
        PhoneBook a;
    }
    PhoneBook phonebook;
    Contact contact;
    std::string choice;
    int end = 0;
    while(end == 0)
    {
        std::cout << "ADD, SEARCH and EXIT: ";
        std::getline(std::cin, choice);
        if(std::cin.eof())
            return (1);
        if(choice == "ADD")
            contact.add_function(phonebook);
        else if(choice == "SEARCH")
            phonebook.search_func();
        else if(choice == "EXIT")
        {   
            std::cout << "Thanks for using PhoneBook\n";
            end = 1;
        }
        else
            std::cout << "Enter a valid value.\n";
    }
    return (0);
}
