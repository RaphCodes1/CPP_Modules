#include "PhoneBook.hpp"

int add_function(PhoneBook pb)
{
    std::string input[5];

    std::cout << "First Name: ";
    std::cin >> input[0];
    std::cout << "Last Name: ";
    std::cin >> input[1];
    std::cout << "Nickname: ";
    std::cin >> input[2];
    std::cout << "Phone Number: ";
    std::cin >> input[3];
    std::cin.ignore();
    std::cout << "Darkest Secret: ";
    getline(std::cin, input[4]);
    
    if(!pb.add_contact(input))
        return (0);
    std::cout << "Info succesfully saved!\n";
    return (1);
}

int main()
{
    PhoneBook acc1("Phonebook");
    std::string choice;
    int end = 0;
    while(end == 0)
    {
        std::cout << "ADD, SEARCH and EXIT: ";
        std::cin >> choice;
        
        if(choice == "ADD")
        {
            if(!add_function(acc1))
                return (1);
        }
        else if(choice == "SEARCH")
        {   
            if(!acc1.search_func())
                return(1);
        }
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
