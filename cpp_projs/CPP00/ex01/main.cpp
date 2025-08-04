#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook phonebook;
    std::string choice;

    while(1)
    {
        if(std::cin.eof())
            return (0);
        std::cout << "ADD, SEARCH and EXIT: ";
        std::getline(std::cin, choice);
        if(std::cin.eof())
            return (0);
        else if(choice == "ADD")
            phonebook.addFunction();
        else if(choice == "SEARCH")
            phonebook.searchFunction();
        else if(choice == "EXIT")
        {   
            std::cout << "Thanks for using PhoneBook\n";
            return (0);
        }
        else
            std::cout << "Enter a valid value.\n";
    }
    return (0);
}
